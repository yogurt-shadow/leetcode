import java.util.List;
import java.util.LinkedList;

class Solution119 {
	public List<Integer> getRow(int rowIndex) {
		List<Integer> res = new LinkedList<>();
		long cur = 1;
		for (int i = 0; i <= rowIndex; i++) {
			res.add((int) cur);
			cur = cur * (rowIndex-i)/(i+1);
		}
		return res;
	}

    public static void main(String[] args){
    	Solution119 s = new Solution119();
    	System.out.println(s.getRow(13));

    }
}