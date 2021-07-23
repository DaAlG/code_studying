import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val a = sc.nextInt()

    if (a >= 90) println("A")
    else if (a >= 80) println("B")
    else if (a >= 70) println("C")
    else if (a >= 60) println("D")
    else println("F")
}