package workshop;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static int[][] square;
	static boolean[][] visited;
	static int num;
	static int posX, posY; // 디폴트 0
	// 우, 하, 좌, 상
	static int[] di = { 0, 1, 0, -1 };
	static int[] dj = { 1, 0, -1, 0 };

	public static void snailRoad(int N) {
		if (N < 1) // 기저조건
			return;
		int startX = posX;
		int startY = posY; // 무한루프 방지.
		int k = 0;
		int ni, nj;

		while (k < 4) {
			if (!visited[posX][posY]) {
				square[posX][posY] = num++;
				visited[posX][posY] = true;
			}
			// 범위 보고 k 증가.
			ni = posX + di[k];
			nj = posY + dj[k];
			//문제점: 여기 들어가면 안되는데 여기 들어가버림...
			if (ni >= startX + N || ni < startX || nj >= N + startY || nj < startY) {
				// 방향 전환 필요.
				k++;
			} else {
				// 무한루프 방지.
				if (!visited[ni][nj]) {
					posX = ni;
					posY = nj;
				} else { // 재귀 시작.
					posY+=1;
					break;
				}
			}
		}
		snailRoad(N - 2);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			posX = 0;
			posY = 0;
			num = 1;
			int N = Integer.parseInt(br.readLine());
			square = new int[N][N];
			visited = new boolean[N][N];
			snailRoad(N);
			System.out.println("#"+(t+1));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(square[i][j] + " ");
				}
				System.out.println();
			}

		}
	}

}
