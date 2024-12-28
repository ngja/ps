class Solution {
    fun plus(n1: Int, n2: Int, n3: Int): Int {
        return n1 + n2 - n3
    }

    fun plus(s1: String, s2: String, s3: String): String {
        return ((s1 + s2).toInt() - (s3).toInt()).toString()
    }
}

fun main() {
    val a = readln()
    val b = readln()
    val c = readln()
    val solution = Solution()
    println(solution.plus(a.toInt(), b.toInt(), c.toInt()))
    println(solution.plus(a, b, c))
}