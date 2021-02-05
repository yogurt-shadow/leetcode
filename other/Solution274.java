import java.util.Arrays;

class Solution274 {
    public int hIndex(int[] citations) {
    	if(citations.length == 0){
            return 0;
        }
    	int length = citations.length;
    	Arrays.sort(citations);
    	int max = Math.min(length, citations[0]);
    	for(int i = 0; i < length; i++){
    		int cur = Math.min(length - i, citations[i]);
    		max = Math.max(max, cur);
    	}
    	return max;
    }
}