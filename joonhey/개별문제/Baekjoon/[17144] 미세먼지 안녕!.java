package test;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int R, C;
	static int[][] map;
	static int T;
//	공기청정기
	static int filterUp_x;
	static int filterUp_y;
	static int filterDown_x;
	static int filterDown_y;
// 추가 미세먼지 ( 곳곳에서 누적한 후 내 꺼 확산시킨 다음 더할 것들)
	static int[][] plus;
	static int[] di = { -1, 1, 0, 0 };
	static int[] dj = { 0, 0, -1, 1 };

	//위쪽 필터 -> 반시계 방향.
	public static void counterclockFilter() {
		int i, j;
		int before, tmp;
		//시작점.
		i = filterUp_x;
		j = 2;
		//덮어씌여지기 전에 저장.
		before = map[i][1];
		map[i][1] = 0; // 정화댐.
		while(true) {
			//끝까지 옴.
			if(j == C) {
				j--;
				i--;
				//맨 위에 공기청정기가 있을 때
				if(i < 0)
					return;
			}
			else if(i  == -1) {
				i++;
				j--;
			}
			else if(j == -1) {
				i++; j++;
			}
			//공기청정기까지 순회.
			if(i == filterUp_x && j == filterUp_y)
				return;
			
			//덮어씌여지기 전에 저장.
			tmp = map[i][j];
			map[i][j] = before;
			before = tmp;
			if(i == filterUp_x)
				j++;
			else if(j == C-1 )
				i--;
			else if(i == 0 )
				j--;
			else if(j == 0 )
				i++;
		}
	}
	//아래쪽 필터 -> 시계 방향.
	public static void clockFilter() {
		int i, j;
		int before, tmp;
		//시작점.
		i = filterDown_x;
		j = 2;
		//덮어씌여지기 전에 저장.
		before = map[i][1];
		map[i][1] = 0; // 정화댐.
		while(true) {
			//끝까지 옴.
			if(j == C) {
				j--;
				i++;
				//맨 아래에 공기청정기가 있을 때
				if(i ==R )
					return;
			}
			else if(i  == R) {
				i--;
				j--;
			}
			else if(j == -1) {
				i--; j++;
			}
			//공기청정기까지 순회.
			if(i == filterDown_x && j == filterDown_y)
				return;
			
			//덮어씌여지기 전에 저장.
			tmp = map[i][j];
			map[i][j] = before;
			before = tmp;
			if(i == filterDown_x)
				j++;
			else if(j == C-1 )
				i++;
			else if(i == R-1 )
				j--;
			else if(j == 0 )
				i--;
		}
	}
	
	public static void main(String[] args) throws Exception {
		filterUp_x = -1; // 초기화 되지 않았음을 표시. 위에 있는 청정기가 먼저 나올 것임.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		map = new int[R][C];
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				// 공기청정기 위치 입력
				if (map[i][j] == -1) {
					// 위에 있는 거.
					if (filterUp_x == -1) {
						filterUp_x = i;
					} else {
						filterDown_x = i;
					}
				}
			}
		}
		// T초간 진행.
		int ni, nj;
		for (int t = 0; t < T; t++) {
			// 확산 될 때마다 더해질 가치 다름
			plus = new int[R][C];
			// 1. 미.먼 확산
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					// 미먼이 있을 경우만 확산
					if (map[i][j] > 0) {
						int spreadCnt = 0;
						for (int d = 0; d < 4; d++) {
							ni = i + di[d];
							nj = j + dj[d];
							// 범위내이고 공기청정기가 없을 경우 확산
							if (ni >= 0 && ni < R && nj >= 0 && nj < C && map[ni][nj] != -1) {
								plus[ni][nj] += map[i][j] / 5;
//								확산횟수 카운트
								spreadCnt++;
							}
						}
						// 나의 값 감소.
						map[i][j] -= map[i][j] / 5 * spreadCnt;
					}
				}
			}
			// 더할 값 더해주긔
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					map[i][j] += plus[i][j];
				}
			}
			// 2. 공기청정기 가동
			counterclockFilter();
			clockFilter();
		}
		// 3. T초 경과 후 미세먼지 양 계산. 출력.
		int res = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				res += map[i][j];
			}
		}
		//공기청정기 -1이니까
		System.out.println(res + 2);
	}
}
