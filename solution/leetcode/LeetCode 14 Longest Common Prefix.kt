class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {

        var ans = ""
        val standard = strs.first()

        for (i in standard.indices) {

            val now = standard[i]
            var end = false
            for (idx in 1 until strs.size) {
                if (i >= strs[idx].length) {
                    end = true
                    break
                }

                if (strs[idx][i] != now) {
                    end = true
                    break
                }
            }

            if (end) {
                break
            }

            ans += now
        }

        return ans
    }
}

fun main(args: Array<String>) {
    val s = Solution()
    val ans = s.longestCommonPrefix(listOf("flower", "afelow", "floight").toTypedArray())
    println(ans)
}