import java.util.Arrays;

class UnionFind {
    int[] parent;
    int[] size;
    int n;
    // 当前连通分量数目
    int setCount;

    public UnionFind(int n) {
        this.n = n;
        this.setCount = n;
        this.parent = new int[n];
        this.size = new int[n];
        Arrays.fill(size, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    public int size(){
    	return setCount;
    }
    
    public int findparent(int x) {
        if(parent[x] == x){
        	return x;
        }
        parent[x] = findparent(parent[x]);
        return parent[x];
    }
    
    public boolean connect(int x, int y) {
        x = findparent(x);
        y = findparent(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    public int size(int x){
    	return size[findparent(x)];
	}
    
    public boolean is_connected(int x, int y) {
        y = findparent(y);
		x = findparent(x);
		return x == y;
    }
}
