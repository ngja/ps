class Solution {
    val startParentheses = setOf('(', '{', '[')

    private fun isStart(char: Char): Boolean {
        return startParentheses.contains(char)
    }

    private fun isFinish(char: Char): Boolean {
        return !isStart(char)
    }

    private fun isMatch(start: Char, finish: Char): Boolean {
        return (start == '(' && finish == ')') || (start == '{' && finish == '}') || (start == '[' && finish == ']')
    }

    private fun isNotMatch(start: Char, finish: Char): Boolean {
        return !isMatch(start, finish)
    }

    fun isValid(s: String): Boolean {
        val stack = ArrayDeque<Char>()

        for (c in s) {
            if (stack.isEmpty()) {
                if (isFinish(c)) {
                    return false
                }
                stack.addLast(c)
            } else {
                if (isStart(c)) {
                    stack.addLast(c)
                } else {
                    val last = stack.removeLast()
                    if (isNotMatch(last, c)) {
                        return false
                    }
                }
            }
        }
        return stack.isEmpty()
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val input = "(())"
    val valid = solution.isValid(input)
    println(valid)
}