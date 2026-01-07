use std::collections::HashSet;
use std::io;
fn main() {
    let mut remain: HashSet<i32> = HashSet::new();

    for _ in 0..10 {
        let mut input = String::new();

        io::stdin().read_line(&mut input).expect("readline fail");

        let num: i32 = input.trim().parse().expect("String num");

        remain.insert(num % 42);
    }

    println!("{}", remain.len());
}
