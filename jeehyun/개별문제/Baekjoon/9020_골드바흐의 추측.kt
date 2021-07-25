fun main() {
    val T = readLine()!!.toInt();
    val op = arrayListOf<Int>()
    val prime = BooleanArray(10001) { it % 2 == 1 }
    prime[1] = false

    for (i in 3..5000 step 2) {
        if (prime[i]) {
            op += i
            for (j in i * 3..10000 step i * 2) {
                prime[j] = false
            }
        }
    }

    for (t in 1..T) {
        val n = readLine()!!.toInt()
        var answer = 2
        for (p in op) {
            if (p > n / 2)
                break
            if (prime[n - p])
                answer = p
        }
        println("$answer ${n - answer}")
    }
}