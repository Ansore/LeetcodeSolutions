
public class ImplementStrstr2 {

	private int[] getNext(String needle) {
		char[] n = needle.toCharArray();
		int[] next = new int[n.length];
		next[0] = -1;
		int j = 0;
		int k = -1;

		while(j < n.length - 1) {
			if(k == -1 || n[j] == n[k]) {
				next[++j] = ++k;
			} else {
				k = next[k];
			}
		}

		return next;
	}

	public int strStr(String haystack, String needle) {
		if(needle.isEmpty()) {
			return 0;
		}
		char[] h = haystack.toCharArray();
		char[] n = needle.toCharArray();
		int lenH = h.length;
		int lenN = n.length;

		if(lenN > lenH) {
			return -1;
		}

		int i = 0;
		int j = 0;

		int[] next = getNext(needle);

		while(i < lenH && j < lenN) {
			if(j == -1 || h[i] == n[j]) {
				i ++;
				j ++;
			} else {
				j = next[j];
			}
		}

		if(j == lenN) {
			return i - j;
		} else {
			return -1;
		}
	}

	public static void main(String[] args) {
		System.out.println(new ImplementStrstr2().strStr("hello", "ll"));
	}
	
}
