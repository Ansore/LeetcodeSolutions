struct Solution;

impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let len = heights.len();
        let mut h_c = heights.clone();
        let mut r: i32 = 0;
        for i in 0..len {
            for j in i..len {
                if h_c[j] < h_c[i] {
                    let t = h_c[i];
                    h_c[i] = h_c[j];
                    h_c[j] = t;
                }
            }
        }
        for i in 0..len {
            if h_c[i] != heights[i] {
                r += 1;
            }
        }
        r
    }
}

fn main() {
    let heights = vec![1, 1, 4, 2, 1, 3];
    println!("{}", Solution::height_checker(heights));
}
