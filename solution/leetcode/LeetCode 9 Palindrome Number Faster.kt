class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) {
            return false
        }

        var original = x
        var reverse = 0
        while (original > 0) {
            reverse *= 10
            reverse += (original % 10)
            original /= 10
        }

        return x == reverse
    }
}

fun main(args: Array<String>) {

    val s = Solution()
    val palindrome = s.isPalindrome(0)
    println(palindrome)
}