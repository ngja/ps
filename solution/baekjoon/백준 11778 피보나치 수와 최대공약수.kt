val identity = arrayOf(longArrayOf(1, 0), longArrayOf(0, 1))
val base = arrayOf(longArrayOf(1, 1), longArrayOf(1, 0))

fun multiply(a: Array<LongArray>, b: Array<LongArray>): Array<LongArray> {
    val c = Array(2) { LongArray(2) }
    for (i in 0..1) {
        for (j in 0..1) {
            c[i][j] = 0
            for (k in 0..1) {
                c[i][j] += a[i][k] * b[k][j]
                c[i][j] %= 1_000_000_007L
            }
        }
    }
    return c
}

fun power(mat: Array<LongArray>, n: Long): Array<LongArray> {

    if (n == 0L)
        return identity

    if (n % 2L == 1L)
        return multiply(power(mat, n - 1), mat)

    val half = power(mat, n / 2)

    return multiply(half, half)
}

fun fibonacci(n: Long): Long {
    if (n == 0L)
        return 0
    if (n == 1L)
        return 1

    val result = power(base, n - 1)
    return result[0][0]
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b);

fun main(args: Array<String>) {
    val (n, m) = readln().split(" ").map { it.toLong() }
    val gcd = gcd(n, m)
    val ans = fibonacci(gcd)
    println(ans)
}