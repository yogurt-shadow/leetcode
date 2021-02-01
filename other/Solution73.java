import java.util.Set;
import java.util.HashSet;

class Solution73 {
    public void setZeroes(int[][] matrix) {
    	Set<Integer> row = new HashSet<>();
    	Set<Integer> col = new HashSet<>();
    	for(int i = 0; i < matrix.length; i++){
    		for(int j = 0; j < matrix[0].length; j++){
    			if(matrix[i][j] == 0){
    				if(!row.contains(i)){
    					row.add(i);
    				}
    				if(!col.contains(j)){
    					col.add(j);
    				}
    			}
    		}
    	}
    	for(Integer x: row){
    		for(int j = 0; j < matrix[0].length; j++){
    			matrix[x][j] = 0;
    		}
    	}
    	for(Integer y: col){
    		for(int j = 0; j < matrix.length; j++){
    			matrix[j][y] = 0;
    		}
    	}
    }
}