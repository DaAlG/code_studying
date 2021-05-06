import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int N, M, C;
	static int[][] arr;
	static int[][] honeySum;
	static int res;
	static int maxSum;
	static int honeySum_tmp;
//	i행 - 현재 열 - 열 끝점 - 현재 순서 - 현재까지 합.
	public static void subset(int row, int col, int curIdx, int curSum) {
//		가지치기
		if (curSum > C)
			return;
//		기저
		if (curIdx == M) {
			if (curSum <= C && maxSum < honeySum_tmp) {
				maxSum = honeySum_tmp;
			}
			return;
		}
//		선택
		honeySum_tmp += arr[row][col + curIdx] * arr[row][col + curIdx];
		subset(row, col, curIdx + 1, curSum + arr[row][col + curIdx]);
//		비선택
		honeySum_tmp -= arr[row][col + curIdx] * arr[row][col + curIdx];
		subset(row, col, curIdx + 1, curSum);

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st;
		for (int t = 1; t <= T; t++) {
//		테케마다 초기화, 입력받기
			res = 0;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			arr = new int[N][N];
			honeySum = new int[N][N - M + 1];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}

//			한 행에서 M개 만큼 선택했을 때의 합을 저장
			for (int i = 0; i < N; i++) {
				for (int j = 0; j <= N - M; j++) {

					maxSum = 0;
					honeySum_tmp = 0;
//					현재 행- 시작열 - 현재 열 - 현재 순서 - 현재까지 합.
					subset(i, j, 0, 0);
					honeySum[i][j] = maxSum;

				}
			}

//			일꾼들이 수확할 벌통세트 선택하기 -> 일꾼들 벌통의 합 업데이트.
			int tmp = 0;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j + M <= N; j++) {
//					일꾼 1이 선택
					tmp = honeySum[i][j];
//					일꾼 2 -> 1의 다음 칸부터 선택.
					int ni, nj;// = 0, nj = 0;
//					시작점 구하자.
					if (j + 2 * M > N) {
//						이땐 칸 바꿔야 함.
						nj = 0;
						ni = i + 1;
					} else {
//						이 외엔 j + M 칸.이 시작점.
						nj = j + M;
						ni = i;
					}
					if (ni == N)
						break;
					int sj = nj;
					for (int si = ni; si < N; si++) {
						while (sj <= N - M) {
							tmp += honeySum[si][sj];
							if (tmp > res)
								res = tmp;
							tmp -= honeySum[si][sj];
							sj++;
						}
						sj = 0;
					}

				}
			}
//			출력
			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		System.out.println(sb);
	}
}
