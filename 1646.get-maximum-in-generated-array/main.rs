impl Solution {
    pub fn get_maximum_generated(n: i32) -> i32 {
        if n <= 1 {
            return n;
        }
        let mut v = vec![0; n as usize + 1];
        v[0] = 0;
        v[1] = 1;

        for i in 2..v.len() {
            if i & 1 == 0 {
                v[i] = v[i/2];
            } else {
                v[i] = v[i/2] + v[i/2+1];
            }
        }
        *v.iter().max().unwrap()
    }
}
