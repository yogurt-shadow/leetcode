class Solution1725 {
    public int countGoodRectangles(int[][] rectangles) {
    	int count = 0;
    	int max = 0;
    	for(int[] ele: rectangles){
    		if(Math.min(ele[0], ele[1]) > max){
    			max = Math.min(ele[0], ele[1]);
    			count = 1;
    		}
    		else if(Math.min(ele[0], ele[1]) == max){
    			count += 1;
    		}
    	}
    	return count;
    }

    public static void main(String[] args){
    	Solution1725 s = new Solution1725();
    	int[][] test = new int[][]{new int[]{5, 8}, new int[]{3, 9}, new int[]{5, 12}, new int[]{16, 5}};
    	System.out.println(s.countGoodRectangles(test));
    }
}