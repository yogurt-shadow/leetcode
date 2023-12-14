class Solution240 {
    public boolean searchMatrix(int[][] matrix, int target) {
    	int m = matrix.length;
    	int n = matrix[0].length;
      	int[] position = new int[]{m - 1, 0};
      	while(position[0] >= 0 && position[0] < m && position[1] >= 0 && position[1] < n){
      		if(target == matrix[position[0]][position[1]]){
      			return true;
      		}
      		if(target > matrix[position[0]][position[1]]){
      			position[1] += 1;
      		}
      		else{
      			position[0] -= 1;
      		}
      	}
      	return false;  
    }
}