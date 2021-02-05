package day0205;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution {
	static Stack<Character> stack = new Stack<>();

	// 입력한 문자열을 한 글자씩 스택에 넣고 빼면서 res++
	public static int cutSticks(String inputLine) {

		char letter;
		int res = 0;
		
		for (int i = 0; i < inputLine.length(); i++) {
			letter = inputLine.charAt(i);
			if (letter == '(') {
				stack.push(letter);
			} else { // 닫는 괄호: 레이저인가, 닫는 벽인가? by idx
				stack.pop();
				if (inputLine.charAt(i - 1) == '(') {
					res += stack.size();
				} else {
					res++;	
				}
			}

		}
		return res;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		String inputLine;
		int res; 
		
		for (int t = 0; t < T; t++) {
			stack.clear();// 테케마다 초기화..할필요 x 함 지워보고 또해보기.
			res = cutSticks(br.readLine());
			// 답 출력
			System.out.println("#" + (t + 1) + " " + res);
		}

	}
}