import java.util.*;

class Solution378 {

    public int kthSmallest(int[][] matrix, int k) {
        int rows = matrix.length, columns = matrix[0].length;
        int[] sorted = new int[rows * columns];
        int index = 0;
        for (int[] row : matrix) {
            for (int num : row) {
                sorted[index++] = num;
            }
        }
        Arrays.sort(sorted);
        return sorted[k - 1];
    }


    public static void main(String[] args){		
		Solution378 s = new Solution378();
    	int[][] matrix = new int[][]{new int[]{1, 4, 7, 11, 15}, new int[]{2, 5, 8, 12, 19},
				new int[]{3, 6, 9, 16, 22}, new int[]{10, 13, 14, 17, 24}, new int[]{18, 21, 23, 26, 30}};
    	System.out.println(s.kthSmallest(matrix, 20));
    }

}