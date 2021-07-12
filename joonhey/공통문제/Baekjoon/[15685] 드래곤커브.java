import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
	static boolean[][] map;
	static class Point{
		int x;
		int y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public boolean equals(Point p) {
			return p.x == this.x && p.y == this.y;
		}
	}
	static Point startingPoint, standardPoint; //드래곤 커브의 시작점을 변환시킨 점이 결국 기준점이 된다.
	//맨 처음 방향 설정.
	static int[] di;
	static int[] dj;
	static Queue<Point> queue;
	static int generation;
	
	//기준점 기준으로 originPoint를 시계반대방향으로 변환한다.
	public static Point getCurvedPoint(Point originPoint) {
		int xDistance = originPoint.x - standardPoint.x;
		int yDistance = originPoint.y - standardPoint.y;
		return new Point(standardPoint.x + (-1)*yDistance, standardPoint.y + xDistance);
	}
	
	public static int countSquares() {
		int sum = 0;
		boolean left, right; //왼쪽 두 점 , 오른쪽 두 점.
		for(int y=0; y <= 999; y++) {
			left = map[0][y] && map[0][y+1];
			for(int x=1; x<=1000; x++) {
				right = map[x][y] && map[x][y+1];
				sum += left && right ? 1 : 0;
				left = right;
			}
		}
		return sum;
	}
	
	public static void move() {
		Point newStandard = null;
		
		while (generation-- > 0 ) {
			//세대별 무빙
			int qSize = queue.size();
			for(int i=0; i<qSize; i++) {
				Point curPoint = queue.poll();
				queue.offer(curPoint);
				//시작점?
				if(curPoint.equals(startingPoint)) {
//					변환한 것도 넣기 -> 기준점이 되도록
					newStandard =  getCurvedPoint(curPoint);
					map[newStandard.x][newStandard.y] = true; 
					queue.offer(newStandard); 
				}
				//기준점은 변환 x
//				기준점도 아니고 시작점도 아님 -> 본인도 offer, 변환점도 offer
				else if(!curPoint.equals(standardPoint)) {
					Point transformed = getCurvedPoint(curPoint);
					map[transformed.x][transformed.y] = true;
					queue.offer(transformed);
					
				}
			}
			//기준점이 바뀌어있음.
			standardPoint = newStandard;
			
		}
	}

	public static void main(String[] args) throws Exception{
//		우상좌하
		di = new int[] {0,-1,0,1};
		dj = new int[] {1,0,-1,0};
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		map = new boolean[1001][1001];
		
		for(int i=0; i<M; i++) {
			queue = new LinkedList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			//x y d g
			startingPoint = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			map[startingPoint.x][startingPoint.y] = true;

			int d = Integer.parseInt(st.nextToken());
			generation = Integer.parseInt(st.nextToken());
			//0세대 드래곤커브.
			queue.offer(startingPoint);
			standardPoint =new Point(startingPoint.x + dj[d], startingPoint.y + di[d]); 
			map[standardPoint.x][standardPoint.y] = true;
			queue.offer(standardPoint);
			move();
		}
		System.out.println(countSquares());
	}
}