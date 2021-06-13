import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static int res;
	static int[][] map;
	static int N, M;
//	두 개 씩 묶어서 더할 때 방향전환

//  0 0
//	* *

//    1 1 
//  * *  ...

	static int[][] di1 = { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, 1 }, { -1, 1 } };
	static int[][] dj1 = { { -1, 0 }, { 1, 2 }, { 0, 1 }, { 0, 1 }, { 1, 0 } };
//	세 개씩 묶어서 더 할 때 방향 전환 (가로)
//	0
//	* * * 

//	  1  
//	* * * ...

	static int[] di2 = { -1, -1, -1, 0, 1, 1, 1 };
	static int[] dj2 = { 0, 1, 2, 3, 0, 1, 2 };

//	세 개씩 묶어서 더할 때 방향 전환(세로)
//	0 *
//	  *
//	  *
//	* 1
//	*
//	* ...
	static int[] di3 = { 0, 0, 1, 1, 2, 2, 3 };
	static int[] dj3 = { -1, 1, -1, 1, -1, 1, 0 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
//		초기화 및 입력받기
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}
		int sum = 0;
		int tmp;
		int ni1, ni2, nj1, nj2;
		int ni, nj;

		for (int i = 0; i != N; i++) {
			for (int j = 0; j != M; j++) {
//		가로 두 개씩 묶어서 합 구하기.
				if (j + 1 < M) {
					sum = map[i][j] + map[i][j + 1];
					for (int d = 0; d < 5; d++) {
						ni1 = i + di1[d][0];
						ni2 = i + di1[d][1];
						nj1 = j + dj1[d][0];
						nj2 = j + dj1[d][1];
						if (ni1 >= 0 && ni2 < N && nj1 >= 0 && nj2 < M && nj1 < M && nj2 >= 0) {
							tmp = sum + map[ni1][nj1] + map[ni2][nj2];
							if (tmp > res)
								res = tmp;
						}
					}
				}
//		가로 세 개씩 묶어서 합 구하기
				if (j + 2 < M) {
					sum += map[i][j + 2];
					for (int d = 0; d < 7; d++) {
						ni = i + di2[d];
						nj = j + dj2[d];
						if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
							tmp = sum + map[ni][nj];
							if (res < tmp)
								res = tmp;
						}
					}
				}
//		세로 세 개씩 묶어서 합 구하기
				if (i + 2 < N) {
					sum = 0;
					for (int k = 0; k < 3; k++)
						sum += map[i + k][j];
					for (int d = 0; d < 7; d++) {
						ni = i + di3[d];
						nj = j + dj3[d];
//						ni는 i보다 같거나 크다
						if (ni < N && nj >= 0 && nj < M) {
							tmp = sum + map[ni][nj];
							if (res < tmp)
								res = tmp;
						}
					}
				}
			}
		}
		System.out.println(res);

	}
}