import java.util.Stack;

// 스택 활용
class Solution_큰수만들기2 {
   
    public String solution(String number, int k) {
    	
    	char[] result = new char[number.length() - k];
    	Stack<Character> stack = new Stack<>();
    	
    	for (int i = 0; i < number.length(); i++) {
			char c = number.charAt(i);
			while(!stack.isEmpty() && stack.peek() < c && k-- >0) {
				stack.pop();
			}
			stack.push(c);
		}
    	
    	for (int i = 0; i < result.length; i++) {
			result[i] = stack.get(i);
		}
    	
    	return new String(result);
    }
    
}