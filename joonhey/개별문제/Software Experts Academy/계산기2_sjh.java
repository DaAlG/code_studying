package day0205;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;
 
public class Solution {
    static Stack<String> stack = new Stack<>();
    static HashMap<String, Integer> map = new HashMap<>();
    static Stack<Integer> evalStack = new Stack<>();
 
    public static String changeToPostfix(String inputLine, int len) {
        StringBuilder sb = new StringBuilder();
        String input;
 
        for (int i = 0; i < len; i++) {
            input = inputLine.substring(i, i + 1);
 
            if (input.equals("*") || input.equals("+")) {
                while (!stack.empty() && map.get(input) <= map.get(stack.peek())) {
                    sb.append(stack.pop());
                }
                stack.push(input);
            }
            else {
                sb.append(input);
            }
 
        }
        while (!stack.empty()) {
            sb.append(stack.pop());
        }
        return sb.toString();
    }
 
    // 후위표현식의 계산결과를 알려줌.
    public static int evalPostfix(String expression) {
        String input;
        for (int i = 0; i < expression.length(); i++) {
            input = expression.substring(i, i + 1);
            switch (input) {
            case "+":
                evalStack.push(evalStack.pop() + evalStack.pop());
                break;
            case "*":
                evalStack.push(evalStack.pop() * evalStack.pop());
                break;
            default:
                evalStack.push(Integer.parseInt(input));
            }
        }
        return evalStack.pop();
    }
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int len;
        String postFix;
        int eval;
        map.put("*", 1);
        map.put("+", 0);
        for (int t = 0; t < 10; t++) {
            len = Integer.parseInt(br.readLine());
            postFix = changeToPostfix(br.readLine(), len);
            eval = evalPostfix(postFix);
            System.out.println("#" + (t + 1) + " " + eval);
        }
    }
}