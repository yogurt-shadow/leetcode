import java.util.Map;
import java.util.HashMap;

class Solution765 {
    public int minSwapsCouples(int[] row) {
    	Map<Integer, Integer> index = new HashMap<>();
    	for(int i = 0; i < row.length; i++){
    		index.put(row[i], i);
    	}
    	int n = row.length;
    	int count = 0;
    	for(int i = 0; i < n - 1; i += 2){
    		int position1 = index.get(i);
    		int position2 = index.get(i + 1);
    		if(Math.abs(position1 - position2) == 1 && Math.min(position1, position2) % 2 == 0){
    			continue;
    		}
            count += 1;
    		if(position1 % 2 == 0){
                int temp = row[position1 + 1];
                row[position1 + 1] = i + 1;
                row[position2] = temp;
                index.put(i + 1, position1 + 1);
                index.put(temp, position2);
            }
            else{
                int temp = row[position1 - 1];
                row[position1 - 1] = i + 1;
                row[position2] = temp;
                index.put(i + 1, position1 - 1);
                index.put(temp, position2);
            }
    	}
        return count;
    }

    public static void main(String[] args){
        Solution765 s = new Solution765();
        int[] row = {0, 2, 1, 3};
        System.out.println(s.minSwapsCouples(row));
    }
}