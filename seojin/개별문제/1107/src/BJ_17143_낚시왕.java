import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class BJ_17143_낚시왕 {

	static int R, C, M; // RxC, 상어의 수
	static Map<Integer, Shark> sharklist = new HashMap<>(); // 번호 - 상어
	static int[][] fishMap;
	static int res; // 잡은 상어의 수
	
	static int[] dy = {0,-1,1,0,0}; // 위 아래
	static int[] dx = {0, 0,0,1,-1}; // 오 왼
	
	public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken()); // 상어의 수
        
        fishMap = new int[R+1][C+1];
        
        for (int i = 1; i <= M; i++) {
        	st = new StringTokenizer(br.readLine());
        	int r = Integer.parseInt(st.nextToken());
        	int c = Integer.parseInt(st.nextToken());
        	int s = Integer.parseInt(st.nextToken()); // 속력
        	int d = Integer.parseInt(st.nextToken()); // 이동방향
        	int z = Integer.parseInt(st.nextToken()); // 크기
        	
        	sharklist.put(i, new Shark(r, c, s, d, z));
			fishMap[r][c] = i; // (r,c) i번 상어 배치
		}
        
        // 낚시꾼 이동 가능한 열 => C개
        for (int i = 1; i <= C; i++) {
            if(M == 0) {
            	System.out.println(0);
            	return;
            }
        	// 1. 오른쪽 한 칸 이동
			// 2. 그 열에서 땅과 가장 가까운 상어 잡기 => 상어가 사라짐
//        	print();
        	fishing(i);
        	// 3. 상어의 이동
//        	print();
        	moveShark();
		}
        
        System.out.println(res);
	}
	
	private static void print() {
		 for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				System.out.printf("%2d", fishMap[i][j]);
			}
			System.out.println();
		}
		 System.out.println();
	}

	private static void moveShark() {
		
		int[][] movefishMap = new int[R+1][C+1];
		List<Integer> removeList = new ArrayList<>();
		
		Iterator<Integer> iter = sharklist.keySet().iterator();
		while(iter.hasNext()) {
			int key = iter.next();
			Shark cur = sharklist.get(key);
			int d = cur.d;
			int r = cur.r;
			int c = cur.c;
			int n = 0;
			
			switch(d) {
				case 1:
				case 2:
					n = cur.s%(R*2-2); // 2*R-2=>자기 자신으로 돌아옴
					for(int k=0; k<n; k++) {
						if(r == 1) {
							d = 2; // 상 -> 하
						}
						else if(r == R) {
							d = 1; // 하-> 상
						}
						r += dy[d];
					}
					
					cur.d = d;
					cur.r = r;
					break;
				case 3:
				case 4:
					n = cur.s%(C*2-2); // 2*R-2=>자기 자신으로 돌아옴
					for(int k=0; k<n; k++) {
						if(c == 1) {
							d = 3; // 왼 => 오
						}
						else if(c == C) {
							d = 4; // 오 => 왼
						}
						c += dx[d];
					}
					
					cur.d = d;
					cur.c = c;
					break;
			}
			
			// map 수정
			sharklist.replace(key, cur);
			
			// movefishMap에 현 위치 넣기!
			r = cur.r;
			c = cur.c;
			int originKey = movefishMap[r][c];
			if( originKey == 0) movefishMap[r][c] = key; // 아무것도 없다면 그냥 넣기
			else if( sharklist.get(originKey).z < cur.z) { // 들어잇는 상어의 크기가 현재 상어 크기보다 작다면
				movefishMap[r][c] = key; // 내가 자리 차지!
				removeList.add(originKey); // 들어있던 상어가 잡아먹힘
			}else { // 원래 있는 상어가 더 크다면
				removeList.add(key); // 현재 상어가 잡아먹힘
			}
		}
		for(int r : removeList) {
			sharklist.remove(r);
			M--;
		}
		
		 for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				fishMap[i][j] = movefishMap[i][j];
			}
		}
		
	}

	private static void fishing(int c) {

		// 상어 잡기!
		for(int i=1; i<=R; i++) {
			if(fishMap[i][c] > 0) {
				res += sharklist.get(fishMap[i][c]).z; // 낚시 성공!
				sharklist.remove(fishMap[i][c]); // 삭제
				fishMap[i][c] = 0; // 삭제
				M--;
				break;
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
