import java.util.*;

class Solution1710 {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
    	Comparator<int[]> cmp = (x, y) -> y[1] - x[1];
    	Arrays.sort(boxTypes, cmp);
    	int result = 0;
    	int index = 0;
    	while(index < boxTypes.length && truckSize >= boxTypes[index][0]){
    		result += boxTypes[index][0] * boxTypes[index][1];
    		truckSize -= boxTypes[index][0];
			index += 1;
    	}
    	if(index == boxTypes.length){
    		return result;
    	}
    	result += truckSize * boxTypes[index][1];
    	return result;
    }

    public static void main(String[] args){
    	Solution1710 s = new Solution1710();
    	int[][] test = {{1, 3}, {2, 2}, {3, 1}};
    	System.out.println(s.maximumUnits(test, 4));
    }
}