import java.util.List;
import java.util.LinkedList;
import java.util.Stack;

class Solution636 {
    public int[] exclusiveTime(int n, List<String> logs) {
    	int[] result = new int[n];
    	for(int i = 0; i < n; i++){
    		result[i] = 0;
    	}
    	
        Stack<Integer> stack = new Stack<>();
        int clock = 0;
        for(String ele: logs){
            String[] info = ele.split(":");
            int id = Integer.parseInt(info[0]);
            int time = Integer.parseInt(info[2]);

            if(info[1].equals("start")){
                if(!stack.empty()){
                    result[stack.peek()] += time - clock;
                }

                stack.push(id);
                clock = time;
            }

            else{
                int x = stack.pop();
                result[x] += time - clock + 1;
                clock = time + 1;
            }
        }
    	return result;

    }

    public static void main(String[] args){
    	Solution636 s = new Solution636();
    	List<String> test = new LinkedList<>();


    	test.add("0:start:0");
    	test.add("1:start:2");
    	test.add("1:end:5");
    	test.add("2:start:6");
        test.add("2:end:9");
        test.add("0:end:12");
    	int[] output = s.exclusiveTime(3, test);
    	System.out.println(output[0]);
        System.out.println(output[1]);
        System.out.println(output[2]);
    	


    }
}