import java.util.Scanner
import kotlin.math.min
import kotlin.math.max

fun sol(scanner: Scanner)
{
    val x=scanner.nextLong()
    val y=scanner.nextLong()
    println("${min(x, y)} ${max(x, y)}")
}

fun main()
{
    val scanner=Scanner(System.`in`)
    val t=scanner.nextInt()
    repeat(t)
    {
        sol(scanner)
    }
}