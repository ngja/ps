import kotlin.math.min

fun distance(x: String, y: String): Int {
    var result = 0
    for (i in 0 until 4) {
        if (x[i] != y[i]) {
            result++
        }
    }
    return result
}

fun main(args: Array<String>) {
    val t = readln().toInt()
    for (i in 0 until t) {
        val n = readln().toInt()
        val mbti = readln().split(" ").toTypedArray()
        if (n > 32) {
            println(0)
            continue
        }

        var ans = 16
        for (x in 0 until n) {
            for (y in x + 1 until  n) {
                for (z in y + 1 until n) {
                    val temp = distance(mbti[x], mbti[y]) + distance(mbti[x], mbti[z]) + distance(mbti[y], mbti[z])
                    ans = min(ans, temp)
                }
            }
        }
        println(ans)
    }
}