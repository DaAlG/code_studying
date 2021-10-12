import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class BJ_괄호의값_2504 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		Stack<String> stack = new Stack<>();
		boolean isFault = false;

		for (int i = 0; i < str.length(); i++) {

			if (isFault)
				break;
			char c = str.charAt(i);

			switch (c) {
			case '(':
				stack.push("(");
				break;
			case '[':
				stack.push("[");
				break;
			case ')':
				// stack.peek에 숫자가 없다면 pop한 뒤 숫자 넣기
				if (!stack.isEmpty() && stack.peek().equals("(")) {
					stack.pop();
					stack.push("2");
				} else {
					// 숫자가 아닐 때까지 pop
					int num = 0;
					isFault = false;
					
					while (!stack.isEmpty() && !stack.peek().equals("(")) {
						if (stack.peek().equals("[") || stack.peek().equals("]") || stack.peek().equals(")")) {
							isFault = true;
							break;
						}
						num += Integer.parseInt(stack.pop());
					}

					if (isFault)
						break;
					// 이제 숫자 다 계산한 후, (라면 pop한 후, 숫자 값 넣기
					if (!stack.isEmpty() && stack.peek().equals("(")) {
						stack.pop();
						stack.push(String.valueOf(num * 2));
					} else { // ( 여는 태그 없다면 잘못된 괄호
						isFault = true;
					}
				}
				break;
			case ']':
				// stack.peek에 숫자가 없다면 pop한 뒤 숫자 넣기
				if (!stack.isEmpty() && stack.peek().equals("[")) {
					stack.pop();
					stack.push("3");
				} else {
					// 숫자가 아닐 때까지 pop
					int num = 0;
					isFault = false;
					while (!stack.isEmpty() && !stack.peek().equals("[")) {
						if (stack.peek().equals("(") || stack.peek().equals(")") || stack.peek().equals("]")) {
							isFault = true;
							break;
						}
						num += Integer.parseInt(stack.pop());
					}
					if (isFault)
						break;
					// 이제 숫자 다 계산한 후, (라면 pop한 후, 숫자 값 넣기
					if (!stack.isEmpty() && stack.peek().equals("[")) {
						stack.pop();
						stack.push(String.valueOf(num * 3));
					} else {// [ 여는 태그 없다면 잘못된 괄호
						isFault = true;
					}
				}
				break;
			default:
				isFault = true;
				break;
			}

		}

		if (isFault) {
			System.out.println(0);
		} else {
			// 스택을 돌면서 더하는데, 만약 숫자가 아닌 값이 있다면 혼내주기
			int result = 0;
			while (!stack.isEmpty()) {
				if (stack.peek().equals("(") || stack.peek().equals("[") || stack.peek().equals(")")
						|| stack.peek().equals("]")) {
					isFault = true;
					break;
				} else {
					result += Integer.parseInt(stack.pop());
				}
			}
			if (!isFault)
				System.out.println(result);
			else
				System.out.println(0);
		}
	}
}
