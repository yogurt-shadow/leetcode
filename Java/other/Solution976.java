package other;
import java.util.Arrays;

public class Solution976 {
    public int largestPerimeter(int[] A) {
    	int[] b = new int[100];
    	System.arraycopy(A, 0, b, 0, A.length);
    	Arrays.sort(b);
    	int result = 0;
    	for(int i = b.length - 1; i - 2 >= b.length - A.length; i--){
    		if(b[i] < b[i - 1] + b[i - 2]){
    			if(b[i] + b[i - 1] + b[i - 2] > result){
    				result = b[i] + b[i - 1] + b[i - 2];
    			}
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution976 s = new Solution976();
    	int[] a = new int[]{2, 1 ,2};
    	System.out.println(s.largestPerimeter(a));
	}
}