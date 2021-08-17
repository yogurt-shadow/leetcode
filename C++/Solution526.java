class Solution526 {
    int[] array;
    int ans = 0;

    public int countArrangement(int n) {
        array = new int[n + 1];
        dfs(n, 1);
        return ans;
    }

    private void dfs(int n, int index){
        if(index > n){
            ans ++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(array[i] == 1){
                continue;
            }
            if(i % index == 0 || index % i == 0){
                array[i] = 1;
                dfs(n, index + 1);
                array[i] = 0;
            }
        }
    }
}