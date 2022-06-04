// 暴力大法
class LargestRectangleInHistogram {
	public int largestRectangleArea(int[] heights) {
		int result = 0;
		for(int i = 0; i < heights.length; i ++) {
			int he = heights[i];
			int j = i - 1;
			int times = 1;
			while(j >= 0 && heights[j] >= he) {
				times ++;
				j --;
			}
			j = i + 1;
			while(j < heights.length && heights[j] >= he) {
				times ++;
				j ++;
			}
			int area = times * he;
			result = area>result? area : result;
		}
		return result;
	}

	public static void main(String[] args) {
		int[] a = new int[]{2, 2, 5, 6, 2, 3};
		System.out.println(new LargestRectangleInHistogram().largestRectangleArea(a));
	}
}
