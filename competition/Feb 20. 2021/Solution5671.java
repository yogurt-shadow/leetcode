import java.util.*;

class Solution5671 {
	int m, n;

    public int[][] highestPeak(int[][] isWater) {
    	m = isWater.length;
    	n = isWater[0].length;
        Map<Integer, Set<int[]>> map = new HashMap<>();
    	Set<int[]> set = new HashSet<>();
        map.put(0, set);
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(isWater[i][j] == 1){
    				set.add(new int[]{i, j});
    			}
    		}
    	}
    	int[][] result = new int[m][n];
    	int[] row = {0, 0, 1, -1};
    	int[] col = {-1, 1, 0, 0};
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			result[i][j] = -1;
    		}
    	}

    	for(int[] ele: set){
    		result[ele[0]][ele[1]] = 0;
		}
        int cur = 0;
        while(true){
            boolean full = true;
            map.put(cur + 1, new HashSet<>());
            for(int[] ele: map.get(cur)){
                for(int index = 0; index < 4; index++){
                    int xx = ele[0] + row[index];
                    int yy = ele[1] + col[index];
                    if(xx >= 0 && xx < m && yy >= 0 && yy < n && result[xx][yy] == -1){
                        full = false;
                        result[xx][yy] = cur + 1;
                        map.get(cur + 1).add(new int[]{xx, yy});
                    }
                }
            }
            cur++;
            if(full){
                break;
            }
        }
    	return result;
    }

    public static void main(String[] args){
    	Solution5671 s = new Solution5671();
    	int[][] test = {{0, 1}, {0, 1}};
    	int[][] result = s.highestPeak(test);
	}
}