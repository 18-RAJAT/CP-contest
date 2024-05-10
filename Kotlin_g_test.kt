import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import java.util.*

fun main() 
{
    val read=BufferedReader(InputStreamReader(System.`in`))
    val writes=BufferedWriter(OutputStreamWriter(System.out))
    val t=read.readLine().toInt()

    repeat(t)
    {
        val n=read.readLine().toLong()
        val s=TreeSet<Long>()
        s.add(-1)

        val token=StringTokenizer(read.readLine())

        for(i in 0 until n)
        {
            val R=token.nextToken().toLong()
            if(i-1 in s) s.add(i+R)
            if(i-R-1 in s) s.add(i)
        }

        writes.write(if(n-1 in s) "YES\n" else "NO\n")
    }
    writes.flush()
    writes.close()
}