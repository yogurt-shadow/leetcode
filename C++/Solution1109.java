import java.util.*;

class Solution1109 {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] ans = new int[n];
        Map<Integer, Integer> mp = new HashMap<>();
        for(int[] book: bookings){
            mp.put(book[0], book[2] + mp.getOrDefault(book[0], 0));
            mp.put(book[1] + 1, -book[2] +  mp.getOrDefault(book[1] + 1, 0));
        }
        int cur = 0;
        for(int i = 1; i <= n; i++){
            cur += mp.getOrDefault(i, 0);
            ans[i - 1] = cur;
        }
        return ans;
    }
}