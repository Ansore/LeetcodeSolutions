import java.lang.Math;
// 动态规划
class MaximalSquare {
	public int maximalSquare(char[][] matrix) {
		if(matrix == null || matrix.length == 0 || matrix[0].length == 0) {
			return 0;
		}
		int maxSide = 0;
		int rows = matrix.length;
		int columns = matrix[0].length;
		int dp[][] = new int[rows][columns];
		for(int i = 0; i < matrix.length; i ++) {
			for(int j = 0; j < matrix[i].length; j ++) {
				if(matrix[i][j] == '1') {
					if(i == 0 || j == 0) {
						dp[i][j] = 1;
					} else {
						dp[i][j] = Math.min(dp[i-1][j], Math.min(dp[i-1][j-1], dp[i][j-1])) + 1;
					}
					maxSide = Math.max(maxSide, dp[i][j]);
				}
			}
		}
		return maxSide * maxSide;
	}

	public static void main(String[] args) {

	}
}
