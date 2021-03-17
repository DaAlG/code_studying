package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
	static int N, M;
	static int selected[];
	static StringBuilder sb;
	
	public static void comb(int cnt, int target) {
		//기저 1 - 다 뽑음
		if(cnt == M) {
			for(int num : selected) {
				sb.append(num).append(" ");
			}
			sb.append("\n");
			return;
		}
		//기저 2 - 범위 초과
		if(target == N+1) {
			return;
		}
		//반복
		//선택
		selected[cnt] = target;
		comb(cnt+1, target+1);
		//비선택
		comb(cnt, target+1);
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		selected = new int[M];
		
		sb = new StringBuilder("");
		comb(0, 1);
		System.out.println(sb);
		
	}
}