import java.io.BufferedReader
import java.io.InputStreamReader

val reader=System.`in`.bufferedReader()

fun readLn()=reader.readLine()
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}

fun sol()
{
    val(n,h,b)=readInts()
    val s=List(2){readLn()}
    var ans=3L*b
    var res=-1
    for(i in 0 until n)
    {
        if(s[0][i]=='S' || s[1][i]=='S')
        {
            res=i
            break
        }
    }
    var Prefix=0L
    var Suffix=0L
    for(i in 0 until res)
    {
        if(s[0][i]=='W')Prefix++
        if(s[1][i]=='W')Prefix++
    }
    for(i in n-1 downTo res+1)
    {
        if(s[0][i]=='W')Suffix++
        if(s[1][i]=='W')Suffix++
    }
    ans=minOf(ans,(Prefix+Suffix)*h)
    ans=minOf(ans,Prefix*h+2L*b)
    ans=minOf(ans,Suffix*h+2L*b)
    println(ans)
}

fun main()
{
    repeat(readInt())
    {
        sol()
    }
}