class Solution {
    fun triangle(a: Int, b: Int, c: Int): String {
        if (a == b && b == c) {
            return "Equilateral"
        }

        if (
            a + b <= c
            || a + c <= b
            || b + c <= a
        ) {
            return "Invalid"
        }

        if (a == b || b == c || a == c) {
            return "Isosceles"
        }

        return "Scalene"
    }
}

fun main() {
    val solution = Solution()
    while (true) {
        val (a, b, c) = readln().split(" ").map { it.toInt() }
        if (a == 0 && b == 0 && c == 0) {
            break
        }
        val ans = solution.triangle(a, b, c)
        println(ans)
    }
}