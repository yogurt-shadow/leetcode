import java.util.Arrays;
import java.util.Comparator;

class Solution1005 {
    public int largestSumAfterKNegations(int[] A, int K) {
    	Comparator<Integer> cmp = (x, y) -> Math.abs(y) - Math.abs(x);
    	Integer[] A_copy = new Integer[A.length];
    	for(int i = 0; i < A.length; i++){
    		A_copy[i] = A[i];
    	}
    	Arrays.sort(A_copy, cmp);
        int index = 0;
    	while(K > 0 && index < A.length){
            if(A_copy[index] < 0){
                A_copy[index] = -A_copy[index];
                K -= 1;
            }
            index += 1;
        }
        int sum = 0;
        for(Integer ele: A_copy){
            sum += ele;
        }
        return K % 2 == 0 ? sum : sum - 2 * A_copy[A.length - 1];
    }

    public static void main(String[] args){
    	Solution1005 s = new Solution1005();
    	int[] test = new int[]{2,-3,-1,5,-4};
    	System.out.println(s.largestSumAfterKNegations(test, 2));
    }
}