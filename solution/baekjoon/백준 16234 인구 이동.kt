import kotlin.math.abs

val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // → ↓ ← ↑

fun canNotMove(cur: Pair<Int, Int>, dir: Pair<Int, Int>, border: Pair<Int, Int>): Boolean {
   return (cur.first + dir.first) < 0 || (cur.second + dir.second) < 0
           || (cur.first + dir.first) >= border.first || (cur.second + dir.second) >= border.second
}

fun main(args: Array<String>) {

   val (n, l, r) = readLine()!!.split(" ").map { it.toInt() }
   val land = Array(n) { readLine()!!.split(" ").map { it.toInt() }.toTypedArray() }

   var day = 0
   while (true) {
      var count = 0

      val visited = Array(n) { Array(n) { false } }
      for (i in 0 until n) {
         for (j in 0 until n) {

            if (visited[i][j])
               continue

            val q = ArrayDeque<Pair<Int, Int>>()
            q.addLast(i to j)
            visited[i][j] = true

            var total = 0
            val positions = mutableListOf<Pair<Int, Int>>()

            while(q.isNotEmpty()) {
               val cur = q.removeFirst()
               total += land[cur.first][cur.second]
               positions.add(cur)

               for (dir in dirs) {
                  if (canNotMove(cur, dir, n to n))
                     continue

                  val next = cur.first + dir.first to cur.second + dir.second
                  if (visited[next.first][next.second])
                     continue

                  val diff = abs(land[cur.first][cur.second] - land[next.first][next.second])
                  if (diff !in l .. r)
                     continue

                  q.addLast(next)
                  visited[next.first][next.second] = true
               }
            }

            val population = total / positions.size
            for (position in positions) {
               land[position.first][position.second] = population
            }
            count++
         }
      }
      if (count == n * n)
         break
      day++
   }

   println(day)
}