import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 2636 치즈

public class Main_2636 {

	static int H, W, hour, cheese;
	static int[][] map;
	static boolean[][] visitAir;
	static boolean[][] visitCheese;
	
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	
	static Queue<Node> queueAir = new LinkedList<>();
	static Queue<Node> queueCheese = new LinkedList<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=  new StringTokenizer(br.readLine());
		
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		
		map = new int[H][W];
		visitAir = new boolean[H][W];
		visitCheese = new boolean[H][W];
		
		// 입력 처리
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				
			}
		}
		
		// 초기화
		visitAir[0][0] = true;
		queueAir.offer(new Node(0,0));
		
		while(true) {
			
			// 공기와 닿은 치즈를 공기를 모두 탐색하면서 visit 고려해서 찾는다.
			bfsAir();
			// 만약 더 이상의 치즈가 없으면 종료한다. 
			if(queueCheese.isEmpty()) break;
			// 공기와 닿은 치즈를 모두 공기로 변경한다.
			bfsCheese();
			
			hour++;
		}
		
		System.out.println(hour);
		System.out.println(cheese);
		
	}
	
	static void bfsAir() {
		while(!queueAir.isEmpty()) {
			Node n= queueAir.poll(); // 공기에 대한 정보가 순차적으로 들어있고,그걸 pop!
			
			for (int i = 0; i < 4; i++) {
				int ny = n.y + dy[i];
				int nx = n.x + dx[i];
				
				if(ny<0 || nx<0 || ny>=H || nx>=W || visitAir[ny][nx]) continue;
				
				// 새로운 공기
				if(map[ny][nx] == 0) { // 공기와 공기 맞닿아있다면
					visitAir[ny][nx] = true;
					queueAir.offer(new Node(ny, nx));
					continue;
				}
				
				// 치즈
				if(map[ny][nx] == 1) { // 공기와 맞닿아 있는 치즈라면
					if(visitCheese[ny][nx]) continue;
					visitCheese[ny][nx] = true;
					queueCheese.offer(new Node(ny, nx)); // 경계면에 있는 치즈
				}
			}
			
		}
	}
	
	static void bfsCheese() {
		cheese = 0;
		while(!queueCheese.isEmpty()) {
			Node n = queueCheese.poll();
			// map[n.y][n.x] = 0; // 치즈-> 공기
			visitAir[n.y][n.x] = true;
			queueAir.offer(n);
			cheese++;
		}
	}
	
	static class Node{
		int y;
		int x;
		public Node(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

}
