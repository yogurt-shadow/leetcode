public class UnionFind{
	private int n;
	private int count;
	private int[] parent;
	private int[] size;

	public UnionFind(int n){
		this.n = n;
		parent = new int[n];
		size = new int[n];
		count = 0;
		for(int i = 0; i < n; i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	public int count(){
		return count;
	}

	private int findparent(int x){
		if(parent[x] == x){
			return x;
		}
		return findparent(parent[x]);
	}

	public void connect(int x, int y){
		if(is_connected(x, y)){
			return;
		}
		int parent1 = findparent(x);
		int parent2 = findparent(y);
		if(size[x] >= size[y]){
			parent[parent2] = parent1;
			size[parent1] += size[parent2];
		}
		else{
			parent[parent1] = parent2;
			size[parent2] += size[parent1];
		}
		count += 1;
	}

	public boolean is_connected(int x, int y){
		return findparent(x) == findparent(y);
	}
}