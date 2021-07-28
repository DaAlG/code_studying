import java.util.*

var n = 0
var m = 0
val visited = BooleanArray(8, {false})

fun dfs(arr : MutableList<Int>, now : Int) {
    if (arr.size >= m) {
        arr.forEach { print("$it ") }
        println()
        return
    }

    for (i in 1..n) {
        if (visited[i]) continue
        visited[i] = true
        arr.add(i)
        dfs(arr, now + 1)
        arr.remove(i)
        visited[i] = false
    }
}

fun main() {
    val st = StringTokenizer(readLine(), " ")
    n = st.nextToken().toInt()
    m = st.nextToken().toInt()
    dfs(mutableListOf(), 1)
}

