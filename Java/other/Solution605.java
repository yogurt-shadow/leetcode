class Solution605 {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
    	if(n == 0){
    		return true;
    	}
    		for(int index = 0; index < flowerbed.length; index++){
    			if(flowerbed[index] == 0 && (index - 1 < 0 || flowerbed[index - 1] == 0) && (index + 1 >= flowerbed.length || flowerbed[index + 1] == 0)){
    				flowerbed[index] = 1;
    				n -= 1;
    				if(n <= 0){
    					return true;
    				}
    		}
    	}
    	return false;
    }
}
    	