// 17144 미세먼지 안녕!
// 처음에 queue썼는데 시간도 많이 걸리고, 공기청정기에서 삭제되면 큐 관리가 또 어려워져서
// 그냥 확산을 매번 전체 배열 돌면서 체크함!(어차피 50x50)

import java.io.*;
import java.util.*;

public class Main_17144 {

	static int R, C, T;
	static int[][] map;
	
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	
	// 공기청정기 위치
	static int[] airindex = new int[2];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		map = new int[R][C];
		int aircnt = 0;
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				 int num = Integer.parseInt(st.nextToken());
				 map[i][j] = num;
				 // 공기청정기 위치
				 if(num == -1) {
					 airindex[aircnt++] = i;
				 }
			}
		}
		
		int[][] up = {{-1,0}, {0,1}, {1,0}, {0,-1}}; 
		int[][] down = {{1,0}, {0,1}, {-1,0}, {0,-1}};
		
		for (int t = 0; t < T; t++) {
			// 확산
			diffuse(t);
			// 공기청정기 작동 - 위
			airpurify(0, airindex[0], 0, up);
			// 공기청정기 작동 - 아래
			airpurify(1, airindex[1], 0, down);
		}

		int res = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if(map[i][j] > -1) res += map[i][j];
			}
		}
		System.out.println(res);
	}
	
	static void airpurify(int flag, int y, int x, int[][] d) {
	
		int sy = 0, sx = 0 ,fy = 0, fx = 0;
		int ty = y;
		int tx = x;
		
		if(flag == 0) {
			// 위
			// (0,0) ~ (y,C-1)
			sy = 0;
			sx = 0;
			fy = y;
			fx = C-1;
		}else {
			// 아래
			// (y,0) ~ (R-1,C-1)
			sy = y;
			sx = 0;
			fy = R-1;
			fx = C-1;
		}
		
		// 4방향 순환
		for (int i = 0; i < 4; i++) {
			int ny = ty;
			int nx = tx;
			
			// 같은 방향이라면 계속 그 방향 가기
			while(true) {
				ny += d[i][0];
				nx += d[i][1];
				
				if(sy<=ny && ny<=fy && sx<=nx && nx<=fx) {
					map[ty][tx] = map[ny][nx];
					ty = ny;
					tx = nx;
				}else {
					break;
				}
			}
		}
		
		// 공기청정기 위치에 있는 애는 지워주고, -1로 다시 바꿔주기
		map[y][x] = -1;
		// 하나가 사라지면서 마지막 남은 애는 비워주기
		map[y][x+1] = 0;
	}
	
	static void diffuse(int sec) {
		int[][] copy = new int[R][C]; 
		
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if(map[y][x] >= 0) {
					int amount = map[y][x]; 
					int cnt = 0; // 확산된 방향의 개수
					
					// 사방 탐색
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						
						if(ny<0 || nx<0 || ny>=R || nx>=C || map[ny][nx] == -1) continue;
						
						// 확산시킬 값 copy 배열에 저장
						copy[ny][nx] += amount/5;
						cnt++;
					}
					
					// (y,x)에 남은 미세먼지 양
					map[y][x] = amount-(amount/5)*cnt;
				}
			}
		}
		
		
		// 현재 시간 종료 -> copy 배열 더하기
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] += copy[i][j];
			}
		}
		return;
	}
	
	static class Node{
		int y,x,sec;

		public Node(int y, int x, int sec) {
			super();
			this.y = y;
			this.x = x;
			this.sec = sec;
		}
	}

}
