import java.util.Arrays;

class Solution3 {
    public int kthLargestValue(int[][] matrix, int k) {
    	int[][] value = new int[matrix.length][matrix[0].length];
    	for(int i = 0; i < matrix.length; i++){
    		for(int j = 0; j < matrix[0].length; j++){
    			if(i == 0 && j == 0){
    				value[i][j] = matrix[i][j];
    			}
    			else if(i == 0){
    				value[i][j] = value[i][j - 1] ^ matrix[i][j];
    			}
    			else if(j == 0){
    				value[i][j] = value[i - 1][j] ^ matrix[i][j];
    			}
    			else{
    				value[i][j] = value[i - 1][j] ^ value[i][j - 1] ^ matrix[i][j] ^ value[i - 1][j - 1];
    				
    			}
    		}
    	}
    	int[] array = new int[value.length * value[0].length];
    	int index = 0;
    	for(int i = 0; i < value.length; i++){
    		for(int j = 0; j < value[0].length; j++){
    			array[index] = value[i][j];
    			index += 1;
    		}
    	}
    	Arrays.sort(array);
    	return array[array.length - k];
    }

    public static void main(String[] args){
    	Solution3 s = new Solution3();
    	int[][] matrix = new int[][]{new int[]{5, 2}, new int[]{1, 6}};
    	System.out.println(s.kthLargestValue(matrix, 3));
    }
}