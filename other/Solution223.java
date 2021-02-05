class Solution223 {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	long area1 = (C - A) * (D - B);
    	long area2 = (G - E) * (H - F);
    	long overlap = Math.max(0, (long) Math.min(C, G) - Math.max(A, E)) * Math.max(0, (long) Math.min(D, H) - Math.max(B, F));
        long area = area1 - overlap + area2;
    	return (int) area;
    }

    public static void main(String[] args){
    	Solution223 s = new Solution223();
    	System.out.println(s.computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1));
    }
}