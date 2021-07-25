fun main() {
    var result : Int = 1
    for (x in 1..3) {
        result *= readLine()!!.toInt()
    }

    val cnt = Array<Int>(10) { i -> 0 }
    while (result != 0) {
        cnt[result % 10]++
        result /= 10
    }

    cnt.forEach { println("$it") }
}