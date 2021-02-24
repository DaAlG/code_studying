package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static boolean[][] visited;
	static int[] di = { -1, 1, 0, 0 };
	static int[] dj = { 0, 0, -1, 1 };

	public static void fillBoard(int startY, int startX) {
		for (int i = startX; i < startX + 10; i++) {
			for (int j = startY; j < startY + 10; j++) {
				visited[i][j] = true;
			}
		}
	}

	
	public static int measureRes() {
		int ni, nj;
		int res = 0;
		
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (visited[i][j]) {
					for (int k = 0; k < 4; k++) {
						ni = i + di[k];
						nj = j + dj[k];
						if (ni >= 0 && nj >= 0 && ni < 100 && nj < 100) {
							if(!visited[ni][nj])
								res++;
						}
						else {
							res++;
						}
					}
				}
			}
		}
		
		return res;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		visited = new boolean[100][100];

		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			fillBoard(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		System.out.println(measureRes());
	}
}