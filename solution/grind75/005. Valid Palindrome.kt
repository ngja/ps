

class Solution {
    fun isPalindrome(s: String): Boolean {
        val removeNonAlphabet = removeNonAlphabet(s)
        return removeNonAlphabet == (removeNonAlphabet.reversed())
    }

    fun removeNonAlphabet(s: String): String {
        return s.filter { it.isLetterOrDigit() }.lowercase()
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val ans = solution.isPalindrome("a1234124124")
    println(ans)
}