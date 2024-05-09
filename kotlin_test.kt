fun main()
{
    val t=readln().toInt()
    for(j in 1..t)
    {
        val n=readln()
        val list=readln().split(" ").map { it.toInt() }
        var init=list.first()
        if(list.first()!=list[1])
        {
            if(list[2]==init)
            {
                println(1+1)
                continue
            }
            else
            {
                println(0+1)
                continue
            }
        }
        for(i in 2..list.lastIndex)
        {
            if(list[i]!=init)
            {
                println(i+1)
                break
            }
        }
    }
}