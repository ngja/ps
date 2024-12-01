class Solution {
    private val phoneNumberArray = arrayOf(
        emptyList(), // 0
        emptyList(), // 1
        listOf("a", "b", "c"), // 2
        listOf("d", "e", "f"), // 3
        listOf("g", "h", "i"), // 4
        listOf("j", "k", "l"), // 5
        listOf("m", "n", "o"), // 6
        listOf("p", "q", "r", "s"), // 7
        listOf("t", "u", "v"), // 8
        listOf("w", "x", "y", "z"), // 9
    )

    fun letterCombinations(digits: String): List<String> {
        var ans = mutableListOf<String>()
        for (digit in digits) {
            val digitToInt = digit.digitToInt()
            if (ans.isEmpty()) {
                ans.addAll(phoneNumberArray[digitToInt])
            } else {
                ans = ans.flatMap { a -> phoneNumberArray[digitToInt].map { "$a$it" } }.toMutableList()
            }
        }
        return ans.toList()
    }
}

fun main() {
    val solution = Solution()
    val ans1 = solution.letterCombinations("2222")
    println(ans1)
    val ans2 = solution.letterCombinations("6789")
    println(ans2)
}