fun main() {
    var num = readLine()!!.split(" ").map { it.reversed().toInt() }
    println(isGreater(num[0], num[1]))
}

fun isGreater(a : Int, b : Int) = if (a > b) a else b