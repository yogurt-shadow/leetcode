import java.util.Queue;
import java.util.LinkedList;

class Solution913 {
	private class State{
		private int i, j, k, value;
		public State(int i, int j, int k, int value){
			this.i = i;
			this.j = j;
			this.k = k;
			this.value = value;
		}
	}

    public int catMouseGame(int[][] graph) {
    	int length = graph.length;
    	Queue<State> queue = new LinkedList<>();
    	int[][][] state = new int[length][length][2];
    	for(int j = 1; j < length; j++){
    		state[0][j][0] = 1;
    		state[0][j][1] = 1;
    		queue.offer(new State(0, j, 0, 1));
    		queue.offer(new State(0, j, 1, 1));
    	}
    	for(int i = 1; i < length; i++){
    		state[i][i][0] = 2;
    		state[i][i][1] = 2;
    		queue.offer(new State(i, i, 0, 2));
    		queue.offer(new State(i, i, 1, 2));
    	}
    	while(!queue.isEmpty()){
    		State cur = queue.poll();
    		if(cur.k == 0){
    			if(cur.value == 1){
    				for(Integer cat_move: graph[cur.j]){
    					boolean mouse_win = true;
    					for(Integer cat_next: graph[cat_move]){
    						if(cat_next != 0 && state[cur.i][cat_next][0] != 1){
    							mouse_win = false;
    							break;
    						}
    					}
    					if(mouse_win && cat_move != 0 && state[cur.i][cat_move][1] == 0){
    						state[cur.i][cat_move][1] = 1;
    						queue.offer(new State(cur.i, cat_move, 1, 1));
    					}
    				}
    			}
    			else{
    				for(Integer cat_move: graph[cur.j]){
    					if(cat_move != 0 && state[cur.i][cat_move][1] == 0){
    						state[cur.i][cat_move][1] = 2;
    						queue.offer(new State(cur.i, cat_move, 1, 2));
    					}
    				}
    			}
    		}
    		else{
    			if(cur.value == 1){
    				for(Integer mouse_move: graph[cur.i]){
    					if(cur.j != 0 && state[mouse_move][cur.j][0] == 0){
    						state[mouse_move][cur.j][0] = 1;
    						queue.offer(new State(mouse_move, cur.j, 0, 1));
    					}
    				}
    			}
    			else{
    				for(Integer mouse_move: graph[cur.i]){
    					boolean cat_win = true;
    					for(Integer mouse_next: graph[mouse_move]){
    						if(cur.j != 0 && state[mouse_next][cur.j][1] != 2){
    							cat_win = false;
    							break;
    						}
    					}
    					if(cat_win && cur.j != 0 && state[mouse_move][cur.j][0] == 0){
    						state[mouse_move][cur.j][0] = 2;
    						queue.offer(new State(mouse_move, cur.j, 0, 2));
    					}
    				}
    			}
    		}
    	}
    	return state[1][2][0];
    }
}