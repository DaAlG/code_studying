import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1220 {
	
	static int N;
	static int[][] table;
	static int cnt;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for (int t = 1; t <= 10; t++) {
			
			// 입력
			N = Integer.parseInt(br.readLine());
			table = new int[N][N];
			cnt = 0;
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int index = 0;
				while(st.hasMoreTokens()) {
					table[i][index] = Integer.parseInt(st.nextToken());
					index++;
				}
			}
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if(table[i][j] == 0) continue;
					magnet(i, j);
				} 
			}
			
			System.out.println("#"+t+" "+cnt);
		}
	}
	
	// 양쪽 볼 필요없이, 위에서 떨어지는걸로만 보고 다른 애랑 충돌할 때만 cnt++ 해주면 됨!
	static void magnet(int y, int x) {
		int ny = y;
		int nx = x;
		
		if(table[y][x] == 1) {
			// N극 자성체라면 아래로 계속 떨어짐
			while(true) {
				ny++;
				if(ny >= N || table[ny][nx] == 1) { // 떨어지거나 나랑 같은 색을 만났다면
					return;
				}
				if(table[ny][nx] == 2) { // 떨어지다가 S극을 만났다면
					cnt++;
					return;
				}
			}
		}
	}
}
