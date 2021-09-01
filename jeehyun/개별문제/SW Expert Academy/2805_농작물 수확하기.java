import java.util.Scanner;

// SWEA 2805 농작물 수확하기
class Solution {
	private static int[] dx = { 1, 1, -1, -1 };
	private static int[] dy = { 1, -1, -1, 1 };
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)	{
			int n = sc.nextInt();
			
			int[][] farm = new int[n][n];
			for (int i = 0; i < n; i++) {
				String tmp = sc.next();
				for (int j = 0; j < n; j++) {
					farm[i][j] = tmp.charAt(j) - '0';
				}
			}
			
			int x = 0;
			int y = n / 2;
			int dir = 0;
			int sum = 0;
			
			boolean[][] visited = new boolean[n][n];
			while (true) {
				visited[x][y] = true;
				sum += farm[x][y];
				
				// 마름모의 정중앙에 도착하면 종료
				if (x == n / 2 && y == n / 2) break;
				
				x += dx[dir];
				y += dy[dir];
				
				// 가로세로의 중간일 경우 방향 바꾼다
				if (x == n / 2 || y == n / 2) { 
					dir = (dir + 1) % 4;
					if (visited[x][y]) { // 이미 방문했으면 한 칸 위로
						x++;
					}
				}
			}
			
			System.out.println("#" + test_case + " " + sum);
		}
	}
}
