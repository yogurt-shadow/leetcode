import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
 

class Solution399 {
	Set<Integer> set = new HashSet<>();
	List<List<Integer>> neighbors = new LinkedList<>();
	double[][] edge_value;
	double[] cur_value;

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    	Map<String, Integer> index = new HashMap<>();
    	int i = 0;
    	for(List<String> equation: equations){
    		String left = equation.get(0);
    		String right = equation.get(1);
    		if(!index.containsKey(left)){
    			index.put(left, i);
    			i += 1;
    		}
    		if(!index.containsKey(right)){
    			index.put(right, i);
    			i += 1;
    		}
    	}
    	int size = i;
    	for(int k = 0; k < size; k++){
    		neighbors.add(new LinkedList<>());
    	}

    	edge_value = new double[size][size];
    	cur_value = new double[size];
    	for(int j = 0; j < equations.size(); j++){
    		String left = equations.get(j).get(0);
    		String right = equations.get(j).get(1);
    		neighbors.get(index.get(left)).add(index.get(right));
    		neighbors.get(index.get(right)).add(index.get(left));
    		edge_value[index.get(left)][index.get(right)] = values[j];
          
            double v = 1.0 / values[j];
            
    		edge_value[index.get(right)][index.get(left)] = v;
    	}
    	double[] result = new double[queries.size()];
    	for(int j = 0; j < queries.size(); j++){
    		String left = queries.get(j).get(0);
    		String right = queries.get(j).get(1);
    		if(!index.containsKey(left) || !index.containsKey(right)){
    			result[j] = -1;
    			continue;
    		}
    		int index1 = index.get(left);
    		int index2 = index.get(right);
    		if(!is_connected(index1, index2)){
    			result[j] = -1;
    			set.clear();
    			continue;
    		}
    		cur_value[index1] = 100.0;
    		set.clear();
    		get_value(index1);
    		set.clear();
    		result[j] = formatDouble1(cur_value[index1] / cur_value[index2]);
			cur_value = new double[size];
    	}
    	return result;
    }

    private void get_value(int index1){
    	set.add(index1);
    	for(Integer neighbor: neighbors.get(index1)){
    		if(set.contains(neighbor)){
    			continue;
    		}
    		cur_value[neighbor] = edge_value[neighbor][index1] * cur_value[index1];
    		get_value(neighbor);
    	}
    }
    private double formatDouble1(double d) {
        return (double) Math.round(d * 100000)/100000;
    }

    private boolean is_connected(int index1, int index2){
    	set.add(index1);
    	if(neighbors.get(index1).contains(index2)){
    		set.clear();
    		return true;
    	}
    	for(Integer neighbor: neighbors.get(index1)){
    		if(set.contains(neighbor)){
    			continue;
    		}
    		if(is_connected(neighbor, index2)){
    			return true;
    		}
    	}
    	return false;
    }

    public static void main(String[] args){
        Solution399 s = new Solution399();
        List<List<String>> equations = new LinkedList<>();
        List<String> list1 = new LinkedList<>();
        list1.add("a"); list1.add("b");
        equations.add(list1);
        List<String> list2 = new LinkedList<>();
        list2.add("b"); list2.add("c");
        equations.add(list2);
        double[] values = {2.0, 3.0};

        List<List<String>> queries = new LinkedList<>();
        List<String> list11 = new LinkedList<>();
        list11.add("a"); list11.add("c");
        queries.add(list11);
        List<String> list22 = new LinkedList<>();
        list22.add("b"); list22.add("a");
        queries.add(list22);
        List<String> list33 = new LinkedList<>();
        list33.add("a"); list33.add("e");
        queries.add(list33);

        double[] result = s.calcEquation(equations, values, queries);
        for(double ele: result){
        	System.out.print(ele + " ");
		}
    }
}