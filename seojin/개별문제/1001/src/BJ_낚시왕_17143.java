import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BJ_낚시왕_17143 {

	static int R, C, M, sum;
	static Shark[][] map;
	static ArrayList<Shark> list = new ArrayList<Shark>();
	// 상-하-우-좌 순서 고려
	static int[] dy = { -1, 1, 0, 0 }; // 0,1,2,3 <= 1,2,3,4,
	static int[] dx = {  0, 0, 1,-1 };
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new Shark[R+1][C+1];
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			
			Shark shark = new Shark(r,c,s,d-1,z); // d-1
			list.add(shark);
			map[r][c] = shark;
		}

		// 시뮬레이션
		for (int i = 1; i <= C; i++) {
			catchShark(i);
			moveShark();
			killShark();
		}
		
		System.out.println(sum);
	}

	// map 에서 작업
	static void catchShark(int col) {
		for (int i = 1; i <= R; i++) {
			if( map[i][col] != null ) {
				sum += map[i][col].z;
				list.remove(map[i][col]);
				// map[i][col] = null; // 없어도 됨
				break;
			}
		}
	}
	// list 에서 작업
	static void moveShark() {
		for (Shark shark : list) {
			int r = shark.r;
			int c = shark.c;
			int s = shark.s;
			int d = shark.d;
			
			switch(d) {
			case 0: // 상하
			case 1:
				s = s%(R*2 -2);
				for (int i = 0; i < s; i++) {
					if( r == 1 ) d = 1; // 상->하 d: delta index
					else if( r == R ) d = 0; // 하->상  
					r += dy[d];
				}
				shark.d = d;
				shark.r = r;
				break;
				
			case 2: // 좌우
			case 3:
				s = s%(C*2 -2);
				for (int i = 0; i < s; i++) {
					if( c == 1 ) d = 2; // 왼->오 d: delta index
					else if( c == C ) d = 3; // 오 -> 왼
					c += dx[d];
				}
				shark.d = d;
				shark.c = c;
				break;
			}
			
		}
	}
	
	static void killShark() {
		// map 초기화
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				map[i][j] = null;
			}
		}
		
		// list -> map
		int size = list.size();
		for (int i = size-1; i >= 0; i--) { // 뒤에서 부터
			Shark s = list.get(i);
			if( map[s.r][s.c] == null ) {
				map[s.r][s.c] = s;
			}else {
				if( s.z > map[s.r][s.c].z ) {
					list.remove(map[s.r][s.c]);
					map[s.r][s.c] = s;
				}else {
					list.remove(s);
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




