fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }

    if (input[0] > input[1]) {
        println(">")
    } else if (input[0] < input[1]) {
        println("<")
    } else {
        println("==")
    }
}