package ahah;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main{
	static int N, M, k;
	static class Point{
		int x;
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
//	상어의 번호, 상어의 현 위치 기록.
	static class Shark implements Comparable<Shark>{
		Point position;
		int num;
		int head; //바라보고 있는 방향.
		public Shark(Point p, int n) {
			this.position = p;
			this.num = n;
		}
//		맨 처음에 번호순으로 리스트 소팅하기 위해서.
		@Override
		public int compareTo(Shark o) {
			return this.num - o.num;
		}
		
		@Override
		public String toString() {
			return "position "+position.x+", "+position.y +" num "+num+" , head: "+head;
			
		}
	}
//	상어 위치 리스트.
	static LinkedList<Shark> sharks;
//	상어 냄새
	static class Smell{
		int smell;
		int time;
//		자신의 냄새 뿌릴 때.
		public Smell(int s, int t) {
			this.smell = s;
			this.time = t;
		}
		@Override
		public String toString() {
			return "smell "+smell+", "+" time: "+time;
			
		}
	}
//	냄새 맵에 기록
	static Smell[][] map;
//	현재시간
	static int cnt;
//	방위
	static int[] di;
	static int[] dj;
//	상어별 이동 우선순위: 상어번호 - 현재 방향 - 우선순위.
	static int[][][] priority;
//	그때 그때 이동한 상어가 연결리스트에 줄줄이 달림 -> 동시에 같은 위치로 오는지 확인.
	static LinkedList<Shark>[][] temp;
	
//	현재 상어 위치 기준으로 냄새가 없는 곳 탐색
	public static int noSmellArea(Shark shark) {
		int ni, nj;
		
		for(int d : priority[shark.num][shark.head]) {
			ni = shark.position.x + di[d];
			nj = shark.position.y + dj[d];
			if(ni >= 0 && ni < N && nj >= 0 && nj < N) {
//				냄새가 있던 적이 없거나, 있어도 사라졌거나.
				if(map[ni][nj].smell == M || cnt - map[ni][nj].time >= k) {
					return d;
				}
			}
		}
//		냄새가 없는 곳이 없음.
		return 4;
		
	}
	
//	자신의 냄새가 있는 곳 찾기.
	public static int mySmellArea(Shark shark) {
		int ni, nj;
		
		for(int d : priority[shark.num][shark.head]) {
			ni = shark.position.x + di[d];
			nj = shark.position.y + dj[d];
			if(ni >= 0 && ni < N && nj >= 0 && nj < N) {
//				현존하는 자신의 냄새 찾기 -> 냄새가 사라진 경우는 위에서 걸러냈음
				if(map[ni][nj].smell == shark.num) {
					return d;
				}
			}
		}
//		자신의 냄새 못찾음.
		return 4;
	}
	
//	상어들 이동.
	public static void moveSharks() {
		int direction;
		
		for(Shark curShark : sharks) {
//			우선순위별로 다음 위치 탐색
//			1. 냄새가 없는 곳
			direction = noSmellArea(curShark);
			if (direction != 4) {
//				예상 위치 업데이트
				curShark.position.x += di[direction];
				curShark.position.y += dj[direction];
				curShark.head = direction;
//				System.out.println("x"+curShark.position.x);
//				System.out.println("y"+curShark.position.y);
				temp[curShark.position.x][curShark.position.y].add(curShark);
				continue;
			}
//			2. 자신의 냄새가 있는 곳 
			else {
				direction = mySmellArea(curShark);
//				예상 위치 업데이트
				if(direction != 4) {
					curShark.position.x += di[direction];
					curShark.position.y += dj[direction];
					curShark.head = direction;
					temp[curShark.position.x][curShark.position.y].add(curShark);
				}
//				다 막혀 있으면 그냥 그대로 있긔.
				else
					temp[curShark.position.x][curShark.position.y].add(curShark); 
			}
			
		}
//		상어의 위치 확정 -> 겹치는 위치에 있는 것들은 하나만 남기고, 
//		위치 업데이트.
		updatePosition();
		
	}
	
//	겹치는 위치는 한 마리만 남기고, 냄새 업데이트 한다.
	public static void updatePosition() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				int len = temp[i][j].size();
				if(len == 0)
					continue;
				Shark shark = temp[i][j].poll();
//				냄새, 상어 위치 업데이트
				map[i][j].smell = shark.num;
				map[i][j].time = cnt+1;
				if(len != 1) {
//					나머지 애들은 아예 삭제 함.
					while(!temp[i][j].isEmpty()) {
						sharks.remove(temp[i][j].poll());
					}
				}
			}
		}
	}
	
	public static void initialTemp() {
		temp = new LinkedList[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				temp[i][j] = new LinkedList<Shark>();
			}
		}
	}
	
	public static void printShark() {
		System.out.println(cnt+"현재 상어 상태.");
		for(Shark s : sharks) {
			System.out.println(s);
		}
	}
	public static void printMap() {
		System.out.println(cnt+" 현재 맵 상태.");
		for(int i = 0; i<N; i++) {
			for(int j=0; j<N; j++) {
				System.out.print(map[i][j]+" ");
			}
			System.out.println();
		}
	}
 	public static void main(String[] args) throws Exception{
// 		상하좌우.
 		di = new int[] {-1,1,0,0};
 		dj = new int[] {0,0,-1,1};
 		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
//		배열 공간 할당
		priority = new int[M][4][4];
		sharks = new LinkedList<>();
		map = new Smell[N][N];
		
//		맵 스캔 -> 어느 위치에 몇번 상어가 있는지.
//		맵에 시간, 냄새 뿌리고 -> (-1 해서 넣는 것 유념!)
//		sharks에 상어 정보 담는다. 
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				int now = Integer.parseInt(st.nextToken());
				map[i][j] = new Smell(M,0);
				if(now-- != 0) { // 0 ~ M-1번으로 메핑.
					//상어가 있다 ! -> 상어 목록에 추가, 냄새도 추가.
					sharks.add(new Shark(new Point(i, j), now));
					map[i][j].smell = now;
				}
			}
		}
		
//		상어 번호 순으로 소팅하기. (이 다음에 우선순위 순으로 이동하기 위함.)
		Collections.sort(sharks);
		
//		상어 현재 방위 입력 -> 1234 -> 0123으로 바꿔야 함.
		st = new StringTokenizer(br.readLine());
		for(Shark s : sharks)
			s.head = Integer.parseInt(st.nextToken()) - 1;
//		상어들의 방위별 우선순위 입력
		for(int s = 0; s < M; s++) {
//			머리 위치 별 우선 순위.
			for(int h = 0; h<4; h++) {
				st = new StringTokenizer(br.readLine());
				for(int d=0; d<4;d++) {
					priority[s][h][d] = Integer.parseInt(st.nextToken())-1;
				}
			}
		}
		
		
//		1번 상어만 남을 때 까지, 혹은 1000초 동안 이동스.
		while(sharks.size() != 1 && cnt != 1000) {
//			상어 상태 출력
//			printShark();
//			냄새 상태 출력
//			printMap();
			initialTemp(); //임시 위치 저장소.
			moveSharks();
			cnt++;
		}
		
//		1000초가 넘어도 남아있으면 -1 출력
		cnt = sharks.size() == 1 ? cnt : -1;
		System.out.println(cnt);
	}
}