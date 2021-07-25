fun main() {
    val score = readLine()!!.toInt()
    println(getGrade(score))
}

fun getGrade(score : Int) : String {
    if (score >= 90) return "A"
    else if (score >= 80) return "B"
    else if (score >= 70) return "C"
    else if (score >= 60) return "D"
    else return "F"
}