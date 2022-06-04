import java.util.Set;
import java.util.HashSet;

class HappyNumber {

	public int getSumOfSquares(int n) {
		int divisor = n / 10;
		int remainder = n % 10;
		int sum = 0;
		while(remainder != 0 || divisor != 0) {
			sum += (remainder*remainder);
			remainder = divisor % 10;
			divisor = divisor / 10;
		}
		return sum;
	}
	public boolean isHappy(int n) {

		Set<Integer> numsSet = new HashSet<>();
		int sum = n;
		for(;;) {
			if(sum == 1) {
				return true;
			} else {
				numsSet.add(sum);
			}
			sum = getSumOfSquares(sum);
			if(numsSet.contains(sum)){
				return false;
			}
		}
	}
	public static void main(String[] args) {
		System.out.println(new HappyNumber().isHappy(12));
	}
}
