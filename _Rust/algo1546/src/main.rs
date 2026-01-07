use std::io;
fn main() {
    let mut input_num = String::new();

    io::stdin().read_line(&mut input_num).expect("msg");

    let num: usize = input_num.trim().parse().expect("dd");

    let mut scores_line = String::new();
    io::stdin()
        .read_line(&mut scores_line)
        .expect("failed input score");

    let scores: Vec<f64> = scores_line
        .trim()
        .split_whitespace()
        .map(|s| s.parse().expect("must be f64 num"))
        .collect();

    let max_score = scores.iter().fold(0.0f64, |max, &val| max.max(val));

    let original_sum: f64 = scores.iter().sum();

    let new_sum = (original_sum / max_score) * 100.0;

    let new_average = new_sum / (num as f64);

    println!("{}", new_average);
}
