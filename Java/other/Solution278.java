/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */
/**
public class Solution278 extends VersionControl {
    public int firstBadVersion(int n) {
       return firstBadVersion2(1, n);
    }

    private int firstBadVersion2(int a, int b){
    	if(a == b){
    		return a;
    	}
    	if(b == a + 1){
    		return isBadVersion(a) ? a : b;
    	}
    	int middle = (a - b) / 2 + b;
    	if(isBadVersion(middle)){
    		return firstBadVersion2(a, middle);
    	}
    	return firstBadVersion2(middle, b);
    }
}
*/
