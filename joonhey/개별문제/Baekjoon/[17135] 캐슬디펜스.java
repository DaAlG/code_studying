package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Main{
	static int N, M, D;
	static int[][] map;
	static class Point{
		int x;
		int y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static ArrayList<Point> archers;
	static ArrayList<Point> willKilled;
	static int enemyCnt;
	static int maxKilled;
	
	public static void defenceCastle() {
		//완성된 궁수 조합으로 적 다 죽거나, 성에 침입할 때까지.
		int cnt = 0; //현재 처리된 애들
		int curKilled = 0; //이 조합으로 죽은 애들
		int[][] board = deepCopy();
		
		while(cnt != enemyCnt) { // 한 턴 -> 적은 계속 다가오고..
			//턴 돌때마다 죽는 사람 바뀜
			willKilled = new ArrayList<>();
			for(Point archer : archers) {
				//가까운 거리부터 탐색
				boolean foundEnemy = false;
				for(int dist=1; dist<=D; dist++) {
					//거리 좁은것 > 열 적은거 > 나머지 행
					for(int col =0; col<M; col++) {
						int colDist = Math.abs(archer.y - col);
						if(colDist > dist)
							continue;
						int rowDist = dist - colDist;
						int upRow = N- rowDist; //무족건 위임. ㄴㄴ col이 바뀌니까 천차만별임...
						//범위 내인 경우만 죽이고 다음 궁수로 넘어가즈아
						if(upRow >= 0 && upRow < N && board[upRow][col] == 1) {
							foundEnemy = true;
							willKilled.add(new Point(upRow, col));
							break;
							
						}
					}
					if(foundEnemy) //이미 죽엿으니 더 올라갈 필요 X
						break;
				}
				
			} //궁수 세명 턴 끝나면 죽은 사람 업데이트 & 칸 이동.
			
			//세 명 다 못죽였을 수도 있음.
			for(Point curEnemy : willKilled) {
				int enemy = board[curEnemy.x][curEnemy.y];
				cnt += enemy;
				curKilled += enemy;
				board[curEnemy.x][curEnemy.y]= 0; //중복 죽은거 방지.
			}
			
			//맨 끝행부터 처리. 뒤진애들 이미 제외.
			for(int j=0; j<M; j++)
				cnt += board[N-1][j];
			//그 밑에 이동
			for(int i=N-1; i>=1; i--) {
				for(int j=0; j<M; j++) {
					board[i][j] = board[i-1][j];
				}
			}
			//맨 첫칸은 빈공간
			for(int j=0; j<M; j++) {
				board[0][j] = 0;
			}
		}
		
		//최대 적의 수 업데이트
		if(curKilled > maxKilled)
			maxKilled = curKilled;
	
	}
	
	public static int[][] deepCopy(){
		int[][] board = new int[N][M];
		for(int i=0;i<N; i++) {
			for(int j=0; j<M; j++)
				board[i][j] = map[i][j];
		}
		return board;
	}
	
	//0~M-1 중에 세 자리 뽑능거
	public static void combArcher(int cnt, int target) {
		if(cnt == 3) {
			//궁수 다 뽑았고 게임 시작
			defenceCastle();
			return;
		}
		if(target == M) { //0~M-1
			return;
		}
		
		//선
		archers.add(new Point(N, target));
		combArcher(cnt+1, target+1);
		//비선
		archers.remove(cnt);
		combArcher(cnt, target+1);
		
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); 
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				int curEnemy = Integer.parseInt(st.nextToken());
				enemyCnt += curEnemy;
				map[i][j] = curEnemy;
			}
		}
		archers = new ArrayList<>();
		combArcher(0,0);
		System.out.println(maxKilled);
	}
}