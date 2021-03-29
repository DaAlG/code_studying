package day0323;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
	static int[][] map;
	static int N, M;
	static boolean[][] visited;
	static Queue<Point> empty;

	static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		visited = new boolean[N][M];
		empty = new LinkedList<>();
		int area = 0;
		int[] di = { -1, 1, 0, 0 };
		int[] dj = { 0, 0, -1, 1 };

		// 판 입력
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				area += map[i][j];
			}
		}

		// 최초 시발점 -> 판의 가장자리엔 치즈가 없으니 ㄱㄴ
		int hour = 0;
		int hole = 0;
		// BFS
		while (area != 0) {
			hole = 0;
			visited = new boolean[N][M];
			empty.offer(new Point(0, 0));
			visited[0][0] = true;
			// 한시간 간격으로 탐색.
			while (!empty.isEmpty()) {
				Point cur = empty.poll();
				// 외부 공간 기준 사방 탐색
				for (int d = 0; d < 4; d++) {
					int ni = cur.x + di[d];
					int nj = cur.y + dj[d];
					if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
						if (!visited[ni][nj]) {
							visited[ni][nj] = true;
							if (map[ni][nj] == 0) {
								empty.add(new Point(ni, nj));
							} else {
								map[ni][nj] = 0; //구멍으로 바꿔주그
								hole++;
							}
						}
					}
				}

			}
			hour++;
			area -= hole;
		}
		// 정답 출력
		System.out.println(hour);
		System.out.println(area + hole);
	}
}
