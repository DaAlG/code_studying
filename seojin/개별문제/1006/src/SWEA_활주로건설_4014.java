import java.io.*;
import java.util.*;

// 해결 덜햇엉...

public class SWEA_활주로건설_4014 {

	static int T;
	static int N, X;
	static int[][] arr;
	static int ans = 0;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine().trim());
		for (int t = 1; t <= T; t++) {
		
			// 입력
			st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			
			arr = new int[N][N];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine().trim());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			ans = 0;
			
			// 행, 열 탐색
			for (int i = 0; i < N; i++) {
				// 행 탐색
				build(i,1);
				// 열 탐색
				build(i,2);
			}
			
			
			System.out.println("#"+t+" "+ans);
		}

	}

	private static void build(int idx, int check) {

		int[] list = new int[N];
		
		if(check == 1) {
			// idx번째 행 탐색
			list = arr[idx];
			System.out.print("행"+idx+" ");
			System.out.println(Arrays.toString(list));
		}else {
			// idx번째 열 탐색
			for(int i=0; i<N; i++) list[i] = arr[i][idx];
			System.out.print("열"+idx+" ");
			System.out.println(Arrays.toString(list));
		}
		
		
		for (int i = 0; i < N-1; i++) {
			int now = list[i];
			
			if(now != list[i+1]) {
				
				// 높이 차이가 1일 때
				if(Math.abs(now-list[i+1])==1) {
					boolean c = check(now, i, list);
					if(c) { // 경사로 건설 성공 
						i += X;
						continue;
					}else { // 경사로 건설 불가
						return;
					}
				}else {
					// 높이 차이가 2 이상 -> 경사로 불가능
					return;
				}
			}
		}
		
		ans++;
	}

	// 이러면 범위 벗어나는 거는 체크가 안되넹..? 흠,.,,,
	static boolean check(int prev, int i, int[] list) {

		for (int j = i; j < i + X; j++) {
			if(prev != list[j]) return false;
		}
		return true;
	}

}
