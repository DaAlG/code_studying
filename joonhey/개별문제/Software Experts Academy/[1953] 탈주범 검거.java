package test;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
	static int[][] map;
	static int N, M, L;
	static int time; // 경과시간
	static int res; // 정답
	static boolean[][] visited;

	static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static HashSet<Integer>[] go = new HashSet[4];
	static int[] di = { -1, 0, 0, 1 };
	static int[] dj = { 0, -1, 1, 0 };
	static Queue<Point> queue;

	public static void main(String[] args) throws Exception {
//		상, 하 , 좌, 우에 오거나 갈 수 있나 표시
//		상,하,좌,우 방향으로 갈 수 있는 터널구조물
		go[0] = new HashSet<>(Arrays.asList(1, 2, 7, 4));
		go[3] = new HashSet<>(Arrays.asList(1, 2, 5, 6));
		go[2] = new HashSet<>(Arrays.asList(1, 3, 6, 7));
		go[1] = new HashSet<>(Arrays.asList(1, 3, 4, 5));
//		상,하,좌,우 방향에서 올 수  있는 터널구조물
//		오른쪽으로 갈 수 있는 터널은 어떤 구조물의 왼쪽 옆에 있을 때 연결됨.
		int startX, startY; // 출발위치
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder("");
		for (int t = 1; t <= T; t++) {
			// 테케마다 초기화할 것.
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			startX = Integer.parseInt(st.nextToken());
			startY = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
//			경과시간및 정답 초기화
			time = 1;
			res = 1;
//			방문 배열 초기화, 위치 배열 
			visited = new boolean[N][M];
			map = new int[N][M];
			queue = new LinkedList<>();
//			지도 입력
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			// 도둑 드감
			queue.offer(new Point(startX, startY));
			visited[startX][startY] = true;
			// 주변 방문
			int ni, nj;
			while (!queue.isEmpty() && time < L) {
				int qSize = queue.size();
				for (int i = 0; i < qSize; i++) {
					Point curPos = queue.poll();
//					사방탐색
					for (int d = 0; d < 4; d++) {
//						내가 그 방향으로 갈 수 있는 가 ?
						if (go[d].contains(map[curPos.x][curPos.y])) {
							ni = curPos.x + di[d];
							nj = curPos.y + dj[d];
//						그 위치는 방문X, 범위 내, 받아 줄 수있는가?
							if (ni >= 0 && ni < N && nj >= 0 && nj < M && !visited[ni][nj]
									&& go[3-d].contains(map[ni][nj])) {
								visited[ni][nj] = true;
								res++;
								queue.offer(new Point(ni, nj));
							}
						}
					}
				}

				time++;
			}

			sb.append("#").append(t).append(" ").append(res).append("\n");
		}
		System.out.println(sb);

	}
}