import java.io.*;
import java.util.*;

// 백준 9935 문자열 폭발
// 2퍼.. 뭔가 temp를 지우고 문자열을 지워가야할 거 같은 느낌.. 메모리 초과.
public class Main {

	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		String bomb = br.readLine();
		int index = 0; 
		boolean isfind = false;
		Stack<Character> stack = new Stack<>();
		Stack<Character> temp = new Stack<>();
		int bomblen = bomb.length();
		
		while(str.contains(bomb)) {
			for (int i = 0; i < str.length(); i++) {
				
				if(isfind && str.charAt(i)!=bomb.charAt(index)) { // 앞에서 일치했는데 지금 일치하지 않다면
					isfind = false; // 폭발 문자열이 아니야
					for(char t : temp) { // 다시 스택에 넣어주기~
						stack.push(t);
					}
					index = 0;
					temp.clear();
				}
				
				if(str.charAt(i)==bomb.charAt(index)) { // 지금 문자열이 지금 가리키는 폭발 문자열 위치와 일치한다면
					if(temp.isEmpty()) { // temp가 비어있다면 이제 시작 위치이구..
						isfind = true; // 폭발 문자열이 될 수 잇어~ 라고 표시해두기
					}
					temp.push(bomb.charAt(index++)); // temp에 넣고, index 증가시켜두기
				}else { // 일치하지 않는다면
					stack.push(str.charAt(i)); // 그냥 스택에 넣어뿌
				}
				
				if(bomblen == index) { // 만약 폭발 문자열 찾은거라면
					isfind = false; // 이제 다시 찾으러 가야지...
					temp.clear(); // 비워두고
					index = 0; // 다시 첨부터 보기
				}
			}
			
			if(!temp.isEmpty()) { // 마지막에 남은 애들
				for(char t : temp) { // 다시 스택에 넣어주기~
					stack.push(t);
				}
			}
			str = "";
			for(char c : stack) {
				str += c;
			}
			stack.clear();
			temp.clear();
		}

		if(str.isEmpty()) System.out.println("FRULA");
		else System.out.println(str);
	}
}
