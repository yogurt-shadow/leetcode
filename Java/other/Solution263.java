import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.PriorityQueue;

class Solution263 {
    public boolean isUgly(int num) {
        if(num == 1){
            return true;
        }
        int[] array = {2, 3, 5};
        for(int ele: array){
            if(num % ele == 0){
                return isUgly(num / ele);
            }
        }
        return false;
    }
}