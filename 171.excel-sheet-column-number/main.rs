struct Solution;

impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        let mut res: i32 = 0;
        let mut i: i32 = 0;
        let m: i32 = 26;
        let len: i32 = column_title.len() as i32;
        for c in column_title.chars() {
            // a = c.to_digit(10).expect("this is not a number");
            res += (c as i32 - 64)
                * if len - i - 1 != 0 {
                    m.pow((len - i - 1) as u32)
                } else {
                    1
                };
            i += 1;
        }
        res
    }
}

fn main() {
    println!("{}", Solution::title_to_number(String::from("AAA")));
    // println!("{}", Solution::title_to_number(String::from("ZY")));
    println!("{}", Solution::title_to_number(String::from("XSHRXW")));
}
