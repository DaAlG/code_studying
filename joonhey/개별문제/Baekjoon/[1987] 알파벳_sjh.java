package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

class Solution {
	static int R, C;
	static char[][] map;
	static boolean[][] visited;
	static int[] di = { 0, 1, 0, -1 };
	static int[] dj = { 1, 0, -1, 0 };
	static int maxCnt;
	static HashSet<Character> set;
	static int cnt;
	
	//전역변수 hashSet 써보즈아..........
	public static void travelMap(int x, int y) {
		set.add(map[x][y]);
		visited[x][y] = true;
		cnt++;
		int ni, nj;
		//다음 방향 탐색
		for(int i=0; i<4; i++) {
			ni = x + di[i];
			nj = y + dj[i];
			if(ni >= 0 && nj>=0 & ni<R && nj<C && !visited[ni][nj] && !set.contains(map[ni][nj])){
				//이동 가능
				travelMap(ni, nj);
			}
		}
		//막힘 -- > 돌아감
		set.remove(map[x][y]);
		visited[x][y] = false;
		if(maxCnt < cnt)
			maxCnt = cnt;
		cnt--;
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		String inputLine;
		map = new char[R][C];
		visited = new boolean[R][C];
		set = new HashSet<>();
		
		for (int i = 0; i < R; i++) {
			inputLine = br.readLine();
			for (int j = 0; j < C; j++) {
				map[i][j] = inputLine.charAt(j);
			}
		}
		travelMap(0, 0);
		System.out.println(maxCnt);
	}
}