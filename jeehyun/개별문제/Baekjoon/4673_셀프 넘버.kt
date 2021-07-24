fun main() {
    val selfNumber = Array<Boolean>(10001) { i -> true }

    for (n in 1..10000) {
        if (selfNumber[n]) {
            var result = d(n)
            while (result <= 10000) {
                selfNumber[result] = false
                result = d(result)
            }
            println(n)
        }
    }
}

fun d(n : Int) : Int {
    var sum = n
    var tmp = n
    while (tmp != 0) {
        sum += tmp % 10
        tmp /= 10
    }
    return sum
}