import java.util.Arrays;

class Solution2 {
    public int minCharacters(String a, String b) {
    	return Math.min(equal(a, b), Math.min(small(a, b), small(b, a)));
    }

    private int equal(String str1, String str2){
    	int[] freq = new int[26];
    	for(char ele: str1.toCharArray()){
    		freq[ele - 'a'] += 1;
       	}
       	for(char ele: str2.toCharArray()){
    		freq[ele - 'a'] += 1;
       	}
       	int max = -1;
       	for(int i = 0; i < 26; i++){
       		max = Math.max(max, freq[i]);
       	}
       	return str1.length() + str2.length() - max;
    }
/**
abe
ace
*/
    private int small(String a, String b){
      int min = Integer.MAX_VALUE;
    	for(char cur = 'a'; cur < 'z'; cur++){
          int number = 0;
          for(int i = 0; i < a.length(); i++){
            if(a.charAt(i) > cur){
              number += 1;
            }
          }
          for(int j = 0; j < b.length(); j++){
            if(b.charAt(j) <= cur){
              number += 1;
            }
          }
          min = Math.min(min, number);
      }
      return min;
    }

    public static void main(String[] args){
      Solution2 s = new Solution2();
     /** System.out.println(s.minCharacters("aba", "caa"));*/
       System.out.println(s.small("abe", "ace"));
    }
}