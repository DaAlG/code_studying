import java.io.*;
import java.util.*;

// 백준 9935 문자열 폭발
/* https://velog.io/@yeoj1n/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-9935%EB%B2%88-%EB%AC%B8%EC%9E%90%EC%97%B4-%ED%8F%AD%EB%B0%9C
 * 입력받은 문자열을 한글자씩 stack에 넣으며 stack에 쌓인 문자열의 길이가 폭발 문자열보다 크거나 같으면 폭발문자열을 찾아 없애는 방법으로 풀었다.
	stack에 입력받은 문자열을 한글자씩 넣는다.
	stack에 넣은 문자열의 길이가 폭발 문자열의 길이보다 같거나 커지는 경우 stack에서 글자를 꺼내며 폭발 문자열이 만들어지는지 확인하고 폭발 문자열인 경우 그 길이만큼 stack에서 꺼낸다.
	stack 에 남은 문자열의 길이를 체크하여 남아있는 문자의 길이가 0인 경우 "FRULA"를 0 이상인 경우 문자열을 출력한다.
 */
public class Main_2 {
	// stack 사용
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String origin = br.readLine();
		String remove = br.readLine();
		Stack<Character> stack = new Stack<Character>();

		for (int i = 0; i < origin.length(); i++) {
			stack.push(origin.charAt(i));

			if (stack.size() >= remove.length()) {
				boolean flag = true;
				for (int j = 0; j < remove.length(); j++) {
					if (stack.get(stack.size() - remove.length() + j) != remove.charAt(j)) { // 같지 않은 문자열이 있다면 폭발 문자열이 아님.
						flag = false;
						break;                                            
					}
				}
				if (flag) { // 폭발 문자열이라면
					for (int j = 0; j < remove.length(); j++) {
						stack.pop(); // 스택에서 지워주기
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for(char ch : stack) {
			sb.append(ch);
		}
		
		System.out.println(sb.length() > 0 ? sb.toString() : "FRULA");
	}
}