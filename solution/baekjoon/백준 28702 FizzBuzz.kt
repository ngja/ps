class Solution {
    fun next(a: String, b: String, c: String): String {
        return if (a.toIntOrNull() != null) {
            fizzBuzz(a.toInt() + 3)
        } else if (b.toIntOrNull() != null) {
            fizzBuzz(b.toInt() + 2)
        } else {
            fizzBuzz(c.toInt() + 1)
        }
    }

    private fun fizzBuzz(a: Int): String {
        if (a % 15 == 0) {
            return "FizzBuzz"
        } else if (a % 5 == 0) {
            return "Buzz"
        } else if (a % 3 == 0) {
            return "Fizz"
        }
        return a.toString()
    }
}

fun main() {
    val a = readln()
    val b = readln()
    val c = readln()
    val solution = Solution()
    println(solution.next(a, b, c))
}