import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_점프_1890 {

	static int N;
	static int[][] board;
	static long[][] dp; // 경로의 개수 저장
	static boolean[][] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		dp = new long[N][N];
		visited = new boolean[N][N];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dp[0][0] = 1; 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(i == N-1 && j==N-1) break;
				if(j+board[i][j] < N) dp[i][j+board[i][j]] += dp[i][j]; // 오른쪽 이동
				if(i+board[i][j] < N) dp[i+board[i][j]][j] += dp[i][j]; // 아래쪽 이동
			}
		}
		System.out.println(dp[N-1][N-1]);

	}

}
