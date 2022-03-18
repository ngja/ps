class Solution {
    fun longestPalindrome(s: String): String {
        val palindrome = Array(s.length) { Array(s.length) { false } }

        palindrome[0][0] = true
        for (i in 1 until s.length) {
            palindrome[i][i] = true
            palindrome[i-1][i] = s[i] == s[i-1]
        }

        var ansLeft = 0
        var ansRight = 0
        for (interval in 2 until s.length) {
            for (left in 0 until s.length - interval) {
                palindrome[left][left+interval] = (s[left] == s[left+interval]) && palindrome[left+1][left+interval-1]
            }
        }

        for (interval in 1 until s.length) {
            for (left in 0 until s.length - interval) {
                if (palindrome[left][left+interval]) {
                    ansLeft = left
                    ansRight = left+interval
                }
            }
        }

        return s.substring(ansLeft .. ansRight)
    }
}

fun main(args: Array<String>) {

    val s = Solution()
    val longestPalindrome = s.longestPalindrome("cbbd")
    println(longestPalindrome)
}