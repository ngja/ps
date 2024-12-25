class Solution {
    private val answer = mutableListOf<String>()
    private var pairsOfParenthesis = 0

    fun generateParenthesis(n: Int): List<String> {
        answer.clear()
        pairsOfParenthesis = n
        backtrack("(", 1, 0)
        return answer
    }

    private fun backtrack(parenthesis: String, openCount: Int, closeCount: Int) {
        if (parenthesis.length == pairsOfParenthesis * 2) {
            answer.add(parenthesis)
            return
        }

        if (openCount < pairsOfParenthesis) {
            backtrack("$parenthesis(", openCount + 1, closeCount)
        }

        if (closeCount < openCount) {
            backtrack("$parenthesis)", openCount, closeCount + 1)
        }
    }
}

fun main() {

    val solution = Solution()
    println(solution.generateParenthesis(1))
    println(solution.generateParenthesis(2))
    println(solution.generateParenthesis(3))
    println(solution.generateParenthesis(4))
}