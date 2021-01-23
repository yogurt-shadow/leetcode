import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;

class Solution1319 {
    public int makeConnected(int n, int[][] connections) {
        UnionFind uf = new UnionFind(n);
        int over = 0;
        for(int[] ele: connections){
            if(uf.is_connected(ele[0], ele[1])){
                over += 1;
            }
            uf.connect(ele[0], ele[1]);
        }
        return over >= uf.size() - 1 ? uf.size() - 1 : -1;
        }

    public static void main(String[] args){
    	Solution1319 s = new Solution1319();
    	int[][] connections1 = new int[][]{new int[]{0, 1}, new int[]{0, 2}, new int[]{0, 3}, new int[]{1, 2}, new int[]{1, 3}};
    	System.out.println(s.makeConnected(6, connections1));
    }
}