fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine()!!.toInt()
    val coord = readLine()!!.split(" ").map { it.toInt() }

    val sortNum = coord.distinct().sorted()
    val map : MutableMap<Int, Int> = HashMap()

    for (i in 0 until sortNum.size) {
        map[sortNum[i]] = i
    }

    val sb = StringBuilder()
    coord.forEach { sb.append("${map[it]} ")}
    println(sb.toString())
}