package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[][] origin;
	static int[][] moved;
	final static int[] plusVal = { 1, 0, -1, 0 };

	// moved의 내용을 origin에 복사
	public static void copyToOrigin(int N, int M) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				origin[i][j] = moved[i][j];

	}

	// R번 회전한 이후의 origin 배열 출력
	public static void printOrigin(int N, int M) {
		for (int i = 0; i < N; i++) {
			StringBuilder sb = new StringBuilder("");
			for (int j = 0; j < M; j++) {
				sb.append(origin[i][j]).append(" ");
			}
			System.out.println(sb.toString());
		}
	}

	// 한 싸이클 - 재귀.
	public static void counterClock(int startX, int startY, int N, int M) {
		if (N <= 0 || M <= 0)
			// 순회 끝.
			return;
		// 방향, 시작점 리셋.
		int addToI = 0;
		int addToJ = 3;
		if (N == 1) {
			addToI = 1;
			addToJ = 0;
		}
		int posX = startX;
		int posY = startY;
		int ni, nj;

		// 순회 시작
		do {
			ni = posX + plusVal[addToI];
			nj = posY + plusVal[addToJ];

			// 범위 나가면 방향전환 -> 한줄의 경우 고려, 여러번 ㅈㄴ화
			while (ni >= startX + N || nj >= startY + M || ni < startX || nj < startY) {
				if(N == 1 || M == 1)
				{
					ni = startX; nj = startY;
					break;
				}
				addToI = (addToI + 1) % 4;
				addToJ = (addToJ + 1) % 4;
				ni = posX + plusVal[addToI];
				nj = posY + plusVal[addToJ];
			}
			moved[ni][nj] = origin[posX][posY];
			posX = ni;
			posY = nj;

		} while (posX != startX || posY != startY);
		// 시작점으로 돌아오면 break;
		
		counterClock(startX + 1, startY + 1, N - 2, M - 2);
		// 가로, 세로 2씩 감소하고 시작점이 대각선 아래로 감
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		// N, M, R 입력
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		origin = new int[N][M];
		moved = new int[N][M];
		// origin 입력.
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				origin[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		// R번 회전.
		for (int i = 0; i < R; i++) {
			// 반시계로 회전
			counterClock(0, 0, N, M);
			// origin에 new copy
			copyToOrigin(N, M);
		}
		// 결과값 출력
		printOrigin(N, M);
	}
}
