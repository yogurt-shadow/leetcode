import java.util.List;
import java.util.LinkedList;

class Solution54 {
    public List<Integer> spiralOrder(int[][] matrix) {
    	List<Integer> list = new LinkedList<>();
    	if(matrix.length == 0){
    		return list;
    	}
    	if(matrix.length == 1){
    		for(int ele: matrix[0]){
    			list.add(ele);
    		}
    		return list;
    	}
    	if(matrix[0].length == 1){
    		for(int i = 0; i < matrix.length; i++){
    			list.add(matrix[i][0]);
    		}
    		return list;
    	}

    	for(int ele: matrix[0]){
    		list.add(ele);
    	}
    	int[][] other = rotate(matrix);
        List<Integer> list2 = spiralOrder(other);
        list.addAll(list2);
    	return list;
    }

    private int[][] rotate(int[][] matrix){
    	int[][] result = new int[matrix[0].length][matrix.length - 1];
    	int row = -1;
    	int col = 0;
		for(int j = matrix[0].length - 1; j >= 0; j--){
			row += 1;
			col = 0;
	    	for(int i = 1; i < matrix.length; i++){
    			result[row][col] = matrix[i][j];
    			col += 1;
    		}
    	}
		return result;
    }

    public static void main(String[] args){
    	Solution54 s = new Solution54();
    	int[][] matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    	int[][] other = s.rotate(matrix);
    }
}