import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    while (true) {
        val result = sum(sc.nextInt(), sc.nextInt())
        if (result == 0)
            break
        println(result)
    }
}

fun sum(a : Int, b : Int) = a + b
