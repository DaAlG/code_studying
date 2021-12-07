fun main() = with(System.`in`.bufferedReader()) {
    val (n, m, k) = readLine().split(" ").map { it.toInt() }
    val nutrients = Array(n) { readLine().split(" ").map { it.toInt() }.toIntArray() }
    val map = Array(n) { IntArray(n) { 5 } }

    val dx = arrayOf(-1, -1, 1, 1, -1, 1, 0, 0)
    val dy = arrayOf(-1, 1, -1, 1, 0, 0, -1, 1)

    val trees = Array(n) { Array(n) { ArrayDeque<Int>() } }

    for (i in 0 until m) {
        val (x, y, z) = readLine().split(" ").map { it.toInt() }
        trees[x - 1][y - 1].apply {
            add(z)
            sort()
        }
    }

    var answer = 0
    for (i in 0 until k) {
        // 봄, 여름
        for (x in trees.indices) {
            for (y in trees[x].indices) {
                val size = trees[x][y].size
                var dead = 0

                for (s in 0 until size) {
                    val z = trees[x][y].removeFirst()
                    if (map[x][y] >= z) {
                        map[x][y] -= z
                        trees[x][y].addLast(z + 1)
                    } else {
                        dead += z / 2
                    }
                }
                map[x][y] += dead
            }
        }

        // 가을
        for (x in trees.indices) {
            for (y in trees[x].indices) {
                trees[x][y].forEach { z ->
                    if (z % 5 == 0) {
                        for (s in dx.indices) {
                            val nx = x + dx[s]
                            val ny = y + dy[s]
                            if (nx in 0 until n && ny in 0 until n) {
                                trees[nx][ny].addFirst(1)
                            }
                        }
                    }
                }
            }
        }

        // 겨울
        answer = 0
        for (x in 0 until n) {
            for (y in 0 until n) {
                map[x][y] += nutrients[x][y]
                answer += trees[x][y].size
            }
        }
    }
    print(answer)
}