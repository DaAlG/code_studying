import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 1600 말이 되고픈 원숭이
public class Main_1600 {
	static int K, W, H;
	static int[][] map;

	// visit 관리 항목 y, x, 말이동 횟수 
	// 같은 y, x 이라도 말이동 횟수 남은 것에 따라 의미가 다를 수 있다.    
	static boolean[][][] visit;

	// 하, 우, 상, 좌
	static int[] dy = { 1, 0, -1,  0 };
	static int[] dx = { 0, 1,  0, -1 };

	static int[] hdy = { 1,  1, -2, -2, -1, -1, 2,  2 };
	static int[] hdx = { 2, -2,  1, -1,  2, -2, 1, -1 };

	static Queue<Node> queue = new LinkedList<Node>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		K = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		
		map = new int[H][W];
		visit = new boolean[H][W][K+1]; //k=1~k
		// 입력
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		Node n = new Node(0,0,K,0);
		queue.offer(n);
		
		bfs();
	}
	
	private static void bfs() {
		while(!queue.isEmpty()) {
			Node node = queue.poll();
			
			// 목표 도달 확인
			if(node.y == H-1 && node.x == W-1) {
				System.out.println(node.d);
				return;
			}
			
			// 상하좌우 탐색
			for (int i = 0; i < 4; i++) {
				int ny = node.y + dy[i];
				int nx = node.x + dx[i];
				// 범위 벗어나는 경우, 장애물인 경우, 꺼낸 애의 k값으로 온 애가 왔으면 갈 필요가 없다.(똑같은 횟수로 이미 왔다면)
				if( ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx]==1 || visit[ny][nx][node.k]) continue;
				visit[ny][nx][node.k] = true;
				queue.offer(new Node(ny, nx, node.k, node.d+1));
			}
			
			// node.k > 0인지 확인. 말 탐색을 할 기회가 남아있으면~
			if(node.k == 0) continue; // 말탐색 ㄴㄴ
			
			// 말 탐색 (조건 : node.k > 0)
			for (int i = 0; i < 8; i++) {
				int ny = node.y + hdy[i];
				int nx = node.x + hdx[i];
				// 범위 벗어나는 경우, 장애물인 경우, 내가 앞으로 갈 곳인 nynx의 k-1번째 방문을 이미 햇다면 
				if( ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx]==1 || visit[ny][nx][node.k-1]) continue;
				visit[ny][nx][node.k-1] = true;
				queue.offer(new Node(ny, nx, node.k-1, node.d+1));
			}
			
		}
		
		System.out.println(-1);
	
	}

	static class Node{
		int y, x, k, d; // k: 말처럼 뛸 수 있는 남은 횟수, d: depth(원숭이가 총 몇 번째 뛰는지)
		public Node(int y, int x, int k, int d) {
			this.y = y;
			this.x = x;
			this.k = k;
			this.d = d;
		}
	}

}
