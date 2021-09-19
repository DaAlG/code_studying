import java.util.*;
import java.io.*;

// 1918 후위 표기식

public class Main_1918 {

	static List<Character> postArr = new ArrayList<>();
	static Stack<Character> stack = new Stack<>();
	static Map<Character, Integer> op = new HashMap<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] infix = br.readLine().toCharArray();
		op.put('(', 0);
		op.put(')', 0);
		op.put('+', 1);
		op.put('-', 1);
		op.put('*', 2);
		op.put('/', 2);
		
		for(char c : infix) {
			if(c>='A' && c<='Z') {
				postArr.add(c);
			}else {
				// 연산자일 때
				if(stack.isEmpty()) stack.add(c);
				else {
					if(c == '(') stack.add(c);
					else if(c == ')') {
						while(stack.peek()!='(')
							postArr.add(stack.pop());
						stack.pop();
					}
					else if(op.get(c) <= op.get(stack.peek())) {
						while(!stack.isEmpty() && op.get(c) <= op.get(stack.peek()))
							postArr.add(stack.pop());
						stack.add(c);
					}
					else if(op.get(c) > op.get(stack.peek())) {
						stack.add(c);
					}
					
				}
			}

		}
		while(!stack.isEmpty()) {
			postArr.add(stack.pop());
		}
		
		for(char c : postArr) {
			System.out.print(c);
		}
	}

}
