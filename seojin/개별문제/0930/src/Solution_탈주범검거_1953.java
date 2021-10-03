import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

// bfs

public class Solution_탈주범검거_1953 {
	
	static int T;
	static int N, M, R, C, L;
	static int[][] map;
	static int[][] visit;
	static int cnt;
	static Queue<Node> queue;
	
	static int[] dy = {-1,1,0,0}; // 상하좌우
	static int[] dx = {0,0,-1,1}; // 상하좌우

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 세로 크기
			M = Integer.parseInt(st.nextToken()); // 가로 크기
			R = Integer.parseInt(st.nextToken()); // 맨홀 세로 위치
			C = Integer.parseInt(st.nextToken()); // 맨홀 가로 위치
			L = Integer.parseInt(st.nextToken()); // 탈출하는데 걸린 시간
			
			map = new int[N][M];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			visit = new int[N][M]; // 방문 체크 및 시간 체크
			queue = new LinkedList<>();
			
			bfs(R,C);
			
			cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if(visit[i][j] > 0) cnt++;
				}
			}
			
			System.out.println("#"+t+" "+cnt);
			
		}
	}
	
	static void bfs(int r, int c) {
		visit[r][c] = 1;
		queue.add(new Node(r,c));
		
		while(!queue.isEmpty()) {
			
			Node n = queue.poll();
					
			if(visit[n.y][n.x] == L) { // 탈출 시간에 도달한 곳은 더이상 볼 필요 없음
				continue;
			}
			
			List<Integer> nd = getDir(map[n.y][n.x]); // next direction 알아내기
			for(int i : nd) {
				
				int ny = n.y + dy[i];
				int nx = n.x + dx[i];
				
				// 범위를 벗어났거나 / 방문했거나 / 터널이 없다
				if(ny<0 || nx<0 || ny>=N || nx>=M || visit[ny][nx] > 0 || map[ny][nx] == 0) continue;
				
				// 그 다음 칸이 연결되어 있지 않은 칸이면 갈 수 없음 -> 지금 방향과는 반대 방향이 이어져야함**
				if(!canGo(i,map[ny][nx])) continue;
				
				visit[ny][nx] = visit[n.y][n.x] + 1;
				queue.add(new Node(ny,nx));
			}
			
		}
	}
	
	static boolean canGo(int dir,int nextdir) {//현재 방향에서 다음 방향으로 접근 가능한지 반환함
		switch(nextdir) {
			case 1:
				return true;
			case 2:
				if(dir==0||dir==1)return true;
				return false;
			case 3:
				if(dir==2||dir==3)return true;
				return false;
			case 4:
				if(dir==1||dir==2)return true;
				return false;
			case 5:
				if(dir==0||dir==2)return true;
				return false;
			case 6:
				if(dir==0||dir==3)return true;
				return false;
			case 7:
				if(dir==1||dir==3)return true;
				return false;
			}
		return false;
	}


	static ArrayList<Integer> getDir(int dir) {
		switch(dir) {
			case 1:
				return new ArrayList<>(Arrays.asList(0,1,2,3));
			case 2:
				return new ArrayList<>(Arrays.asList(0,1));
			case 3:
				return new ArrayList<>(Arrays.asList(2,3));
			case 4:
				return new ArrayList<>(Arrays.asList(0,3));
			case 5:
				return new ArrayList<>(Arrays.asList(1,3));
			case 6:
				return new ArrayList<>(Arrays.asList(1,2));
			case 7:
				return new ArrayList<>(Arrays.asList(0,2));
			
		}
		return null;
	}

	static class Node{
		int y,x; // y,x

		public Node(int y, int x) {
			this.y = y;
			this.x = x;

		}
	}

}
