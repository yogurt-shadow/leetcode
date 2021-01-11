class Solution204 {
    public int countPrimes(int n) {
        if(n < 2){
            return 0;
        }
        int[] index = new int[n];
        index[0] = 1;
        index[1] = 1;
        for(int i = 2; i < n - 1; i++){
            if(index[i] == 1){
                continue;
            }
            if(is_prime(i)){
                index[i] = 0;
                for(int j = 2; j * i < n; j++){
                    index[i * j] = 1;
                }
            }
        }

        int count = 0;
        for(int ele: index){
            if(ele == 0){
                count += 1;
            }
        }
        return count;
    }

    private boolean is_prime(int x){
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
}