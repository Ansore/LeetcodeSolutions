struct Solution;

impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut res: i32 = 0;
        for i in 0..32 {
            if (n>>i) & 0x1 == 1 {
                res += 1
            }
        }
        res
    }
}

fn main() {
    println!("{}", Solution::hammingWeight(0b11111111111111111111111111111101));
}
