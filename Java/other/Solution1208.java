class Solution1208 {
    public int equalSubstring(String s, String t, int maxCost) {
    	int[] cost = new int[s.length()];
    	for(int i = 0; i < s.length(); i++){
    		cost[i] = Math.abs(s.charAt(i) - t.charAt(i));
    	}
    	int max_length = 0;
    	int cur_cost = 0;
    	int left = 0;
    	int right = 0;
    	for(; right < s.length(); right++){
    		cur_cost += cost[right];
    		if(cur_cost > maxCost){
    			cur_cost -= cost[left];
    			left += 1;
    		}
    		max_length = Math.max(max_length, right - left + 1);
    	}
    	return max_length;
    }
}