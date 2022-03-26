class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) {
            return false
        }

        val string = x.toString()
        var lo = 0
        var hi = string.length - 1

        while (lo < hi) {
            if (string[lo] != string[hi]) {
                return false
            }
            lo++
            hi--
        }

        return true
    }
}

fun main(args: Array<String>) {

    val s = Solution()
    val palindrome = s.isPalindrome(0)
    println(palindrome)
}