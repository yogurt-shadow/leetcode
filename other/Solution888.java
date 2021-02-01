import java.util.Arrays;

class Solution888 {
	public int[] fairCandySwap(int[] A, int[] B) {
		Arrays.sort(A);
		Arrays.sort(B);
		int sum1 = 0;
		for (int ele : A) {
			sum1 += ele;
		}
		int sum2 = 0;
		for (int ele : B) {
			sum2 += ele;
		}
		int index1 = 0;
		int index2 = 0;
		while (index1 < A.length && index2 < B.length) {
			int after1 = sum1 - A[index1] + B[index2];
			int after2 = sum2 - B[index2] + A[index1];
			if (after1 == after2) {
				return new int[]{A[index1], B[index2]};
    		}
				if (after1 < after2) {
					index2 += 1;
				}
				if (after1 > after2) {
					index1 += 1;
				}
			}
		return new int[]{-1, -1};
	}
}