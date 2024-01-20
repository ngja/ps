fun main(args: Array<String>) {
    val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // 우 하 좌 상

    val (n, m) = readln().split(" ").map { it.toInt() }

    val map = Array(n) { readln().split(" ").map { it.toInt() }.toIntArray() }
    val visited = Array(n) { BooleanArray(m) { false } }
    val dist = Array(n) { IntArray(m) { -1 } }
    dist.forEachIndexed { rowIndex, row ->
        row.forEachIndexed { colIndex, _ ->
            if (map[rowIndex][colIndex] == 0) dist[rowIndex][colIndex] = 0
        }
    }

    // 시작 위치 찾기
    var startPos = 0 to 0
    run loop@{
        map.forEachIndexed { rowIndex, row ->
            row.forEachIndexed { colIndex, _ ->
                if (map[rowIndex][colIndex] == 2) {
                    startPos = rowIndex to colIndex
                    return@loop
                }
            }
        }
    }

    // 시작 위치에서 bfs pair(위치, 거리)
    val q = ArrayDeque<Pair<Pair<Int, Int>, Int>>()
    q.addLast(startPos to 0)

    while (q.isNotEmpty()) {
        val now = q.removeFirst()
        val nowPos = now.first
        val nowDist = now.second
        visited[nowPos.first][nowPos.second] = true
        dist[nowPos.first][nowPos.second] = nowDist

        for (dir in dirs) {
            val nextPos = nowPos.first + dir.first to nowPos.second + dir.second

            if (nextPos.first < 0 || nextPos.first >= n || nextPos.second < 0 || nextPos.second >= m) {
                continue
            }

            if (map[nextPos.first][nextPos.second] == 0) {
                continue
            }

            if (visited[nextPos.first][nextPos.second]) {
                continue
            }

            visited[nextPos.first][nextPos.second] = true
            q.addLast(nextPos to nowDist + 1)
        }
    }

    // 출력
    dist.forEach { println(it.joinToString(" ")) }
}