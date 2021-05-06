import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	static int[][] box;
	static int M, N; //가로 세로
	static int redTomato; //익은 토마토
	static int totalTomato; //전체토마토
	static class Point{
		int x;
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static int cnt; //소요된 시간(정답)
	static Queue<Point> queue; //방문 기록
	//상하좌우 이동.
	static int[] di = {-1,1,0,0};
	static int[] dj = {0,0,-1,1};
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		box = new int[N][M];
		queue = new LinkedList<>();
		//칸 입력
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				box[i][j] = Integer.parseInt(st.nextToken());
//				System.out.print("box[i][j] "+box[i][j]);
				if(box[i][j] == 0)//안익은 토마토
					totalTomato++;
				else if(box[i][j] == 1) { //익은토마토
					totalTomato++;
					redTomato++;
					//익은 토마토 먼저 넣기
					queue.offer(new Point(i,j));
				}
			}
//			System.out.println();
		}
		//이동할 곳이 없거나 다 익으면 텨나온다.
		int ni, nj;
		while(!queue.isEmpty() && redTomato != totalTomato) {
			//하루 카운트.
			int qSize = queue.size();
			for(int i=0; i<qSize; i++) {
				Point cur = queue.poll();
				for(int d=0; d<4; d++) {
					ni = cur.x + di[d];
					nj = cur.y + dj[d];
					//범위 내에 있고 안익은 토마토면 방문(방문 체크 필요  x : 방문했을 경우는 익은 토마토일 경우이므로 이 경우 제외시킴, 빈칸은 갈수 없으므로 제외.)
					if(ni >=0 && ni < N && nj >=0 && nj < M && box[ni][nj] == 0) {
						queue.offer(new Point(ni, nj));
//						System.out.println("익음 "+ni+" "+nj);
						redTomato++;
						box[ni][nj] = 1;
					}
				}
			}
			//하루 경과.
			cnt++;
		}
		//만약 갈 곳이 없어서 나온거면 cnt++ 전에 이미 탐색을 끝마쳤으므로 하루를 빼 줘야 함.
//		if(queue.isEmpty())
//			cnt--;
		//정답 출력.
//		System.out.println("총토마토 "+totalTomato+" 익은고 "+redTomato);
		cnt = totalTomato != redTomato ? -1 : cnt;
		System.out.println(cnt);
		
	}
}