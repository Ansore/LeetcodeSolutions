struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n < 3 {
            return n;
        }
        let n = n as usize;
        let mut dp: Vec<i32> = vec![0; n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for i in 3..=n {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}

fn main() {
    println!("{}", Solution::climb_stairs(3));
}
