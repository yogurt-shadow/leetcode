package  tree;


import java.util.List;
import java.util.LinkedList;
/**
*  G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
*/

public class Solution96 {
    public int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        else{
            int result = 0;
            for(int i = 0; i < n; i++){
                result += numTrees(i) * numTrees(n - 1 - i);
            }
            return result;
        }
       }

    public static void main(String[] args){
		Solution96 s = new Solution96();
		System.out.println(s.numTrees(3));

	}
}