import java.util.Arrays;
import java.util.Comparator;

class Solution179 {
    public String largestNumber(int[] nums) {
    	StringBuilder str = new StringBuilder();
    	Comparator<String> cmp = new Comparator<>(){
    		@Override
    		public int compare(String s1, String s2){
    			if(contains(s1, s2) || contains(s2, s1)){
    				return 0;
    			}
    			int i = 0;
    			while(s1.charAt(i % s1.length()) == s2.charAt(i % s2.length())){
    				i += 1;
    			}
    			return s1.charAt(i % s1.length()) > s2.charAt(i % s2.length()) ? -1 : 1;
    		}
    	};
    	String[] convert = new String[nums.length];
        for(int i = 0; i < nums.length; i++){
            convert[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(convert, cmp);
    	for(String ele: convert){
    		str.append(ele);
    	}
    	return str.charAt(0) == '0' ? "0" : str.toString();
    }

    private boolean contains(String s1, String s2){
    	if(s1.length() < s2.length()){
    		return false;
    	}
    	if(s1.equals(s2)){
    		return true;
    	}
        String str = s1.substring(0, s2.length());
    	if(!str.equals(s2)){
    		return false;
    	}
    	String str2 = s1.substring(s2.length(), s1.length());
    	return contains(str2, s2) || contains(s2, str2);
	}

    public static void main(String[] args){
        Solution179 s = new Solution179();
        int[] nums = {3, 30, 34, 5, 9};
        System.out.println(s.largestNumber(nums));
    }
}