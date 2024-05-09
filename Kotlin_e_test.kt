fun main()
{
    repeat(readln().toInt())
    {
        solve()
    }
}

fun solve()
{
    var (n, k)=readln().split(" ").map(String::toInt)
    val s=readln()

    val upper=IntArray('z' - 'a' + 1)
    val lower=IntArray('z' - 'a' + 1)

    for(ch in s)
    {
        if(ch in 'a'..'z')
        {
            lower[ch-'a']++
        }
        if(ch in 'A'..'Z')
        {
            upper[ch-'A']++
        }
    }
    var res=0
    for(i in upper.indices)
    {
        val cur=minOf(upper[i],lower[i])
        res+=cur
        upper[i]-=cur
        lower[i]-=cur

        val maxi=maxOf(upper[i],lower[i])/2
        val ans=minOf(maxi,k)
        res+=ans
        k-=ans
    }
    println(res)
}
