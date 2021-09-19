import java.io.*;
import java.util.*;

// 11660 구간 합 구하기 5
public class Main_11660 {

	static int N, M;
	static int[][] map; // 입력받는 값
	static int[][] dp; // dp [i][j] = (1,1)에서 (i,j) 까지의 합

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		// 1. N * N 지도 입력 받기
		map = new int[N + 1][N + 1];
		dp = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// 2. DP 배열 완성하기 dp[i][j] = (1,1)에서 (i,j)까지의 합
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
			}
		}

		// 3. 정답 구해서 출력
		StringBuilder sb = new StringBuilder();
		int x1, y1, x2, y2;
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());

			sb.append((dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]) + "\n");
		}
		
		System.out.println(sb.toString());
	}
}