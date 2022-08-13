package technic


fun main() {
    // input
    val (n, l, r) = readLine()!!.split(" ").map { it.toInt() }
    val twoDimensionArray = Array(n) { readLine()!!.split(" ").map { it.toInt() }.toTypedArray() }

    // initialize
    val adj = Array(5) { mutableListOf<Int>() }

    // 방향
    val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // → ↓ ← ↑
}