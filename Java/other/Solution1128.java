import java.util.Arrays;
import java.util.Comparator;

class Solution1128 {
    public int numEquivDominoPairs(int[][] dominoes) {
    	for(int i = 0; i < dominoes.length; i++){
    		if(dominoes[i][0] > dominoes[i][1]){
    			int temp = dominoes[i][0];
    			dominoes[i][0] = dominoes[i][1];
    			dominoes[i][1] = temp;
    		}
    	}
    	Comparator<int[]> cmp = (x, y) -> x[0] != y[0] ? x[0] - y[0] : x[1] - y[1];
    	Arrays.sort(dominoes, cmp);
    	int count = 0;
    	for(int i = 0; i < dominoes.length; i++){
    		int j = i + 1;
    		while(j < dominoes.length && dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]){
    			j += 1;
    		}
    		count += (j - i) * (j - i - 1) / 2;
    		i = j - 1;
    	}
    	return count;
    }

    public static void main(String[] args){
    	Solution1128 s = new Solution1128();
    	int[][] dominoes = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
    	System.out.println(s.numEquivDominoPairs(dominoes));
    }
}