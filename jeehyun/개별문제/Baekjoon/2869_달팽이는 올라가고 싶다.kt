fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val cnt = Math.ceil((input[2] - input[1]).toDouble() / (input[0] - input[1])).toInt()

    println("$cnt")
}