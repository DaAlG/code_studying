import java.io.*;
import java.util.*;

public class Solution_1767 {
	
	static int T, N;
	static int[][] map;
	static List<Node> core;
	
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	
	static int maxCorecnt, minWirecnt;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			
			// 초기화
			N = Integer.parseInt(br.readLine());
			map = new int[N+2][N+2]; // 둘레를 벽으로 만들어주기!
			core = new ArrayList<>();
			maxCorecnt = 0;
			minWirecnt = 0;
			
			// 입력 처리
			for (int i = 1; i <= N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 1; j <= N; j++) {
					
					map[i][j] = Integer.parseInt(st.nextToken());
					// 코어 위치를 리스트에 담기
					if(map[i][j] == 1) core.add(new Node(i,j));
				}
			}
			
			connect(0,0,0);
			System.out.println("#"+t+" "+minWirecnt);
		}
		
	}
	
	// dfs
	static void connect(int index, int corecnt, int wirecnt) {

		// index가 List.size라면 -> 종료조건
		if(index == core.size()) {
			
//			System.out.println("Core : " +corecnt+" wire : "+wirecnt);
			// corecnt가 max일 때, wirelen 비교...
			if(maxCorecnt < corecnt) {
				maxCorecnt = corecnt;
				minWirecnt = wirecnt;
			}else if(maxCorecnt == corecnt) {
				if(minWirecnt > wirecnt) {
					minWirecnt = wirecnt;
				}
			}
			
//			System.out.println("maxCore : " +maxCorecnt+" minwire : "+minWirecnt);
			return;
		}
		
		// 현재 coreList의 index
		Node now = core.get(index);
		
		// 사방탐색 -> 코어 주변에 벽 있음
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			
			// 코어가 벽을 만났다면 다음 코어로!
			if(ny<1 || nx<1 || ny>N || nx>N) {
				connect(index+1, corecnt+1, wirecnt);
				return;
			}
		}
		boolean isConnect = false;
		// 사방탐색 -> 벽 없음
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			
			// 1이라면(core)가 있거나 전선이 있다면 continue;
			if(map[ny][nx] == 1 || map[ny][nx] == -1) continue;
			else {
				// 그 방향으로 벽까지 달리기(-1)로 채우기
				boolean isWall = false;
				int cnt = 0;
				while(true) {
					if(ny<1 || nx<1 || ny>N || nx>N) {
						isWall = true;
						break;
					}
					if(map[ny][nx] == 0) {
						map[ny][nx] = -1;
						ny += dy[i];
						nx += dx[i];
						cnt++;
					}else if(map[ny][nx] == 1 || map[ny][nx] == -1) {
						break;
					}
				}
				
				// 벽까지 전선이 연결되었다면
				if(isWall) {
					isConnect = true;
					connect(index+1, corecnt+1, wirecnt+cnt);
				}
				// 원상복구
				while(true) {
					ny -= dy[i];
					nx -= dx[i];
					
					if(ny == now.y && nx == now.x )break;
					map[ny][nx]  = 0;
				}
			}
		}
		// isConnect = false라면 (사방탐색갔는데 연결할 곳이 없네?)
		if(!isConnect) connect(index+1, corecnt, wirecnt);
	}
	
	
	static class Node{
		int y;
		int x;
		
		public Node(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
