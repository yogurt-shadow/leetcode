import java.util.List;
import java.util.LinkedList;

class Solution131 {
    public List<List<String>> partition(String s) {
    	List<List<String>> result = new LinkedList<>();
    	List<String> list = new LinkedList<>();
    	put(result, list, s, 0);
    	return result;
}	

	private void put(List<List<String>> result, List<String> list, String s, int total){
		for(int i = 1; total + i <= s.length(); i++){
			String str = s.substring(total, total + i);
			if(!isPalindrome(str)){
				continue;
			}
			list.add(str);
			if(total + i == s.length()){
				List<String> copy = new LinkedList<>(list);
				result.add(copy);
				list.remove(list.size() - 1);
				return;
			}
			put(result, list, s, total + i);
			list.remove(list.size() - 1);
		}
	}

	private boolean isPalindrome(String s){
		int left = 0;
		int right = s.length() - 1;
		while(right > left){
			char left_cur = s.charAt(left);
			char right_cur = s.charAt(right);
			if(left_cur != right_cur){
				return false;
			}
			left += 1;
			right -= 1;
		}
		return true;
	}

	public static void main(String[] args){
		Solution131 s = new Solution131();
		List<List<String>> result = s.partition("aab");
	}
}