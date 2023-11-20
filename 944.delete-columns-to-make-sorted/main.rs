struct Solution;

impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let mut res: i32 = 0;
        if strs.len() <= 0 {
            return res;
        }
        for i in 0..strs[0].len() {
            for j in 1..strs.len() {
                if strs[j-1].get(i..=i) > strs[j].get(i..=i) {
                    res += 1;
                    break;
                }
            }
        }
        res
    }
}

fn main() {
    // let strs: Vec<String> = vec![String::from("cba"),String::from("daf"),String::from("ghi")];
    let strs: Vec<String> = vec!["cba".to_string(),"daf".to_string(),"ghi".to_string()];
    println!("{}", Solution::min_deletion_size(strs));
}
