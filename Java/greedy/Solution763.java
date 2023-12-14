import java.util.List;
import java.util.LinkedList;

class Solution763 {
    public List<Integer> partitionLabels(String S) {
    	List<Integer> result = new LinkedList<>();
    	int cover = findlast(S, S.charAt(0));
    	int length = 0;
    	for(int i = 0; i < S.length(); i++){
    		cover = Math.max(cover, findlast(S, S.charAt(i)));
    		length += 1;
    		if(i == cover){
    			result.add(length);
    			length = 0;
    		}
    	}
    	return result;
    }

    private int findlast(String S, char cur){
    	int result = -1;
    	for(int i = 0; i < S.length(); i++){
    		if(S.charAt(i) == cur){
    			result = i;
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution763 s = new Solution763();
    	String s1 = "ababcbacadefegdehijhklij";
    	List<Integer> result = s.partitionLabels(s1);
    	System.out.println(result);
    }
}