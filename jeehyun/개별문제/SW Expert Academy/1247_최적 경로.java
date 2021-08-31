import java.util.Scanner;

// SWEA 1247 최적 경로
class Solution {
	static int n;
	static int[][] p;
	static boolean[] visited;
	static int answer;
	
	public static void go(int now, int cnt, int dist) {
		if (cnt == n + 2) {
			answer = Math.min(answer, dist);
			return;
		}
		
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				flag = 0;
				visited[i] = true;
				int d = Math.abs(p[now][0] - p[i][0]) + Math.abs(p[now][1] - p[i][1]);
				go(i, cnt + 1, dist + d);
				visited[i] = false;
			}
		}
		
		if (flag == 1) {
			int d = Math.abs(p[now][0] - p[n + 1][0]) + Math.abs(p[now][1] - p[n + 1][1]);
			go(n + 1, cnt + 1, dist + d);
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for (int test_case = 1; test_case <= T; test_case++) {
			n = sc.nextInt();
			p = new int[n + 2][2];
			visited = new boolean[n + 2];
			
			for (int i = 0; i <= n; i++) {
				p[i][0] = sc.nextInt();
				p[i][1] = sc.nextInt();
				if (i == 0) {
					p[n + 1][0] = sc.nextInt();
					p[n + 1][1] = sc.nextInt();
				}
			}
			
			answer = 20000;
			visited[0] = true;
			go(0, 1, 0);
			
			System.out.println("#" + test_case + " " + answer);
		}
	}
}
