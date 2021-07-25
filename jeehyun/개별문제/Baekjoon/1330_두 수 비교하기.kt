fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    println(compareNum(input[0], input[1]))
}

fun compareNum(a : Int, b : Int) = if (a > b) ">" else if (a < b) "<" else "=="