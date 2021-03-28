package test;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

//K의 범위를 이진탐색으로 찾는다.
//치료 범위가 N-M 보다 같거나 크면 그때 최솟값(K)을 찾아 업데이트 한다.
class Solution {
	static int maxCoreCnt;
	static int shortLength;
	static int N;
	static char[][] circuit;
	static ArrayList<Point> cores;
	static int[] di = {-1, 1, 0, 0};
	static int[] dj = {0, 0, -1, 1};

	static class Point{
		int x;
		int y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	//해당 방향으로 전선 깔기 ㄱㄴ?
	public static boolean isAvailable(Point core, int dir) {
		
		Point curPos = new Point(core.x+di[dir], core.y+dj[dir]);
		while(curPos.x >= 0 && curPos.x < N && curPos.y < N && curPos.y >= 0) {
			//다른 전선이 있거나 코어가 있으면 안된다.
			if(circuit[curPos.x][curPos.y] != '0') {
				return false;
			}
			curPos.x += di[dir];
			curPos.y += dj[dir];
		}
		
		return true;
	}
	
	//core에서부터 해당 방향으로 state 설정
	public static void setWire(Point core, int dir, char state) {
		Point curPos = new Point(core.x+di[dir], core.y+dj[dir]);
		while(curPos.x >= 0 && curPos.x < N && curPos.y < N && curPos.y >= 0) {
			circuit[curPos.x][curPos.y] = state;
			curPos.x += di[dir];
			curPos.y += dj[dir];
		}
	}
	
	public static int getLength() {
		int len = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(circuit[i][j] == '2')
					len++;
			}
		}
		return len;
	}
	
	//cnt번째 core를 연결(이 때 전선 방향도 다름)할까 말가..
	public static void subset(int cnt, int coreCnt) {
		//기저
		if(cnt == cores.size()) {
			//코어 개수가 최대인지, 전선 개수 최소인지 확인
			int curLength = getLength();
			if(coreCnt > maxCoreCnt) {
				maxCoreCnt = coreCnt;
				shortLength = curLength;
			}
			else if(coreCnt == maxCoreCnt) {
				if(curLength < shortLength)
					shortLength = curLength;
			}
			return;
		}
		//반복
		for(int k=0; k<4; k++) {
			//연결
			if(isAvailable(cores.get(cnt),k)) {
				//전선 깔기
				setWire(cores.get(cnt), k ,'2');
				subset(cnt+1, coreCnt+1);
				//전선 취소 -> 다른 방향을 노린다.
				setWire(cores.get(cnt), k, '0');
			}
		}
		//비연결 -> 가능한 방향이 없거나, 네 방향 다 시도하고 전선 지움.
		subset(cnt+1, coreCnt);
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder("");
		
		for(int t=1; t<=T; t++) {
			//테케마다 초기화: N, 최소 전선 길이, 연결된 코어 수.
			maxCoreCnt = -1;
			shortLength = Integer.MAX_VALUE;
			N = Integer.parseInt(br.readLine());
			circuit = new char[N][N];
			cores = new ArrayList<Point>();
			//회로 입력
			for(int i=0; i<N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=0;j <N; j++) {
					circuit[i][j] = st.nextToken().charAt(0);
					if(circuit[i][j] =='1' && i != 0 && j !=0 && i != N-1 && j != N-1)
						cores.add(new Point(i,j));
				}
			}
			
			//코어 부분집합으로 연결 or 비연결
			subset(0,0);
			
			//출력
			sb.append("#").append(t).append(" ").append(shortLength).append("\n");
		}
		System.out.println(sb);
	}

}
