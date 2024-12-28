fun main() {
    val n = readln().toInt()
    val size = readln().split(" ").map { it.toInt() }
    val (t, p) = readln().split(" ").map { it.toInt() }
    val tCount = size.sumOf { (it / t) + if (it % t == 0) 0 else 1 }
    val pCount = n / p
    val onePenCount = n % p
    println(tCount)
    println("$pCount $onePenCount")
}