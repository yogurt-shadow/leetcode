import java.util.List;
import java.util.LinkedList;

class Solution989 {
    public List<Integer> addToArrayForm(int[] A, int K) {
    	LinkedList<Integer> result = new LinkedList<>();
    	String b = String.valueOf(K);
    	int index1 = A.length - 1;
    	int index2 = b.length() - 1;
    	int over = 0;
    	while(index1 >= 0 || index2 >= 0 || over != 0){
    		int sum;
    		if(index1 < 0 && index2 < 0){
    			sum = over;
			}
    		else if(index1 < 0){
    			sum = over + (b.charAt(index2) - '0');
			}
    		else if(index2 < 0){
    			sum = over + A[index1];
			}
    		else{
    			sum = over + A[index1] + (b.charAt(index2) - '0');
			}
    		int digit = sum < 10 ? sum : sum - 10;
    		over = sum < 10 ? 0 : 1;
    		result.addFirst(digit);
    		index1 -= 1;
    		index2 -= 1;
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution989 s = new Solution989();
    	int[] test1 = new int[]{9,9,9,9,9,9,9,9,9,9};
    	System.out.println(s.addToArrayForm(test1, 1));
    }
}