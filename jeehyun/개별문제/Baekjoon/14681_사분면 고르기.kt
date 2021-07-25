import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val x = sc.nextInt()
    val y = sc.nextInt()

    if (x > 0 && y > 0) println(1)
    else if (x < 0 && y > 0) println(2)
    else if (x < 0 && y < 0) println(3)
    else println(4)
}