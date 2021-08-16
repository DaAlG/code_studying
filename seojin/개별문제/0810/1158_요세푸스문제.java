import java.io.*;
import java.util.*;

public class Main {
	
	static int N, K;
	static int[] input;
	static StringBuilder output = new StringBuilder();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		input = new int[N+1];
		
		for (int i = 1; i <=N; i++) {
			input[i] = i;
		}
		
		output.append("<");
		int count = 0; // 죽는 수가 나오면 증가
		int idx = 1;
		int step = 1;
		
		while(true) {
			if(count == N) break; 
			
			// 살아있는 번호
			if(input[idx] != 0) {
				// 그 번호가 k의 배수이면
				if(step % K == 0) {
					output.append(input[idx]+", ");
					input[idx] = 0;
					count++;
				}
				step++;
			}
			idx ++;
			if(idx > N) idx = 1;
		}
		
		output.deleteCharAt(output.length()-2);
		output.deleteCharAt(output.length()-1);
		output.append(">");
		System.out.println(output);
	}

}
