use std::io;
fn main() {
    let mut c_scale = String::new();

    io::stdin().read_line(&mut c_scale).expect("숫자 입력");

    let cam: Vec<i32> = c_scale
        .trim()
        .split_whitespace()
        .map(|s| s.parse().expect("숫자 넣기"))
        .collect();

    let ascending: Vec<i32> = (1..=8).collect();
    let descending: Vec<i32> = (1..=8).rev().collect();

    if cam == ascending {
        println!("ascending");
    } else if cam == descending {
        println!("descending");
    } else {
        println!("mixed");
    }
}
