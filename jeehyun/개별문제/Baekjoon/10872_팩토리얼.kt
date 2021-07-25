fun main() = println(fact(readLine()!!.toInt()))
fun fact(n : Int) : Int = if (n < 2) 1 else n * fact(n - 1)