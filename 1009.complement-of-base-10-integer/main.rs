struct Solution;

impl Solution {
    pub fn bitwise_complement(n: i32) -> i32 {
        let mut ones = 1;
        while ones < n {
            ones = (ones << 1) + 1;
        }
        n ^ ones
    }
}

fn main() {
    println!("{}", Solution::bitwise_complement(5));
}
