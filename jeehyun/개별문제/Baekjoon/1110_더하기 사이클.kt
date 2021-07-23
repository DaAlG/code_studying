fun main() {
    val n = readLine()!!.toInt()
    var cnt : Int = 0
    var num : Int = n

    while (true) {
        cnt++

        var sum = 0
        var tmp = num
        while (tmp != 0) {
            sum += tmp % 10
            tmp /= 10
        }
        num = num % 10 * 10 + sum % 10

        if (num == n)
            break;
    }
    println(cnt)
}