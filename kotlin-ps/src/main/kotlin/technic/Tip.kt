package technic


fun main() {
    // input
    val (n, l, r) = readln().split(" ").map { it.toInt() }
    val twoDimensionArray = Array(n) { readln().split(" ").map { it.toInt() }.toTypedArray() }

    // initialize
    val adj = Array(5) { mutableListOf<Int>() }

    // 방향
    val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // → ↓ ← ↑
}