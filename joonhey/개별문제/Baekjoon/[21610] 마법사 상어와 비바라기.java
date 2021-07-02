package project;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main{
	static int[] di;
	static int[] dj;
	static int[][] water;
	static int N;
	static class Point{
		int x;
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static boolean[][] moved; // 구름이 이동한 위치 -> 구름 생성 시 참고, 매번 clear
	static Queue<Point> cloud; //새로 생성된 구름의 위치
	static int d,s;//현재 이동 방향 및 속력
	
//	음수 ->양수
	public static int minusToplus(int num) {
		while(num < 0)
			num += N;
		return num;
	}
//	모든 구름이 di, si만큼 이동한다
	public static void moveCloud() {
		//x, y 방향으로 이만큼 이동해야 함
		int moveX = di[d] * s;
//		해당방향으로 이동하려고 했는 데 음수 값이 나온 경우 -> 양수로 바꾸고 다음에 범위가 넘어간다면 %로 처리
		moveX = moveX < 0 ?  minusToplus(moveX) : moveX;
		
		int moveY = dj[d] * s;
		moveY = moveY < 0 ? minusToplus(moveY) : moveY;
		
		int ni, nj;
		
		while(!cloud.isEmpty()) {
			Point curCloud = cloud.poll();
			ni = (curCloud.x + moveX ) % N;
			nj = (curCloud.y + moveY ) % N;
//			구름에서 비가 내림
			water[ni][nj]++;
//			구름이 사라짐
			moved[ni][nj] = true;
		}
	}
	
	public static void waterCopyBug() {
		int ni, nj;
//		대각선 : 2,4,6,8
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(moved[i][j]) {
					int cnt = 0; //대각선 방향으로 인접한 바구니의 개수
					for(int d = 2; d <=8; d+=2) {
						ni =i + di[d];
						nj = j + dj[d];
//						경계 넘어가면 x
						if(ni >=0 && ni < N && nj >=0 && nj < N && water[ni][nj] != 0) {
							cnt++;
						}
					}
					water[i][j] += cnt;
				}
			}
		}

	}
	
	public static void makeCloud() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(water[i][j] >= 2 && !moved[i][j]) {
					cloud.offer(new Point(i, j));
					water[i][j] -= 2;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
//		변수 생성 및 초기화
		di = new int[] {0,0,-1,-1,-1,0,1,1,1};
		dj = new int[] {0,-1,-1,0,1,1,1,0,-1};
		int M;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		water = new int[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				water[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		cloud = new LinkedList<>();
//		비바라기 시전
		cloud.offer(new Point(N-1, 0));
		cloud.offer(new Point(N-1, 1));
		cloud.offer(new Point(N-2, 0));
		cloud.offer(new Point(N-2, 1));

		//		이동 명령
		for(int i=0; i<M; i++) {
			moved = new boolean[N][N];
			st = new StringTokenizer(br.readLine());
			d = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
//			구름이 모두 di, si 이동
			moveCloud();
//			물복사 버그 마법
			waterCopyBug();
//			구름이 생기기 시작
			makeCloud();
			
		}
//		물의 양 총합
		int res = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				res += water[i][j];
			}
		}
		System.out.println(res);
	}
}