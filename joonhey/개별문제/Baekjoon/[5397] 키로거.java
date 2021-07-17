package ahah;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main{
	static StringBuilder res = new StringBuilder("");
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine());
		Stack<Character> stack1 = new Stack();
		Stack<Character> stack2 = new Stack();
		
		for(int k = 0; k < num; k++) {
			int idx = 0;
			String str = br.readLine();
	
			for(int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				
				if( c != '<' && c != '>' && c != '-') { // alphabet 인지 확인
					stack1.push(c);
					continue;
				}
				else if(c == '<' && !stack1.isEmpty()) {
					stack2.push(stack1.pop());
					continue;
				}
				else if(c == '>' && !stack2.isEmpty()){
					stack1.push(stack2.pop());
					continue;
				}
				else if(c == '-' && !stack1.empty()) {
					stack1.pop();
				}	
			}
			StringBuilder sb = new StringBuilder();
			while(!stack2.isEmpty())
				sb.append(stack2.pop());
			StringBuilder sb2 = new StringBuilder();
			while(!stack1.isEmpty())
				sb2.append(stack1.pop());
			res.append(sb2.reverse()).append(sb).append("\n");
		}
		res.setLength(res.length()-1);
		System.out.println(res);
	}
}