
//백준 10026 적록색약

import java.io.*;
import java.util.*;

public class Main_10026 {

	static int N;
	static char[][] picture;
	static int[][] visited;
	static int areacnt; // 구역 번호
	static int[] dy = {-1,1,0,0}; // 상하좌우
	static int[] dx = {0,0,-1,1};
	
	static Queue<Vertex> queue = new LinkedList<>();
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		picture = new char[N][N];
		for (int i = 0; i < N; i++) {
			picture[i] = br.readLine().toCharArray();
		}
		
		visited = new int[N][N];
		// 적록색약 아니신 분
		RedGreenCanSee();
		System.out.print(areacnt+" ");
		
		// 적록색약이신분
		areacnt = 0;
		visited = new int[N][N];
		RedGreenCanNotSee();
		System.out.print(areacnt);
	
	}
	
	static void RedGreenCanSee() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(visited[i][j]>0) continue; // 방문한 곳이면 패스
				bfs(i,j);
			}
		}
	}
	
	static void RedGreenCanNotSee() {
		// 빨간색 초록색 같은 색으로 처리하기!
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(picture[i][j] == 'G') picture[i][j] = 'R';
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(visited[i][j]>0) continue; // 방문한 곳이면 패스
				bfs(i,j);
			}
		}
	}
	
	static void bfs(int i, int j) {
		queue.clear();
		
		char color = picture[i][j];
		queue.add(new Vertex(i,j));
		visited[i][j] = ++areacnt;
		
		while(!queue.isEmpty()) {
			Vertex now = queue.poll();
			for (int k = 0; k < 4; k++) {
				int ny = now.y + dy[k];
				int nx = now.x + dx[k];
				
				if(ny<0 || ny>=N || nx<0 || nx>=N) continue; // 범위 벗어나면 방문 금지
				if(visited[ny][nx]>0) continue; // 방문했던 곳 방문 금지
				if(color != picture[ny][nx]) continue; // 같은 색 아닌 곳 방문 금지
				
				queue.add(new Vertex(ny, nx));
				visited[ny][nx] = areacnt;
			}
			
		}
	}

	static class Vertex{
		int y;
		int x;
		
		public Vertex(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
