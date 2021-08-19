
//baekjoon 1987 알파벳

import java.io.*;
import java.util.*;

public class Main_1987 {
	
	static int R, C;
	static char[][] board;
	static boolean[] visited = new boolean[26]; //알파벳 방문했는지 여부 확인
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	static int max_len;
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		board = new char[R][];
		for (int i = 0; i < R; i++) {
			board[i] = br.readLine().toCharArray();
		}
		
		visited[board[0][0]-65] = true; // 첫 칸 방문한 거니까
		dfs(1,0,0); // 1 = 첫 칸 포함
		
		System.out.println(max_len);
	}
	
	static void dfs(int s, int y, int x) {
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(!visited[board[ny][nx]-65]) {
				visited[board[ny][nx]-65] = true;
				dfs(s+1, ny, nx);
				visited[board[ny][nx]-65] = false;
			}
			if(s > max_len) max_len = s;
		}
	}
}
