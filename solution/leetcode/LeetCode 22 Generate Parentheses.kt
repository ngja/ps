class Solution {
    fun generateParenthesis(n: Int): List<String> {
        val ans = mutableListOf<String>()
        backtrack(n, "(", ans)
        return ans
    }

    private fun backtrack(pairsOfParenthesis: Int, parenthesis: String, ans: MutableList<String>) {
        if (isComplete(pairsOfParenthesis, parenthesis)) {
            ans.add(parenthesis)
            return
        }

        if (isCorrect(pairsOfParenthesis, parenthesis, "(")) {
            backtrack(pairsOfParenthesis, "$parenthesis(", ans)
        }

        if (isCorrect(pairsOfParenthesis, parenthesis, ")")) {
            backtrack(pairsOfParenthesis, "$parenthesis)", ans)
        }
    }

    private fun isCorrect(pairsOfParenthesis: Int, parenthesis: String, next: String): Boolean {
        if (next == "(") {
            var openCount = 1
            for (c in parenthesis) {
                if (c == '(') {
                    openCount += 1
                }
            }
            return openCount <= pairsOfParenthesis
        } else {
            var closeCount = 1
            val stack = mutableListOf<String>()
            for (c in parenthesis) {
                if (c == '(') {
                    stack.add(next)
                } else if (c == ')') {
                    closeCount += 1
                    stack.removeLast()
                }
            }
            return (stack.isNotEmpty() && closeCount <= pairsOfParenthesis)
        }
    }

    private fun isComplete(pairsOfParenthesis: Int, parenthesis: String): Boolean {
        var openCount = 0
        var closeCount = 0
        val stack = mutableListOf<Char>()
        for (c in parenthesis) {
            if (c == '(') {
                openCount += 1
                stack.add(c)
            } else if (c == ')') {
                closeCount += 1
                if (stack.isEmpty()) {
                    return false
                }
                stack.removeLast()
            }
        }
        val complete = stack.isEmpty() && openCount == pairsOfParenthesis && closeCount == pairsOfParenthesis
        return complete
    }
}

fun main() {
    val solution = Solution()
    println(solution.generateParenthesis(1))
    println(solution.generateParenthesis(2))
    println(solution.generateParenthesis(3))
    println(solution.generateParenthesis(4))

}