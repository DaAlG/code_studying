import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int[] top = new int[N+1];
		for(int i=1; i<=N; i++) {
			top[i] = Integer.parseInt(st.nextToken());
		}
		
		Stack<Integer> stack = new Stack<>(); 
		int[] index = new int[N+1];
		int[] result = new int[N+1]; // 인덱스 담을 결과 배열
		
		stack.push(top[1]); // 첫번째 탑 처리
		int idx = 1;
		index[1] = 1;
		for(int i=2; i<=N; i++) {
				// 현재 stack의 top보다 큰게 들어오면 top이 나보다 클 때까지 pop하고 나를 넣는다.
				// 왜냐면 이제 나 뒤에 있는 애들은 나보다 작은 탑은 볼 수 없기 때문. , top에 있는 애를 가리키고, 
			while (!stack.isEmpty()) {
				if (stack.peek() < top[i]) { // 현재 stack의 top보다 내가 더 높으면 
					stack.pop(); // 얘는 가리킬 애가 이제 없으므로 지워줘
					index[idx--] = 0;
					
				}else {
					break;
				}
			}
			if(stack.isEmpty() || stack.peek() > top[i]) { 
				result[i] = index[idx]; // 내가 가리키는 탑을 result에 넣는다.
				stack.push(top[i]); 
				index[++idx] = i;
			}
		}
		
		for(int i=1; i<=N; i++) {
			System.out.print(result[i]+" ");
		}

	}

}
