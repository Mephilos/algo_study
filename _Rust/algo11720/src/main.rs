use std::io;
fn main() {
    let mut input = String::new();
    let mut input2 = String::new();

    io::stdin().read_line(&mut input).expect("input1 eerr");
    io::stdin().read_line(&mut input2).expect("input2 eerr");

    let sum: u32 = input2.trim().chars().map(|c| c.to_digit(10).unwrap()).sum();

    println!("{}", sum);
}
