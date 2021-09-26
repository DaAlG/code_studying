import java.util.*;
import java.io.*;

// 7576 토마토
public class Main_7576 {

	static int M, N;
	static int[][] tomato;
	static Queue<Node> queue = new LinkedList<>();
	static int zerocnt, res = 0;
	
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine().trim());
		
		// 입력
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		tomato = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int j = 0; j < M; j++) {
				tomato[i][j] = Integer.parseInt(st.nextToken());
				// 익은 토마토(1) 있으면 queue에 넣기
				if(tomato[i][j] == 1) queue.add(new Node(i,j,0));
				// 0의 개수 세기
				else if (tomato[i][j] == 0) zerocnt ++;
			}
		}

		
		// 0의 개수가 0이라면 0 출력하고 끝
		if(zerocnt == 0) {
			System.out.println(0);
			return;
		}
		// bfs
		while(!queue.isEmpty()) {
			Node now = queue.poll();
			if(res < now.day) res = now.day;
			
			for (int i = 0; i < 4; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				
				// 범위체크, -1인지 체크(없는 곳)
				if(ny>=0 && nx>=0 && ny<N && nx<M && tomato[ny][nx]==0) {
					// map update, queue에 넣기
					tomato[ny][nx] = now.day+1;
					queue.add(new Node(ny, nx, now.day+1));
					// 0의 개수 --
					zerocnt--;
				}

			}
		}
		// bfs이후 0의 개수가 0보다 크다면 -1 출력
		if(zerocnt > 0) System.out.println(-1);
		else System.out.println(res);
		
	}

	static class Node{
		int y;
		int x;
		int day;
		
		public Node(int y, int x, int day) {
			super();
			this.y = y;
			this.x = x;
			this.day = day;
		}
	}
}
