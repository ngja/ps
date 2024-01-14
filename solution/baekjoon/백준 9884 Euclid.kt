fun gcd(a: Int, b: Int): Int {
    if (b == 0) return a
    return gcd(b, a % b)
}

fun main(args: Array<String>) {
    val (a, b) = readln().split(" ").map { it.toInt() }
    println(gcd(a, b))
}