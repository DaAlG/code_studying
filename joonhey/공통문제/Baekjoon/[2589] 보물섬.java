import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	
	static int N, M;
	static char[][] map;
	static int res; //정답 -> 최장거리중 최댓값.
	
	static class Point{
		int x;
		int y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static boolean[][] visited; //경우의 수 때마다 방문 체크
	static int[] di, dj; //상하좌우.
	static Queue<Point> queue; //bfs용.
	
	public static void bfs(int startX, int startY) {
		int dist = 0;
		
		while(!queue.isEmpty()) {
//			거리가 같은 것끼리 한번에 for문 -> 거리 계산 위함.
			int qSize = queue.size();
			dist++;
			for(int q = 0; q<qSize; q++) {
				Point cur = queue.poll();
//				현재 위치 기준 사방탐색
				for(int d=0; d<4; d++) {
					int ni, nj;
					ni = cur.x + di[d];
					nj = cur.y + dj[d];
//					visited로 출발점에서의 최단거리임을 보장하고,
//					dist로 최단거리 중 최장거리를 찾는다.
//					System.out.println("ni "+ni);
//					System.out.println("nj "+nj);
					
					if(ni >=0 && ni < N && nj >=0 && nj < M && map[ni][nj] == 'L' && !visited[ni][nj]) {

						visited[ni][nj] = true;
						queue.add(new Point(ni, nj));
					}
				}
			}
			
		}
		dist--;
//		큐가 빌때까지 이동 -> dist가 계속해서 증가했으므로 마지막 dist가 곧 출발지에서의 최장거리가 됨.
		if(res < dist) //이 출발지에서의 최장거리가 모든 출발지에서의 최장거리보다 긺 ? 
			res = dist;
		
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
//		0. 전역변수 초기화 
		map = new char[N][M];
		
		queue = new LinkedList<>();
		di = new int[] {-1,1,0,0};
		dj = new int[] {0,0,-1,1};
		
//		1. 지도값 입력 -> map이랑 minDist도 초기화.
		for(int i=0; i<N; i++) {
			char[] inputLine = br.readLine().toCharArray();
			int j= 0 ;
			for(char c : inputLine) {
				map[i][j++] = c;
			}
		}
//		2. map 순회하면서 최단경로 & res 업데이트
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
//				육지일 때만 출발 ㄱㄴ
				if(map[i][j] == 'L') {
					visited = new boolean[N][M]; //방문 체크 초기화 필요.
					visited[i][j] = true;
					queue.add(new Point(i, j));
					bfs(i,j);
				}
			}
		}
//		3. 정답 출력
		System.out.println(res);
		
		
		
	}
}