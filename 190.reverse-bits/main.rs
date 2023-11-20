impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut res = (x & 0x55555555) << 1 | (x & 0xaaaaaaaa) >> 1;
        res = (res & 0x33333333) << 2 | (res & 0xcccccccc) >> 2;
        res = (res & 0x0f0f0f0f) << 4 | (res & 0xf0f0f0f0) >> 4;
        res = (res & 0x00ff00ff) << 8 | (res & 0xff00ff00) >> 8;
        res = (res & 0x0000ffff) << 16 | (res & 0xffff0000) >> 16;
        res
    }
}
