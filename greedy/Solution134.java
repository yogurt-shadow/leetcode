class Solution134 {
    public int canCompleteCircuit(int[] gas, int[] cost) {
    	for(int i = 0; i < gas.length; i++){
    		if(gas[i] >= cost[i]){
    			if(round(gas, cost, i)){
    				return i;
    			}
    		}
    	}
    	return -1;
    }

    private boolean round(int[] gas, int[] cost, int start){
    	int gass = 0;
    	for(int i = start; i < start + gas.length; i++){
    		gass += gas[i % gas.length] - cost[i % gas.length];
    		if(gass < 0){
    			return false;
    		}
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution134 s = new Solution134();
    	int[] gas1 = new int[]{1,2,3,4,5};
    	int[] cost1 = new int[]{3,4,5,1,2};

    	System.out.println(s.canCompleteCircuit(gas1, cost1));
    }
}