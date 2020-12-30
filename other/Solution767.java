package other;
import java.util.PriorityQueue;
import java.util.Comparator;

public class Solution767{
	private class alphabet{
		private int count;
		private char letter;

		public alphabet(int n, char x){
			count = n;
			letter = x;
		}
	}

	 public  String reorganizeString(String S) {
	 	int len = S.length();
	 	int[] counts = new int[26];
	 	for(int i = 0; i < S.length(); i++){
	 		for(int j = 0; j < 26; j++){
	 		if(S.charAt(i) - 'a' == j){
	 			counts[j]++;
	 		}
	 	}
	 	}

	 	Comparator<alphabet> h = (x1, x2) -> x2.count - x1.count;
	 	PriorityQueue<alphabet> pq = new PriorityQueue<>(h);
	 	for(int m = 0; m < 26; m++){
	 		if(counts[m] > (len + 1) / 2){
	 			return "";
	 		}
	 		if(counts[m] > 0){
	 			pq.add(new alphabet(counts[m], (char) (m + 'a')));
	 		}
	 	}

	 	String result = "";
	 	while(pq.size() != 0 || result == "") {
			alphabet a1 = pq.poll();
			result += String.valueOf(a1.letter);
			a1.count--;

			alphabet a2 = pq.poll();
			if (a2 != null) {
				result += String.valueOf(a2.letter);
				a2.count--;
				if (a1.count > 0) {
					pq.add(a1);
				}
				if (a2.count > 0) {
					pq.add(a2);
				}
			}
		}
	 return result;
    }

    public static void main(String[] args){
		Solution767 a = new Solution767();
		System.out.println(a.reorganizeString("aaab"));
	}

}