import java.util.*

class Solution {
    fun isValid(s: String): Boolean {
        val stack = Stack<Char>()

        for (c in s) {
            if (stack.isEmpty()) {
                if (c == ')' || c == '}' || c == ']') {
                    return false
                }
                stack.push(c)
            } else {
                val top = stack.pop()
                if (top == '(') {
                    if (c == ')') {
                        continue
                    } else if (c == '}' || c == ']') {
                        return false
                    } else {
                        stack.push(top)
                        stack.push(c)
                    }
                } else if (top == '[') {
                    if (c == ']') {
                        continue
                    } else if (c == ')' || c == '}') {
                        return false
                    } else {
                        stack.push(top)
                        stack.push(c)
                    }
                } else if (top == '{') {
                    if (c == '}') {
                        continue
                    } else if (c == ')' || c == ']') {
                        return false
                    } else {
                        stack.push(top)
                        stack.push(c)
                    }
                }
            }
        }

        return stack.isEmpty()
    }
}

fun main() {
    val solution = Solution()
    println(solution.isValid("("))
    println(solution.isValid(")"))
    println(solution.isValid("()"))
    println(solution.isValid("()[]{}"))
    println(solution.isValid("(}"))
    println(solution.isValid(")()("))
    println(solution.isValid("[({})]"))
    println(solution.isValid("[({)}]"))
}