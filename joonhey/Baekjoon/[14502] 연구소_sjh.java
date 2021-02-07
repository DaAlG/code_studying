package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int R, C;
	static int origin; // 원래 바이러스 + 빈공간.
	static char[][] lab;
	static boolean[][] visited; // spreadVirus에서 한 번 더 초기화.
	static int maxSafe = -1;
	static int curVirus;

	static class Position {
		int x;
		int y;

		public Position(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static Queue<Position> queue = new LinkedList<>(); // 빌때까지 순회 -> 초기화 필요 x
	static int[] di = { -1, 1, 0, 0 };
	static int[] dj = { 0, 0, -1, 1 };

	public static void clearVisited() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				visited[i][j] = false;
			}
		}
	}

	// 특정 바이러스 시발점에서의 바이러스의 확산을 계산.
	public static void BFS() {
		if (queue.isEmpty())
			return; // 더 이상 방문할 곳 x
		int ni, nj;
		// 현 위치 방문.
		Position pos = queue.poll();
		curVirus++;

		// 상하좌우 탐색.
		for (int i = 0; i < 4; i++) {
			ni = pos.x + di[i];
			nj = pos.y + dj[i];
			if (ni >= 0 && nj >= 0 && ni < R && nj < C && lab[ni][nj] != '1' && !visited[ni][nj]) {
				queue.offer(new Position(ni, nj));
				visited[ni][nj] = true;
			}
		}
		BFS();

	}

	// 특정 조합(벽)의 lab을 탐색하며 바이러스를 퍼뜨린다
	// 최대 안전영역 업데이트.
	public static void spreadVirus() {
		curVirus = 0;
		clearVisited(); // visited 초기화

		// 2인곳 방문하면서 확산 시작 -> curVirus 계산
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (lab[i][j] == '2' && !visited[i][j]) {
					visited[i][j] = true;
					queue.offer(new Position(i, j)); // 시발점
					BFS();
				}
			}
		}
		// 바이러스 개수 측정 완료 > 안전영역 갱신.
		if (maxSafe < origin - curVirus)
			maxSafe = origin - curVirus;
	}

	// lab[x][y]에 벽('1')을 세운다.
	public static void buildWall(int x, int y, int cnt) {
		// 기저조건
		if (cnt == 3) {
			spreadVirus();
			return;
		} else if (x == R)
			return; // 더 이상 조합 X
		else if (y == C)
			buildWall(x + 1, 0, cnt);
		else if (lab[x][y] != '0')
			buildWall(x, y + 1, cnt);
		else { // 범위 내, 빈 공간에만 벽 건설 가능.
				// 장소 선택.
			lab[x][y] = '1';
			buildWall(x, y + 1, cnt + 1);
			// 장소 비선택.
			lab[x][y] = '0';
			buildWall(x, y + 1, cnt);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		lab = new char[R][C];
		visited = new boolean[R][C];
		String inputLine;
		char input;
		int k;

		// 지도 입력
		for (int i = 0; i < R; i++) {
			inputLine = br.readLine();
			k = 0;
			for (int j = 0; j < 2 * C; j += 2) {
				input = inputLine.charAt(j);
				lab[i][k++] = input;
				if (input != '1') {
					origin++;
				}
			}
		}

		origin -=3; //곧 벽을 3개 쌓을 것이므로 빈공간이 3 줄어듦.여기서 두시간 날림 하...
		buildWall(0, 0, 0);
		System.out.println(maxSafe);

	}
}
