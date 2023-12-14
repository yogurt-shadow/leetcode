class Solution275 {
    public int hIndex(int[] citations) {
    	int max = 0;
    	int length = citations.length;
    	for(int i = 0; i < length; i++){
    		int cur = Math.min(length - i, citations[i]);
    		max = Math.max(max, cur);
    	}
    	return max;
    }
}