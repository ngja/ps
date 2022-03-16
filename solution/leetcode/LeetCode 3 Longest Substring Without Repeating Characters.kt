data class Cache(val index: Int, var before: Char?)

class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        val cacheMap = mutableMapOf<Char, Cache>()

        if (s.isEmpty()) {
            return 0
        }

        var ans = 1
        cacheMap[s[0]] = Cache(0, null)

        for (i in 1 until s.length) {

            val cur = s[i]
            if (cacheMap[cur] == null) {
                cacheMap[cur] = Cache(i, s[i-1])
            } else {
                var temp = cur
                var target = cacheMap[temp]
                val lastNullUpdateIndex = target!!.index + 1
                while (true) {
                    if (target!!.before == null) {
                        cacheMap.remove(temp)
                        cacheMap[cur] = Cache(i, s[i-1])
                        break
                    } else {
                        val tempTemp = target.before!!
                        target = cacheMap[tempTemp]
                        cacheMap.remove(temp)
                        temp = tempTemp
                    }
                }
                cacheMap[s[lastNullUpdateIndex]]!!.before = null
            }

            if (ans < cacheMap.size) {
                ans = cacheMap.size
            }
        }

        return ans
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val result = solution.lengthOfLongestSubstring("a")
    println(result)

}