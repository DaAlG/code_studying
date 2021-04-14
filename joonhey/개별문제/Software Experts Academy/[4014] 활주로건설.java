import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	static int cnt;
	static int[] di = { -1, 1 };
	static int[][] map;
	static int N, X;
	static int res;
	static boolean[] installed;

	// road에서 i를 기준 d 방향으로 X 길이의 경사로 건설이 가능한가 ?
	public static boolean installPossible(int[] road, int current, int direct) {
		int nPos = current + di[direct];
		for (int i = 0; i < X; i++) {
			if (nPos < 0 || nPos >= N)
				return false;
			if (road[current] - road[nPos] != 1)
				return false;
			if (installed[nPos] == true)
				return false;
			installed[nPos] = true;
			nPos += di[direct];
		}
		return true;
	}

	// 가로, 세로 방향에 따른 특정한 길이 활주로 건설 가능한지 확인학 ㅗ리턴.
	public static boolean roadPossible(int[] road) {
		int nPos;
		// 좌우 탐색
		for (int i = 0; i < N; i++) {
			for (int d = 0; d < 2; d++) {
				nPos = i + di[d];
				// 범위 내에 있고 내가 걔보다 1 클 때.
				if (nPos >= 0 && nPos < N) {
					if (road[i] == road[nPos] + 1 && !installPossible(road, i, d)) {
						return false;
					}
					else if( Math.abs(road[i] - road[nPos]) > 1) {
						return false;
					}
				}
			}
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder("");
		for (int t = 1; t <= T; t++) {
			// 테케마다 초기화.
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			res = 0;
			// map 입력
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			// 행 탐색 => 좌, 우
			for (int i = 0; i < N; i++) {
				installed = new boolean[N];
				if (roadPossible(map[i]))
					res++;
			}
			System.out.println("좌우 탐색 결과 " + res);
			// 열 탐색 => 상, 하
			for (int j = 0; j < N; j++) {
				installed = new boolean[N];
				int[] tmp = new int[N];
				for (int i = 0; i < N; i++) {
					// 세로로 담긔
					tmp[i] = map[i][j];
				}
				if (roadPossible(tmp))
					res++;
			}
			System.out.println("상하까지 탐색 결과 " + res);
			// 정답
			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		System.out.println(sb);

	}
}