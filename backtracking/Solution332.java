import java.util.List;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Map;
import java.util.HashMap;

class Solution332 {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> result = new LinkedList<>();
        Set<Integer> set = new HashSet<>();
        result.add("JFK");
        put(result, set, tickets, "JFK");
        return result;
    }

    private boolean put(List<String> result, Set<Integer> set, List<List<String>> tickets, String start){
        Map<String, List<Integer>> map = new HashMap<>();
        Queue<String> pq = new PriorityQueue<>((s1, s2) -> s1.compareTo(s2));
        for(int i = 0; i < tickets.size(); i++){
            if(!set.contains(i) && tickets.get(i).get(0).equals(start)){
                pq.add(tickets.get(i).get(1));
                if(!map.containsKey(tickets.get(i).get(1))){
                    map.put(tickets.get(i).get(1), new LinkedList<Integer>());
                }
                map.get(tickets.get(i).get(1)).add(i);
            }
        }
        while(pq.size() > 0){
            String end = pq.poll();
            int index = map.get(end).get(0);
            map.get(end).remove(0);
            set.add(index);
            result.add(end);
            if(result.size() == tickets.size() + 1){
                return true;
            }
            if(put(result, set, tickets, end)){
                return true;
            }
            set.remove(index);
            result.remove(result.size() - 1);
        }
        return false;
    }

    public static void main(String[] args){
    	Solution332 s = new Solution332();
    	List<String> str1 = new LinkedList<>();
        str1.add("JFK");
        str1.add("KUL");
        List<String> str2 = new LinkedList<>();
        str2.add("JFK");
        str2.add("NRT");
		List<String> str3 = new LinkedList<>();
		str3.add("NRT");
		str3.add("JFK");
        List<List<String>> tickets = new LinkedList<>();

        tickets.add(str1);
        tickets.add(str2);
        tickets.add(str3);
        List<String> result = s.findItinerary(tickets);
	}
}