struct Solution;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let (mut cnt, mut res) = (0, nums[0]);
        for i in &nums {
            cnt += if res == *i { 1 } else { -1 };
            if cnt < 0 {
                res = *i;
                cnt = 0;
            }
        }
        res
    }
}

fn main() {
    // let nums = vec![3, 2, 3];
    let nums = vec![2, 2, 1, 1, 1, 2, 2];
    println!("{}", Solution::majority_element(nums.clone()));
}
