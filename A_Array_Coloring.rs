use std::io::stdin;

fn take_int() -> usize {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}

fn take_vector() -> Vec<usize> {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect()
}

fn solve() {
    let n = take_int();
    let arr = take_vector();

    let odd = arr.iter().filter(|&&x| x % 2 == 1).count();

    if odd % 2 == 1 {
        println!("NO");
    } else {
        println!("YES");
    }
}

fn main() {
    let t = take_int();
    for _ in 0..t {
        solve();
    }
}