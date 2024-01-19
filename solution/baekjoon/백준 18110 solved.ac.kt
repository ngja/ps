import kotlin.math.roundToInt

// 사사오입, 오사오입 개념이 중요한 문제
// kotlin.math.round 는 사사오입으로 동작
// kotlin.math.roundToInt 는 오사오입으로 동작
// kotlin.math.rountToLong 은 오사오입으로 동작
fun main(args: Array<String>) {
    val n = readln().toInt()
    if (n ==  0) {
        println(0)
        return
    }
    val opinion = IntArray(n)
    for (i in 0 until n) {
        opinion[i] = readln().toInt()
    }
    val exception = (n * 0.15).roundToInt()
    opinion.sort()
    val sliceOpinion = opinion.sliceArray(exception until (n - exception))
    val avg = sliceOpinion.average().roundToInt()
    println(avg)
}