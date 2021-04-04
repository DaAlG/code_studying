import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static boolean[] garo;
	static boolean[] sero;
	static int[][] map;
	static int N;
	static int L;
	static int[] di = { -1, 1, 0, 0 };
	static int[] dj = { 0, 0, -1, 1 };
	static int[][][] installed;

	// map[i][j] 열로부터 k만큼 다리를 세워야 하는데 세울수 있는지 검사.
	public static boolean installBridges(int i, int j, int k) {
		int ni = i + di[k];
		int nj = j + dj[k];
		int top = map[i][j];

		for (int len = 1; len <= L; len++) {
			// L 이전에 범위 밖이면 false
			if (ni >= N || ni < 0 || nj >= N || nj < 0)
				return false;
			// 크기가 차이가 1이 아닌게 나오면 바로 false
			if (top - map[ni][nj] != 1)
				return false;
			if(installed[ni][nj][k<2?0:1] != 0)
				return false;
			// 다음 위치
			ni += di[k];
			nj += dj[k];
		}

		return true;
	}
	public static void makeBrideges(int i, int j, int k) {
		int ni = i + di[k];
		int nj = j + dj[k];

		for (int len = 1; len <= L; len++) {
			installed[ni][nj][k<2?0:1]++;
			// 다음 위치
			ni += di[k];
			nj += dj[k];
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		// 각각 그 방향으로 경사로를 놓을 수 있는지 체크.
		garo = new boolean[N];
		sero = new boolean[N];
		installed = new int[N][N][2];
		int ni, nj;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 상하 탐색 -> sero 결정
				for (int k = 0; k < 2; k++) {

					ni = i + di[k];
					// 범위 밖, 같은 크기 , 나보다 큼-> ㄱㅊ
					if (ni >= N || ni < 0 || map[ni][j] >= map[i][j])
						continue;
					// 다리를 세워야 하는 환경임 -> 세울 수 없으면 false, 있으면 true리턴하고 다리를 세운다.
					// L개가 모두 길이가 1 차이 나야 함.
					if (installBridges(i,j,k)) {
						// 설치하기.
						makeBrideges(i, j, k);
					} else {
						// 설치 불가능
						sero[j] = true;
					}
				}
				// 좌우 탐색 -> garo 결정
				for (int k = 2; k < 4; k++) {
					nj = j + dj[k];
					// 범위 밖, 같은 크기 , 나보다 큼-> ㄱㅊ
					if (nj >= N || nj < 0 || map[i][nj] >= map[i][j])
						continue;
					if (installBridges(i,j,k)) {
						// 설치하기.
						makeBrideges(i, j, k);
					} else {
						// 설치 불가능
						garo[i] = true;
					}
					
					
				}
			}
		}
		// 출력: garo, sero에서 false인 길의 개수 합산
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (!garo[i])
				sum++;
			if (!sero[i])
				sum++;
		}
		System.out.println(sum);
	}
}