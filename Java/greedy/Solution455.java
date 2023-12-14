import java.util.Arrays;

class Solution455 {
    public int findContentChildren(int[] g, int[] s) {
    	Arrays.sort(g);
    	Arrays.sort(s);
    	int result = 0;
    	int index2 = g.length - 1;
    	int index1 = s.length - 1;
    	while(index1 >= 0 && index2 >= 0){
    		if(s[index1] >= g[index2]){
    			result += 1;
    			index1 -= 1;
    			index2 -= 1;
    		}
    		else{
    			index2 -= 1;
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution455 s = new Solution455();
    	int[] s1 = new int[]{1, 1};
    	int[] g1 = new int[]{1, 2, 3};
    	System.out.println(s.findContentChildren(g1, s1));
    }
}