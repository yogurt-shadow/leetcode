import java.util.*;

class Solution5682 {
    public int beautySum(String s) {
    	int res = 0;
        char[] array = s.toCharArray();
        for(int i = 0; i < s.length(); i++){
            int[] freq = new int[26];
            for(int j = i; j < s.length(); j++){
                char cur = array[j];
                freq[cur - 'a']++;
                int max = -1, min = Integer.MAX_VALUE;
                for(int ele: freq){
                    if(ele > 0){
                        max = Math.max(max, ele);
                        min = Math.min(min, ele);
                    }
                }
                res += max - min;
            }
        }
        return res;
    }

    public static void main(String[] args){
    	Solution5682 s = new Solution5682();
    	String str = "aabcb";
    	System.out.println(s.beautySum(str));
	}
}