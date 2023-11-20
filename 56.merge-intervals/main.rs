impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut sorted_intervals = intervals;
        sorted_intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut merged_intervals: Vec<Vec<i32>> = Vec::new();
        for interval in sorted_intervals {
            if merged_intervals.is_empty() || merged_intervals.last().unwrap()[1] < interval[0] {
                merged_intervals.push(interval)
            } else {
                merged_intervals.last_mut().unwrap()[1] = merged_intervals.last().unwrap()[1].max(interval[1]);
            }
        }
        merged_intervals
    }
}
