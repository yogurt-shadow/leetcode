class Solution4 {
    public int minimumBoxes(int n) {
    	int level = findlevel(n);
        int start = sum(level);
        int[] number = new int[level];
        int cur = start;
        while(cur < n){
            number[0] += 1;
            for(int i = 0; i < level - 1; i++){
                number[i + 1] = Math.max(number[i] - 1, 0);
            }
            int sum = 0;
            for(int ele: number){
                sum += ele;
            }
            cur = start + sum;
        }
        return number[0] + (level + 1) * level / 2;
    }

    private int findlevel(int x){
        int level = 1;
        while(x >= sum(level)){
            level += 1;
        }
        return level - 1;
    }

    private int sum(int level){
        if(level == 1){
            return 1;
        }
        return sum(level - 1) + (level + 1) * level / 2;
    }

    public static void main(String[] args){
        Solution4 s = new Solution4();
        System.out.println(s.minimumBoxes(126));
    }
}