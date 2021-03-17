import java.util.HashMap;
import java.util.Stack;

class Solution {
	static int operCnt; // 이 식의 연산자 종류
	static char[] inputOper; // 이 식의 연산자들 중복 없이
	static boolean[] isSelected;
	static Stack<Long> operands;
	static long maxAbs;
	static Stack<Character> operator;
	static String exp;
	static HashMap<Character, Boolean> map;

	// 식 스캔하면서 계산...우선순위는 sb의 indexOf로.
	public static long evalExp(StringBuilder sb) {
		String operRank = sb.toString();
		char input;
		int idx;
		long firstPop, secondPop;

		for (int i = 0; i < exp.length(); i++) {
			input = exp.charAt(i);
			idx = operRank.indexOf(input);
			// 연산자
			if (idx != -1) {
				if (operator.empty())
					operator.push(input);
				else {//첨에 while 아니고 if로 했다가 틀림...우선순위가 같거나 높은게 있으면 걔네 계속 pop해줘야함
					while(!operator.empty() && operRank.indexOf(operator.peek()) >= operRank.indexOf(input)) {
						switch (operator.pop()) {
						case '+':
							operands.push(operands.pop() + operands.pop());
							break;
						case '-':
							firstPop = operands.pop();
							secondPop = operands.pop();
							operands.push(secondPop - firstPop);
							break;
						case '*':
							operands.push(operands.pop() * operands.pop());
							break;
						}
					}
					operator.push(input);
				}
			}
			// 피연산자
			else {
				StringBuilder num = new StringBuilder(Character.toString(input));
				while((i+1) < exp.length() && operRank.indexOf(input = (exp.charAt(++i))) == -1) {
					num.append(Character.toString(input));
				}
				//원상복구
				if(i+1 < exp.length())
					i--;
				operands.push(Long.parseLong(num.toString()));
			}
		}
		// 남으 연산 해주기
		while (!operator.empty()) {
			switch (operator.pop()) {
			case '+':
				operands.push(operands.pop() + operands.pop());
				break;
			case '-':
				firstPop = operands.pop();
				secondPop = operands.pop();
				operands.push(secondPop - firstPop);
				break;
			case '*':
				operands.push(operands.pop() * operands.pop());
				break;
			}
			
		}
		long ans = operands.pop();
		return Math.abs(ans);
	}

	// 연산자 operand를 순열로 줄세움.
	public static void perm(int cnt, StringBuilder sb) {
		if (cnt == operCnt) {
			long tempAns = evalExp(sb);
			if (tempAns > maxAbs)
				maxAbs = tempAns;
			return;
		}
		for (int i = 0; i < operCnt; i++) {
			if (!isSelected[i]) {
				sb.append(Character.toString(inputOper[i]));
				isSelected[i] = true;
				perm(cnt + 1, sb);
				sb.setLength(sb.length() - 1);
				isSelected[i] = false;
			}
		}
	}

	public long solution(String expression) {
		long answer;
		exp = expression;
		map = new HashMap<>();
		map.put('+', false);
		map.put('-', false);
		map.put('*', false);
		inputOper = new char[3];// 최대 3개
		operands = new Stack<>();
		operator = new Stack<>();
		char input;

		// 하나씩 스캔하면서 operator 중복없이 저장..
		for (int i = 0; i < expression.length(); i++) {
			input = expression.charAt(i);
			// 연산자
			if (map.get(input) != null && !map.get(input)) {
				map.put(input, true);
				inputOper[operCnt++] = input;
			}
		}

		isSelected = new boolean[operCnt];
		perm(0, new StringBuilder(""));
		answer = maxAbs;
		return answer;
	}

}