struct Solution;

impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        let mut cur: usize = 0;
        // let mut t_c: usize = 0;
        let mut res = arr1.clone();
        let mut tmp: i32;
        for i in 0..arr2.len() {
            // t_c = cur;
            for j in cur..arr1.len() {
                if res[j] == arr2[i] {
                    if j != cur {
                        // swap
                        tmp = res[cur];
                        res[cur] = res[j];
                        res[j] = tmp;
                    }
                    cur += 1;
                }
            }
        }
        for i in cur..res.len() {
            for j in i..res.len() {
                if res[i] > res[j] {
                    tmp = res[i];
                    res[i] = res[j];
                    res[j] = tmp;
                }
            }
        }
        res
    }
}

fn main() {
    // let arr1 = vec![2,3,1,3,2,4,6,7,9,2,19];
    // let arr2 = vec![2,1,4,3,9,6];
    let arr1 = vec![28,6,22,8,44,17];
    let arr2 = vec![22,28,8,6];
    println!("{:?}", Solution::relative_sort_array(arr1, arr2));
}
