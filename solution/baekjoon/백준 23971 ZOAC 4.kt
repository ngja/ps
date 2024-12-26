
fun main() {
    val (h, w, n, m) = readln().split(" ").map { it.toInt() }
    val height = h / (1 + n) + if (h % (1 + n) > 0) 1 else 0
    val width = w / (1 + m) + if (w % (1 + m) > 0) 1 else 0
    val ans = height * width
    println(ans)
}