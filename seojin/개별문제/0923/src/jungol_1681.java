// 해밀턴 순환회로
import java.io.*;
import java.util.*;

public class jungol_1681 {
	
	static int N, minCost;
	static int[][] map;
	static boolean[] visited;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine().trim());
		map = new int[N+1][N+1];
		visited = new boolean[N+1];
		minCost = Integer.MAX_VALUE;
		
		for (int i = 1; i < N+1; i++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int j = 1; j < N+1; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(1, 0, 0);
		System.out.println(minCost);
	}

	static void dfs(int row, int cnt, int cost) {
		if(cnt==N-1) {
			if(map[row][1] == 0) return;
			cost += map[row][1];
			minCost = Math.min(minCost, cost);
			return;
		}
		
		for (int i = 2; i <= N; i++) {
			if(row == i || visited[i] || map[row][i] == 0) continue;
			if(minCost < cost+map[row][i]) continue;
			visited[i] = true;
			dfs(i, cnt+1, cost+map[row][i]);
			visited[i] = false;
		}
		return;
	}
}
