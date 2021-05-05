import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution{
	
	static boolean found;
	static char[][] map;
	static boolean[][][] visited;
	static int res;
	static int N, M;
	static int[] di = {-1,1,0,0};
	static int[] dj = {0,0,-1,1};
	
	static class Point{
		int x;
		int y;
		int z;
		
		public Point(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
	static Queue<Point> queue;
	
	public static void main(String[] args) throws IOException{
		queue = new LinkedList<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new char[N][M];
		visited = new boolean[N][M][2];
		String inputLine;
		for(int i = 0; i<N; i++) {
			inputLine = br.readLine();
			for(int j=0; j<M; j++) {
				map[i][j]=inputLine.charAt(j);
			}
		}
		queue.offer(new Point(0,0,0));
		int dist;	
		int ni, nj;
		//ù ����� �湮 ����.
		while(!queue.isEmpty()) {
			res++; //�湮Ƚ�� ����.
			dist = queue.size();
//			���� ����� �ֵ� ����.
			for(int i=0; i<dist; i++) {
				Point curPoint = queue.poll();
//				���� ���� ��� �ٷ� out
				if(curPoint.x == N-1 && curPoint.y == M-1) {
					found = true;
					break;
				}
//				���Ž�� & offer
				for(int d=0; d<4; d++) {
					ni = curPoint.x + di[d];
					nj = curPoint.y + dj[d];
//					���� ���� ���.
					if(ni >= 0 && ni < N && nj >= 0 && nj < M) {
//						���� �� -> �μ� �� �ֳ� Ȯ�� -> �湮 Ȯ�� �� �湮.
						if(map[ni][nj] == '1' && curPoint.z == 0 && !visited[ni][nj][1]) {
							visited[ni][nj][1] = true;
							queue.offer(new Point(ni, nj, 1));
						}
//						���� �ƴ� �� -> �湮 Ȯ�� �� �湮.(z�� �״��.)
						else if(map[ni][nj] == '0' && !visited[ni][nj][curPoint.z]){
							visited[ni][nj][curPoint.z]= true;
							queue.offer(new Point(ni,nj,curPoint.z));
						}
					}
				}
				
			}
//			���� ���� ��� ������.
			if(found)
				break;
		}
		if(found)
			System.out.println(res);
		else
			System.out.println("-1");
	}
}