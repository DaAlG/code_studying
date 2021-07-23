fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    var h = input[0]
    var m = input[1] - 45

    if (m < 0) {
        m += 60;
        if (--h < 0) {
            h += 24;
        }
    }
    println("$h $m")
}