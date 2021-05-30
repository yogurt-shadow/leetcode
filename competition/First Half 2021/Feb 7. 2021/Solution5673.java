import java.util.*;

class Solution5673 {
    public int maximumScore(int a, int b, int c) {
    	int[] stone = new int[]{a, b, c};
    	Arrays.sort(stone);
    	int result = 0;
    	while(stone[1] != 0){
    	stone[1] -= 1;
    	stone[2] -= 1;
    	result += 1;
    	Arrays.sort(stone);
    }
    return result;
    }

    public static void main(String[] args){
    	Solution5673 s = new Solution5673();
    	System.out.println(s.maximumScore( 2 , 4, 6));
    }
}