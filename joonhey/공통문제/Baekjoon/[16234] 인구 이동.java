import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	
	static int[][] earth;
	static int N, L, R;
//	BFS 용
	static class Point{
		int x; int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static Queue<Point> queue;
	static boolean[][] visited;
	static int[] di, dj;
//	[연합순번] => 연합 목록
	static LinkedList<Point>[] unitInfo;
//	[연합순번] => 연합 인구
	static int[] unitPopulation;
//	연합 인덱스
	static int unitIdx;
	
//	i, j 기준으로 국경 열기 - 연합 별 나라, 인구 총 합 저장
	public static void openBFS(int startX, int startY) {
		
//		연합 정보 설정
		unitPopulation[unitIdx] = earth[startX][startY];
		unitInfo[unitIdx].offer(new Point(startX, startY));

//		BFS 탐색 시작
		visited[startX][startY] = true;
		queue.offer(new Point(startX, startY));
		
		int ni, nj, diff;
		
		while(!queue.isEmpty()) {
			Point curNation = queue.poll();
			for(int d= 0; d<4; d++) {
				ni = curNation.x + di[d];
				nj = curNation.y + dj[d];
				if(ni >= 0 && nj >= 0 && ni < N && nj < N && !visited[ni][nj]) {
					diff = Math.abs(earth[curNation.x][curNation.y] - earth[ni][nj]);
//					연합국 추가쓰
					if(diff >= L && diff <= R) {
						unitPopulation[unitIdx] += earth[ni][nj];
						unitInfo[unitIdx].offer(new Point(ni, nj));
						visited[ni][nj] = true;
						queue.offer(new Point(ni, nj));
					}
				}
			}
		}
		
	}
	
	public static void sharePeople() {
//		연합국 별로 인구를 같게 만듦
		int curPeople;
		Point curPoint;
		
		for(int i=0; i<unitIdx; i++) {
			curPeople = unitPopulation[i] / unitInfo[i].size();
			while(!unitInfo[i].isEmpty()) {
				curPoint = unitInfo[i].poll();
				earth[curPoint.x][curPoint.y]= curPeople; 
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
//		객체 생성, 초기화
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		earth = new int[N][N];
		queue = new LinkedList<>();
		unitInfo = new LinkedList[N*N];
		di = new int[] {-1,1,0,0};
		dj = new int[] {0,0,-1,1};
		for(int i=0; i<N*N; i++)
			unitInfo[i] = new LinkedList<>();
		unitPopulation = new int[N*N];
		
//		입력받기
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				earth[i][j] = Integer.parseInt(st.nextToken());
			}
		}
//		이중 탐색->국경선 열기
		int res = 0;
		int ni, nj;
		int diff;
		
		while(true) {
//			새로 탐색하면서 국경선 열고 인구 이동 시작
			unitIdx = 0;
			visited = new boolean[N][N];
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(!visited[i][j]) {
//						L 이상 R 이하 차이나는 인접국 있나 확인
						for(int d=0; d<4; d++) {
							ni = i + di[d];
							nj = j + dj[d];
							if(ni >= 0 && ni < N && nj >= 0 && nj < N && !visited[ni][nj] ) {
								diff = Math.abs(earth[i][j] - earth[ni][nj]);
//								[i][j] 기준으로 국경선 열어야 함
								if(diff >= L && diff <= R) {
									openBFS(i, j);
//									연합 국 하나 건설 완료
									unitIdx++;
									break;
								}
							}
						}
					}
				}
			}
			
			
//		연합을 맺은 게 아무것도 없으면 인구 이동을 종료한다.
			if(unitIdx == 0)
				break;
//			인구 이동
			sharePeople();
			
			res++;
		}
		
		System.out.println(res);
	}
}