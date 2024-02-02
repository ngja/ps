import java.util.PriorityQueue

fun main(args: Array<String>) {

    val n = readln().toInt()
    val ho = mutableListOf<Pair<Long, Long>>();
    for (i in 0 until n) {
        val (h, o) = readln().split(" ").map { it.toLong() }
        if (h < o) {
            ho.add(h to o)
        } else {
            ho.add(o to h)
        }
    }
    val d = readln().toLong()

    ho.sortWith(compareBy<Pair<Long, Long>> { it.second }.thenBy { it.first })

    var max = 0
    val pq = PriorityQueue<Long>()
    for (now in ho) {
        val right = now.second
        val left = right - d

        pq.offer(now.first)
        while (pq.isNotEmpty() && left > pq.peek()) {
            pq.poll()
        }
        if (max < pq.size) {
            max = pq.size
        }
    }
    println(max)
}