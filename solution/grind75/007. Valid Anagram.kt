class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        val sAlphabetCounter = IntArray(26)
        val tAlphabetCounter = IntArray(26)

        for (c in s) {
            sAlphabetCounter[c - 'a']++
        }
        for (c in t) {
            tAlphabetCounter[c - 'a']++
        }

        for (i in 0 until 26) {
            if (sAlphabetCounter[i] != tAlphabetCounter[i]) {
                return false
            }
        }
        return true
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val s = "z"
    val t = "z"
    val ans = solution.isAnagram(s, t)
    println(ans)
}