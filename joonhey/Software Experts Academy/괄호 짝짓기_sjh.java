package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class Solution {
	static ArrayList<Character> stack;
	static boolean flag;
	static HashMap<Character, Character> map = new HashMap<>(); // 닫는괄호-여는괄호.

	public static char pop() {
		int len = stack.size();
		if (len == 0) {
			return 'x';
		} else {
			return stack.remove(len - 1);
		}
	}


	public static void updateStack(char input) {
		char outChar;

		outChar = pop();
		
		if(outChar == 'x')
			flag = false;
		
		else if (map.get(input) != outChar)
			flag = false;

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int length;
		String inputLine;
		char inputChar;
		int res = 1;

		map.put(')', '(');
		map.put(']', '[');
		map.put('}', '{');
		map.put('>', '<');

		for (int t = 0; t < 10; t++) {
			// stack, flag reset
			stack = new ArrayList<>();
			flag = true; // 디폴트는 트루.
			length = Integer.parseInt(br.readLine());
			inputLine = br.readLine();

			for (int i = 0; i < length; i++) {
				inputChar = inputLine.charAt(i);
				// 여는 괄호면 push, 닫는 괄호면 pop
				if (map.get(inputChar) == null)
					stack.add(inputChar);
				else
					updateStack(inputChar);

				if (!flag) {
					res = 0;
					break;
				}
			}
			// true일 때만 재확인.
			if (flag) {
				if (stack.size() == 0)
					res = 1;
				else
					res = 0;
			}
			// 출력
			System.out.println("#" + (t + 1) + " " + res);

		}
	}
}
