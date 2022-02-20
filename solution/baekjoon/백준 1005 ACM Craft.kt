import java.lang.Integer.max
import java.util.*

fun main(args: Array<String>) {

    val t = readLine()!!.toInt()

    repeat(t) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }

        val costs = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        costs.add(0, 0)
        val graph = Array(n + 1) { ArrayList<Int>() }
        val indegree = IntArray(n + 1) { _ -> 0 }

        repeat(m) {
            val (x, y) = readLine()!!.split(" ").map { it.toInt() }
            graph[x].add(y)
            indegree[y] += 1
        }

        val target = readLine()!!.toInt()

        // topological sort
        val pq = PriorityQueue<Int>()
        val totalCost = IntArray(n + 1) { costs[it] }
        for (i in 1 .. n) {
            if (indegree[i] == 0) {
                pq.add(i)
            }
        }

        while (pq.isNotEmpty()) {
            val cur = pq.poll()
            for (next in graph[cur]) {
                totalCost[next] = max(totalCost[next], totalCost[cur] + costs[next])
                indegree[next] -= 1
                if (indegree[next] == 0) {
                    pq.add(next)
                }
            }
        }

        println(totalCost[target])
    }
}