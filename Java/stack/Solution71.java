import java.util.Stack;

class Solution71 {
    public String simplifyPath(String path) {
		Stack<String> stack = new Stack<>();
        for(String s: path.split("/")){
            switch(s){
                case "..":
                if(!stack.empty()){
                    stack.pop();
                }
                break;

                case ".":
                break;

                case "":
                break;

                default:
                stack.push(s);
                break;
            }
        }

        String result = "";
        if(stack.empty()){
            return "/";
        }

        while(!stack.empty()){
            result = "/" + stack.pop() + result;
        }
        return result;
    }

    public static void main(String[] args){
    	Solution71 s = new Solution71();
    	String s1 = "/home/";
    	System.out.println(s.simplifyPath(s1));
    	String s2 = "/../";
		System.out.println(s.simplifyPath(s2));
		String s3 = "/home//foo/";
		System.out.println(s.simplifyPath(s3));
		String s4 = "/a/./b/../../c/";
		System.out.println(s.simplifyPath(s4));
		String s5 ="/a/../../b/../c//.//";
		System.out.println(s.simplifyPath(s5));
		String s6 = "/a//b////c/d//././/..";
		System.out.println(s.simplifyPath(s6));
		String s7 = "/...";
		System.out.println(s.simplifyPath(s7));
    }
}