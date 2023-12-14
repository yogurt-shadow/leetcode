import java.util.Arrays;
import java.util.Comparator;

class Solution318 {
    public int maxProduct(String[] words) {
    	Comparator<String> cmp = new Comparator<>(){
    		@Override
    		public int compare(String str1, String str2){
    			return str2.length() - str1.length();
    		}
    	};
    	Arrays.sort(words, cmp);
    	int length = 0;
    	for(int i = 0; i < words.length; i++){
       loop:  for(int j = i + 1; j < words.length; j++){
                for(int k = 0; k < words[i].length(); k++){
                    if(words[j].indexOf(words[i].charAt(k)) >= 0){
                        continue loop;
                    }
                }
                 length = Math.max(words[i].length() * words[j].length(), length);
            }
        }
        return length;
    }

    public static void main(String[] args){
        Solution318 s = new Solution318();
        String[] test = {"a","ab","abc","d","cd","bcd","abcd"};
        System.out.println(s.maxProduct(test));
    }
}