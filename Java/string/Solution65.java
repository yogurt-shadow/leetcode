class Solution65 {
    public boolean isNumber(String s) {
       boolean dot_before = false;
       boolean dot_after = false;
       boolean in_exp = false;
       boolean exp_after = false;
       boolean double_space = false;
       boolean sign_double = false;
       boolean in_E = false;
       boolean E_after = false;
       String state = "start";

       boolean dot = false;
       boolean eee  = false;
       for(int i = 0; i < s.length(); i++){
            char cur = s.charAt(i);
            if(cur == '.'){
                  if(dot){
                        return false;
                  }
                  dot = true;
            }

            if(cur == 'e'){
                  if(eee){
                        return false;
                  }
                  eee = true;
            }
       }

     loop:  for(int i = 0; i < s.length(); i++){
       	char cur = s.charAt(i);
            if(i == s.length() - 1 && ((cur == 'e') || (cur == '+') || (cur == '-'))){
                  return false;
            }
       	switch(state){
       		case "start":
       		if(cur == '+' | cur == '-'){
       			state = "sign";
       		}
       		else if(cur == '.'){
       			state = "double";
       			if(i == s.length() - 1){
       				return dot_before;
				}
       		}
       		else if(cur >= '0' && cur <= '9'){
       			state = "number";
       			dot_before = true;
       		}
       		else if(cur == ' '){
       			continue loop;
       		}
       		else{
       			return false;
       		}
       		break;

       		case "sign":
       		if(cur >= '0' && cur <= '9'){
				if(in_exp){
					exp_after = true;
					state = "exp";
				}
				else {
					state = "number";
					dot_before = true;
				}
       		}
       		else if(cur == '.'){
       			if(i == s.length() - 1){
       				return dot_before;
				}
       			state = "double";
       		}
       		else{
       			return false;
       		}
       		break;

       		case "double":
       		if(i == s.length() - 1){
       			if(cur >= '0' && cur <= '9'){
       				dot_after = true;
				}
       			else if(cur == ' ') {
					return dot_before || dot_after;
				}
       			else{
       				return false;
				}
       		}
       		if(in_exp){
       			return false;
       		}
       		else if(cur >= '0' && cur <= '9'){
       			dot_after = true;
       		}
       		else if(cur == ' '){
       			double_space  = true;
       			continue loop;
       		}
                  else if(cur == 'e'){
                        in_exp = true;
                        state = "exp";
                        if(!(dot_before || dot_after)){
                        	return false;
						}
                        if(double_space){
                        	return false;
						}
                  }
       		else{
       			return false;
       		}
       		break;

                  case "E":
                  if(cur >= '0' && cur <= '9'){
                        E_after = true;
                  }
                  else if(cur == ' '){
                        return E_after;
                  }
                  else if(cur == '+' || cur == '-'){
                        if(E_after || sign_double){
                              return false;
                        }
                       sign_double = true;
                  }
                  break;

       		case "number":
                  if(cur == 'E'){
                        if(i == s.length() - 1){
                              return false;
                        }
                        state = "E";
                        in_E = true;
                  }
       		else if(cur >= '0' && cur <= '9'){
       			continue loop;
       		}
       		else if(cur == '.'){
       			state = "double";
       		}
       		else if(cur == 'e'){
       			state = "exp";
       			in_exp = true;
       		}
       		else{
       			return false;
       		}
       		break;

       		case "exp":
       		if(cur >= '0' && cur <= '9'){
                        exp_after = true;
       			continue loop;
       		}
       		else if(cur == '+' | cur == '-'){
       			state = "sign";
       			if(exp_after){
       				return false;
				}
       		}
                  else if(cur == ' '){
                        if(exp_after){
                              continue;
                        }
                        else{
                              return false;
                        }
                  }
       		else{
       			return false;
       		}
       		break;

       		default:
       		break;
       	}
       }
       return true;
    }

    public static void main(String[] args){
    	Solution65 s = new Solution65();
    	System.out.println(s.isNumber("1E+1+2"));
    }
}