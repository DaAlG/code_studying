import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val a = sc.nextInt()
    var b = sc.nextInt()

    var mult = 1
    var total = 0

    for (x in 1..3) {
        var res = a * (b % 10)
        println(res)
        total += res * mult
        b /= 10;
        mult *= 10
    }
    println(total)
}
