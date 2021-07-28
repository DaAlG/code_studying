fun main() = with(System.`in`.bufferedReader()) {
    var arr = IntArray(readLine()!!.toInt()) { readLine()!!.toInt() }.distinct().sorted()
    arr.forEach { println("$it") }
}