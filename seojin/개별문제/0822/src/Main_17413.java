
import java.io.*;
import java.util.*;

// 단어뒤집기 2
public class Main_17413 {

	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Character> stack = new Stack<>();
		String sen = br.readLine();
		int i = 0;
		int n = sen.length();
		
		boolean isTag = false; // 태그인 경우
		
		while(i < n) {
			// 공백 만났다면
			if(!isTag && sen.charAt(i) == ' ') {
				while(!stack.isEmpty()) System.out.print(stack.pop());
				System.out.print(sen.charAt(i++));
				continue;
			}
			
			if(sen.charAt(i) == '<') { // 열린 태그라면
				
				if(!stack.isEmpty()) {
					// 스택이 비어있지 않다면
					while(!stack.isEmpty()) System.out.print(stack.pop());
				}
				System.out.print(sen.charAt(i++));
				isTag = true; 
				continue;
				
			}else if(sen.charAt(i) == '>') { // 닫힌 태그라면
				
				isTag = false; 
				System.out.print(sen.charAt(i++));
				continue;
				
			}
			
			if(isTag) {
				// 태그 안의 단어라면
				System.out.print(sen.charAt(i++));
				continue;
			}else if(!isTag) { // 단어라면
				stack.add(sen.charAt(i++));
			}
		}
		while(!stack.isEmpty()) System.out.print(stack.pop()); // 마지막 처리
	}
}
