use std::io;

fn main()
{
    let mut input=String::new();
    io::stdin().read_line(&mut input).expect("Error");
    let n:i32=input.trim().parse().expect("Read");

    for _ in 0..n
    {
        let mut input=String::new();
        io::stdin().read_line(&mut input).expect("Error");
        let x: i32=input.trim().parse().expect("Read");
        let mut sum=0;
        let mut ok=false;
        for _ in 0..
        {
            if(x-sum)%3==0 || (x-sum)%7==0
            {
                println!("YES");
                ok=true;
                break;
            }
            if sum>=x
            {
                break;
            }
            sum+=3;
        }
        if !ok
        {
            println!("NO");
        }
    }
}