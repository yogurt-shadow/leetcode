class Solution74 {
    public boolean searchMatrix(int[][] matrix, int target) {
    	int[] line = new int[matrix.length * matrix[0].length];
    	int index = 0;
    	for(int i = 0; i < matrix.length; i++){
    		for(int j = 0; j < matrix[0].length; j++){
    			line[index] = matrix[i][j];
    			index += 1;
    		}
    	}
    	return search(line, target);
    }

    private boolean search(int[] line, int target){
    	if(target < line[0] && target > line[line.length - 1]){
    		return false;
    	}
    	int left = 0;
    	int right = line.length - 1;
    	if(line.length <= 2){
    		for(int ele: line){
    			if(ele == target){
    				return true;
    			}
    		}
    		return false;
    	}
    	
    	while(left != right && left != right - 1){
    		if(target == line[left] || target == line[right]){
    			return true;
    		}
    		int half = (left + right) / 2;
    		if(target == line[half]){
    			return true;
    		}
    		if(target > line[half]){
    			left = half;
    		}
    		else{
    			right = half;
    		}
    	}
    	return false;
    }
}