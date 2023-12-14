import java.util.Arrays;

class Solution1552 {
    public int maxDistance(int[] position, int m) {
    	Arrays.sort(position);
    	int left = Integer.MAX_VALUE;
    	for(int i = 0; i + 1 < position.length; i++){
    		left = Math.min(left, position[i + 1] - position[i]);
    	}
    	int right = (position[position.length - 1] - position[0]) / (m - 1);
    	while(right - left > 1){
    		int mid = (left + right) / 2;
    		if(check(mid, position, m)){
    			left = mid;
    		}
    		else{
    			right = mid;
    		}
    	}
    	return check(right, position, m) ? right : left;
    }

    private boolean check(int value, int[] position, int m){
    	int count = 1;
    	int last = position[0];
    	for(int i = 1; i < position.length; i++){
    		if(position[i] - last >= value){
    			count += 1;
    			last = position[i];
    		}
    	}
    	return count >= m;
    }
}