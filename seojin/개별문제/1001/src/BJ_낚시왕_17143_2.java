import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BJ_낚시왕_17143_2 {

	static int R, C, M, sum;
	static Shark[][] mapA, mapB;
	//static ArrayList<Shark> list = new ArrayList<Shark>();
	// 상-하-우-좌 순서 고려
	static int[] dy = { -1, 1, 0, 0 }; // 0,1,2,3 <= 1,2,3,4,
	static int[] dx = {  0, 0, 1,-1 };
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		mapA = new Shark[R+1][C+1];
		mapB = new Shark[R+1][C+1];
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			
			Shark shark = new Shark(r,c,s,d-1,z); // d-1
			//list.add(shark);
			mapA[r][c] = shark;
		}

		// 시뮬레이션
		for (int i = 1; i <= C; i++) {
			catchShark(i);
			moveShark(i);
		}
		
		System.out.println(sum);
	}

	// map 에서 작업
	static void catchShark(int col) {
		Shark[][] from = col % 2 == 1 ? mapA : mapB;
		for (int i = 1; i <= R; i++) {
			if( from[i][col] != null ) {
				sum += from[i][col].z;
				//list.remove(from[i][col]);
				from[i][col] = null;
				break;
			}
		}
	}
	// list 에서 작업
	static void moveShark(int col) {
		Shark[][] from = col % 2 == 1 ? mapA : mapB;
		Shark[][] to = col % 2 == 1 ? mapB : mapA;
		
		// to 초기화
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				to[i][j] = null;
			}
		}
			
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				
				if( from[i][j] != null ) {
					
					int r = from[i][j].r;
					int c = from[i][j].c;
					int s = from[i][j].s;
					int d = from[i][j].d;
					
					switch(d) {
						case 0: // 상하
						case 1:
							s = s%(R*2 -2);
							for (int k = 0; k < s; k++) {
								if( r == 1 ) d = 1; // 상->하 d: delta index
								else if( r == R ) d = 0; // 하->상  
								r += dy[d];
							}
							from[i][j].d = d;
							from[i][j].r = r;
							if( to[r][c] == null || to[r][c].z < from[i][j].z ) to[r][c] = from[i][j];
							break;
							
						case 2: // 좌우
						case 3:
							s = s%(C*2 -2);
							for (int k = 0; k < s; k++) {
								if( c == 1 ) d = 2; // 왼->오 d: delta index
								else if( c == C ) d = 3; // 오 -> 왼
								c += dx[d];
							}
							from[i][j].d = d;
							from[i][j].c = c;
							if( to[r][c] == null || to[r][c].z < from[i][j].z ) to[r][c] = from[i][j];
							break;
					}
				}
				
			}
		}
	}
	
	static class Shark{
		int r, c, s, d, z;
		public Shark(int r, int c, int s, int d, int z) {
			this.r = r;
			this.c = c;
			this.s = s;
			this.d = d;
			this.z = z;
		}
	}
}




