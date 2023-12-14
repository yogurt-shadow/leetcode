class Solution860 {
    public boolean lemonadeChange(int[] bills) {
    	int[] money = new int[2];
    	for(int ele: bills){
    		switch(ele){
    			case 5:
    			money[0] += 1;
    			break;

    			case 10:
    			if(money[0] == 0){
    				return false;
    			}
    			money[0] -= 1;
    			money[1] += 1;
    			break;

    			case 20:
    			if(money[0] == 0){
    				return false;
    			}
    			if(money[1] > 0){
    				money[1] -= 1;
    				money[0] -= 1;
    			}
    			else{
    				money[0] -= 3;
    				if(money[0] < 0){
    					return false;
    				}
    			}
    			break;

    			default:
    			break;
    		}
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution860 s = new Solution860();
    	int[] test1 = new int[]{5, 5, 5, 10, 20};
    	System.out.println(s.lemonadeChange(test1));
    }
}