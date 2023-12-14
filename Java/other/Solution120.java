import java.util.List;
import java.util.LinkedList;

class Solution120 {
    public int minimumTotal(List<List<Integer>> triangle) {
    	int size = triangle.size();
    	int[] num = new int[size];
    	for(int i = 0; i < size; i++){
    		num[i] = triangle.get(size - 1).get(i);
    	}
    	for(int i = size - 2; i >= 0; i--){
    		for(int j = 0; j <= i; j++){
    			num[j] = Math.min(num[j], num[j + 1]) + triangle.get(i).get(j);
    		}
    	}
    	return num[0];
    }
}