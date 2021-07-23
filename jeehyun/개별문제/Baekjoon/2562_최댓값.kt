fun main() {
    val arr = Array<Int>(9) { readLine()!!.toInt() }
    var idx = -1
    var max = 0

    for (i in 0..8) {
        if (max < arr[i]) {
            max = arr[i]
            idx = i + 1
        }
    }
    println("$max\n$idx")
}