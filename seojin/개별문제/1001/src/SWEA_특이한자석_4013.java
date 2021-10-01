import java.io.*;
import java.util.*;

public class SWEA_특이한자석_4013 {

	static int T, K;
	static int[][] arr; // 톱니바퀴 정보 저장
	static int[] dir; // 각 톱니바퀴의 현재 방향 정보
	static boolean[] visit; // 방문 처리
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		T = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= T; t++) {
			// 입력 처리
			K = Integer.parseInt(br.readLine()); // 회전시키려는 톱니바퀴의 수
			
			arr = new int[4+1][8]; 
			for (int i = 1; i <= 4; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 8; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			// 시뮬레이션
			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				
				int num = Integer.parseInt(st.nextToken()); // 돌릴 바퀴 번호
				int d = Integer.parseInt(st.nextToken()); // 회전 방향
				
				// 초기화
				dir = new int[4+1];
				visit = new boolean[4+1];
				
				// 돌릴 바퀴 찾기
				find(num, d);
				// 회전
				rotate();
			}
			
			int ans = arr[1][0] + arr[2][0] * 2 + arr[3][0] * 4 + arr[4][0] * 8;

			System.out.println("#"+t+" "+ans);
		}
	}

	static void rotate() {
		
		for (int i = 1; i <= 4; i++) {
			
			if(dir[i] == 0) continue; // 회전이 없었다면
			else if(dir[i] == 1) {
				
				// 시계방향으로 회전하였다면
				int temp = arr[i][7]; 
				for (int j = 7; j > 0; j--) {
					arr[i][j] = arr[i][j-1];
				}
				arr[i][0] = temp;
				
			}else {
				
				// 반시계방향으로 회전하였다면
				int temp = arr[i][0]; 
				for (int j = 0; j < 7; j++) {
					arr[i][j] = arr[i][j+1];
				}
				arr[i][7] = temp;
				
			}
		}
	}

	static void find(int num, int d) {

		Queue<Wheel> info = new LinkedList<>();
		info.offer(new Wheel(num, d));
		visit[num] = true;
		dir[num] = d;
		
		while(!info.isEmpty()) {
			
			Wheel w = info.poll();
			int curNum = w.num;
			int curDir = w.d;
			
			if(w.num-1>=1) {
				// 왼쪽 탐색
				int nextNum = w.num-1; 
				
				// 내 6번과 왼쪽 2번이 다르다면 회전
				if(arr[curNum][6] != arr[nextNum][2] && !visit[nextNum]) {
					info.add(new Wheel(nextNum, curDir*-1));
					dir[nextNum] = curDir*-1;
					visit[nextNum] = true;
				}

			}
			if(w.num+1<=4) {
				// 오른쪽 탐색
				int nextNum = w.num + 1; 
				
				// 내 2번과 오른쪽 6번이 다르다면 회전
				if(arr[curNum][2] != arr[nextNum][6] && !visit[nextNum]) {
					info.add(new Wheel(nextNum, curDir*-1));
					dir[nextNum] = curDir*-1;
					visit[nextNum] = true;
				}
			}
			
		}
	}

	static class Wheel{
		int num, d;
		
		public Wheel(int num, int d) {
			this.num = num;
			this.d = d;
		}
	}
}
