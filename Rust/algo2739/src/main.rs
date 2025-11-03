use std::io;
fn main() {
    let mut n = String::new();

    io::stdin().read_line(&mut n).expect("input fail");

    let num: i32 = n.trim().parse().expect("tpye conv");

    let mut multi_counter = 1;

    loop {
        println!("{} * {} = {}", num, multi_counter, num * multi_counter);
        if multi_counter == 9 {
            break;
        }
        multi_counter += 1;
    }
}
