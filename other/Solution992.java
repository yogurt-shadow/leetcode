import java.util.Map;
import java.util.HashMap;

class Solution992 {
    public int subarraysWithKDistinct(int[] A, int K) {
    	Window w1 = new Window();
    	Window w2 = new Window();
    	int left1 = 0, left2 = 0;
    	int result = 0;
    	for(int right = 0; right < A.length; right++){
    		w1.add(A[right]);
    		w2.add(A[right]);
    		while(w1.get_different() > K){
    			w1.remove(A[left1]);
    			left1 += 1;
    		}
    		while(w2.get_different() >= K){
    			w2.remove(A[left2]);
    			left2 += 1;
    		}
    		result += left2 - left1;
    	}
    	return result;
    }

    private class Window{
    	private int different;
    	private Map<Integer, Integer> map;
    	public Window(){
    		different = 0;
    		map = new HashMap<>();
    	}

    	private void add(int ele){
    		if(!map.containsKey(ele) || map.get(ele) == 0){
    			map.put(ele, 1);
    			different += 1;
    		}
    		else{
    			map.put(ele, map.get(ele) + 1);
    		}
    	}

    	private void remove(int ele){
    		map.put(ele, map.get(ele) - 1);
    		if(map.get(ele) == 0){
    			different -= 1;
    		}
    	}

    	public int get_different(){
    		return different;
    	}
    }
}