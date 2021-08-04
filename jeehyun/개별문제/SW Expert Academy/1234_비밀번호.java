import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

class Solution {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static String solve(String pw) {
		Stack<Character> st = new Stack<>();
		for (int i = 0; i < pw.length(); i++) {
			char ch = pw.charAt(i);
			if (!st.isEmpty() && st.peek() == ch)
				st.pop();
			else
				st.push(ch);
		}
		
		StringBuilder sb = new StringBuilder();
		while (!st.isEmpty()) {
			sb.append(st.pop());
		}
		return sb.reverse().toString();
	}
	
	public static void main(String[] args) throws Exception {
		StringTokenizer st;
		for (int tc = 1; tc <= 10; tc++) {
			st = new StringTokenizer(br.readLine(), " ");
			int len = Integer.parseInt(st.nextToken());
			System.out.println("#" + tc + " " + solve(st.nextToken()));
		}
	}
}
