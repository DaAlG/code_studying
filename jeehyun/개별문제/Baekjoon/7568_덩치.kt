fun main() = with(System.`in`.bufferedReader()) {
    val arr = List(readLine()!!.toInt()) { readLine()!!.split(" ").map { it.toInt() } }
    for (i in arr) {
        print("${ arr.count{ i[0] < it[0] && i[1] < it[1]} + 1} ")
    }
}