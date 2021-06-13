import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	static class Point{
		int x; int y;
		public Point(int x, int y) {
			this.x = x;
			this.y  = y;
		}
	}
	
	static int N, M;
	static int[][] map;
	static int[] di;
	static int[] dj;
	static Queue<Point> queue;
	static ArrayList<Point> chickenZone; //치킨 위치 모아둚.
	static int originThinZone, curThinZone, maxThinZone;
	static boolean[][] visited;
	
	
//	치킨 냄새 확장
	public static void bfsChicken() {
		int ni, nj;
		while(!queue.isEmpty()) {
			Point cur = queue.poll();
			for(int d=0; d<4; d++) {
				ni = cur.x + di[d];
				nj = cur.y + dj[d];
				if(ni >= 0 && ni < N && nj >=0 && nj < M && !visited[ni][nj] && map[ni][nj] == 0) {
					visited[ni][nj]  = true;
					queue.offer(new Point(ni, nj));
//					map[ni][nj] = 2; 어차피 visited 됐으니까 재방문 안함
					curThinZone--;
				}
			}
		}
		
	}
	
//	치킨 위치별로 확장 시직
	public static void spreadChicken() {
		
		visited = new boolean [N][M];
		for(Point chicken : chickenZone) {
			queue.offer(new Point(chicken.x, chicken.y));
			visited[chicken.x][chicken.y]= true; 
		}
		
		curThinZone = originThinZone;
		bfsChicken();
		
//		날씬이존 넓이 구하기
		if(curThinZone > maxThinZone)
			maxThinZone = curThinZone;
	}
	
//	탈취제 위치 정하기
	public static void pickPosition(int x, int y, int cnt) {
//		기저조건
		if(cnt == 3) {
			spreadChicken();
			return;
		}
		if(x == N) //칸 끝까지 옴.
			return;
		
		int ni, nj;
//		다음칸 확인.
		if(y + 1 == M) {
			ni = x + 1;
			nj = 0;
		}
		else {
			ni = x;
			nj = y + 1;
		}

		//		선택 ㄱㄴ한지 확인하고 선택: 0인 칸에만 가능.
		if(map[x][y] == 0) {
			map[x][y] = 1;
			pickPosition(ni, nj, cnt + 1);
			map[x][y] = 0; //선택 취소.
			pickPosition(ni, nj, cnt);
		}
		else {
			pickPosition(ni, nj, cnt);
		}
		
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		queue = new LinkedList<>();
		di = new int[] {-1,1,0,0};
		dj = new int[] {0,0,-1,1};

		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder("");
		
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			map = new int[N][M];
			chickenZone = new ArrayList<>();
			maxThinZone=0; originThinZone = -3;
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<M; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if(map[i][j] == 2)
						chickenZone.add(new Point(i, j));
					else if(map[i][j] == 0)
						originThinZone++;
				}
			}
//			탈취제를 놓을 칸 정하기
			pickPosition(0,0,0);
			sb.append("#").append(t).append(" ").append(maxThinZone).append("\n");
		}
		
		System.out.println(sb);
	}
}