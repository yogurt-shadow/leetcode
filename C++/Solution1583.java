class Solution1583 {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        int[][] rela = new int[n][n];
        for(int i = 0; i < preferences.length; i++){
            for(int j = 0; j < preferences[i].length; j++){
                rela[i][preferences[i][j]] = j;
            }
        }
        int[] part = new int[n];
        for(int[] pair: pairs){
            part[pair[0]] = pair[1];
            part[pair[1]] = pair[0];
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i || j == part[i]) continue;
                if(rela[i][j] < rela[i][part[i]] && rela[j][i] < rela[j][part[j]]){
                    cnt ++;
                    break;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args){
        System.out.println(12321);
    }
}