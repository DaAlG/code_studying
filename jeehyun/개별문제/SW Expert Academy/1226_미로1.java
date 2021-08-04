import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Location {
	int x, y;
	public Location(int x, int y) { this.x = x; this.y = y; }
}

class Solution {
	private static int n = 16;
	private static char map[][] = new char[n][n];
	private static int dx[] = { -1, 1, 0, 0 };
	private static int dy[] = { 0, 0, -1, 1 };
	
	public static boolean isWall(int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= n)
			return true;
		return false;
	}
	
	public static int bfs(int stx, int sty) {
		Queue<Location> q = new LinkedList<>();
		boolean visited[][] = new boolean[n][n];
		
		q.add(new Location(stx, sty));
		visited[stx][sty] = true;
		
		while (!q.isEmpty()) {
			Location now = q.poll();
			
			if (map[now.x][now.y] == '3')
				return 1;
			
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				
				if (!isWall(nx, ny) && map[nx][ny] != '1' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.add(new Location(nx, ny));
				}
			}
		}
		return 0;
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = 10;
        for (int test_case = 1; test_case <= T; test_case++) {
        	test_case = sc.nextInt();
        	
        	int stx = 0;
        	int sty = 0;
        	for (int i = 0; i < n; i++) {
        		String s = sc.next();
        		for (int j = 0; j < n; j++) {
        			map[i][j] = s.charAt(j);
        			if (map[i][j] == '2') {
        				stx = i; sty = j;
        			}
        		}
        	}
        	System.out.println("#" + test_case + " " + bfs(stx, sty));
		}
        sc.close();
	}
}