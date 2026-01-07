use std::io;
fn main() {
    let mut ab_input = String::new();

    io::stdin().read_line(&mut ab_input).expect("Input Err");

    let mut sw = ab_input.trim().split_whitespace();

    let a: i32 = sw.next().unwrap().parse().unwrap();
    let b: i32 = sw.next().unwrap().parse().unwrap();

    if a > b {
        println!(">")
    } else if a < b {
        println!("<")
    } else {
        println!("=")
    }
}
