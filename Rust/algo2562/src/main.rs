use std::io;
fn main() {
    let mut input = String::new();
    let mut max = 0;
    let mut maxloop = 0;

    for i in 1..=9 {
        input.clear();
        io::stdin().read_line(&mut input).expect("input fail");
        let num: i32 = input.trim().parse().expect("parse fail");

        if max < num {
            max = num;
            maxloop = i;
        }
    }

    println!("{}", max);
    println!("{}", maxloop);
}
