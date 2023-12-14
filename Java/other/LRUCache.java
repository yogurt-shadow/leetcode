import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.LinkedList;

class LRUCache {
	private Map<Integer, Integer> map;
	private Queue<Integer> queue;
	private int capacity;
	private int size;

    public LRUCache(int capacity) {
    	map = new HashMap<>();
    	queue = new LinkedList<>();
    	this.capacity = capacity;
    	size = 0;
    }
    
    public int get(int key) {
    	if(!map.containsKey(key)){
    		return -1;
    	}
    	queue.remove(key);
    	queue.add(key);
    	return map.get(key);
    }
    
    public void put(int key, int value) {
    	if(map.containsKey(key)){
    		map.put(key, value);
    		queue.remove(key);
    		queue.add(key);
    	}
    	else{
    		queue.add(key);
    		map.put(key, value);
    		size += 1;
    		if(size > capacity){
    			size -= 1;
    			map.remove(queue.poll());
    		}
    	}
    }

    public static void main(String[] args){
    	LRUCache lRUCache = new LRUCache(2);
		lRUCache.put(1, 1); // 缓存是 {1=1}
		lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
		System.out.println(lRUCache.get(1));    // 返回 1
		lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
		System.out.println(lRUCache.get(2));    // 返回 -1 (未找到)
		lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
		System.out.println(lRUCache.get(1));    // 返回 -1 (未找到)
		System.out.println(lRUCache.get(3));    // 返回 3
		System.out.println(lRUCache.get(4));    // 返回 4
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */