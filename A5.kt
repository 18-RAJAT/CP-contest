fun solve()
{
    val s=readLine()!!
    var pos=readLine()!!.toInt()-1
    val n=s.length;val q=mutableListOf<Int>();val order=mutableListOf<Int>();var j=0
    val used=BooleanArray(n)
    for(i in 0 until n)
    {
        while(q.isNotEmpty() && s[i]<s[q.last()])
        {
            order.add(q.removeAt(q.size-1))
        }
        q.add(i)
    }
    while(q.isNotEmpty())
    {
        order.add(q.removeAt(q.size-1))
    }
    for(i in n downTo 1)
    {
        if(pos<i)
        {
            break
        }
        else
        {
            pos-=i;j++
        }
    }
    for(i in 0 until j) used[order[i]]=true
    val str=StringBuilder()
    for(i in 0 until n)
    {
        if(!used[i])str.append(s[i])
    }
    println(str[pos])
}
fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        solve()
    }
}