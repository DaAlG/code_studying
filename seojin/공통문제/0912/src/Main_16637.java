// 16637 괄호 추가하기

/* 괄호를 추가해야하는 경우의 수 찾기-> 계산하기라고 생각했는데
 * 완전탐색 + dfs문제라고한다.. 
 * 백트래킹 생각해내는게 너무 어렵네 ㅠㅠ 
 * https://steady-coding.tistory.com/36
 */
import java.io.*;
import java.util.*;
 
public class Main_16637 {
    static int ans;
    static ArrayList<Character> ops;
    static ArrayList<Integer> nums;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        String input = br.readLine();
 
        ops = new ArrayList<>();
        nums = new ArrayList<>();
 
        // 미리 연산자와 값을 넣어둔다.
        for (int i = 0; i < N; i++) {
            char c = input.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                ops.add(c);
                continue;
            }
            // Character.getNumericValue -> char형을 int형으로 변환
            nums.add(Character.getNumericValue(c));
        }
 
        ans = Integer.MIN_VALUE;
        DFS(nums.get(0), 0);
 
        System.out.println(ans);
    }
 
    // 연산
    public static int calc(char op, int n1, int n2) {
        switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        }
        return -1;
    }
 
    // DFS, 백트래킹 활용.
    public static void DFS(int result, int opIdx) {
        // 주어진 연산자의 개수를 초과하였을 경우.
        if (opIdx >= ops.size()) {
            ans = Math.max(ans, result); // 이전 max값과 괄호를 추가해 새로 계산된 값들 비교. 맨 처음에는 괄호 없는 연산 값 저장됨.
            return;
        }
 
        // 괄호가 없는 경우
        int res1 = calc(ops.get(opIdx), result, nums.get(opIdx + 1));
        DFS(res1, opIdx + 1);
        

        // 괄호가 있는 경우
        if (opIdx + 1 < ops.size()) {
            // result의 오른쪽에 있는 값을 연산함.
            int res2 = calc(ops.get(opIdx + 1), nums.get(opIdx + 1), nums.get(opIdx + 2));
 
            // 현재 result와 방금 구한 괄호 값을 연산한 결과와 괄호 오른쪽에 존재하는 연산자의 인덱스를 넘김.
            DFS(calc(ops.get(opIdx), result, res2), opIdx + 2);
        }
    }
 
}
