package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution{
	static int[][] map;
	static int N, M;
	static boolean[][] cleared;
	static int curX, curY;
	static int curDir;
	static int area;
	//북, 동, 남, 서
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	
	public static void clean() {
		cleared[curX][curY] = true;
		area++;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		//지도 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		cleared = new boolean[N][M];
		//현위치, 현방향 입력
		st = new StringTokenizer(br.readLine());
		curX = Integer.parseInt(st.nextToken());
		curY = Integer.parseInt(st.nextToken());
		curDir = Integer.parseInt(st.nextToken());
		//지도 내용 입력
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		//현위치 청소하고 시작.
		clean();
		int nextDir;
		int ni, nj;
		int d;
		boolean end = false;
		while(!end) {
			//네 방향 확인
			for(d=0; d<4; d++) {
				//현재 위치에서 왼 쪽 확인.
				nextDir = (curDir + 3) % 4;
				ni = curX + di[nextDir];
				nj = curY + dj[nextDir];
				//빈 공간 && 청소 안함
				if(map[ni][nj] == 0 && !cleared[ni][nj]) {
					curDir = nextDir;
					curX = ni;
					curY = nj;
					clean();
					break;
				}
				//빈 공간 && 청소함 || 벽임
				else {
					curDir = nextDir;
					continue;
				}
			}
			//네 방향 모두 청소 || 벽
			if(d == 4) {
				ni= curX + di[(curDir+2)%4];
				nj = curY + dj[(curDir+2)%4];
				//한 칸 불가능
				if(map[ni][nj] == 1){
					end = true;
					break;
				}
				//후진 가능.
				curX = ni;
				curY = nj;
			}
		}
		
		
		//정답 출력
		System.out.println(area);
		
	}
}