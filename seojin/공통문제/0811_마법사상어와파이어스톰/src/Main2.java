import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		// 맵 크기
		int N = (int) Math.pow(2, Integer.parseInt(stt.nextToken()));
		// 시전 횟수
		int Q = Integer.parseInt(stt.nextToken());

		int[][] map = new int[N][N];
		for(int i = 0; i < N; i++) {
			stt = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(stt.nextToken());
			}
		} 
		
		// 시전 단계
		int[] L = new int[Q];
		stt = new StringTokenizer(br.readLine());
		for(int i = 0; i < Q; i++) {
			L[i] = (int) Math.pow(2, Integer.parseInt(stt.nextToken()));
		} // input end
		
		process(N, Q, map, L);
		
		// 녹인 얼음을 기준으로 덩어리를 찾자!
		int[] res = findLump(map, N);
		
		System.out.println(res[0]);
		System.out.println(res[1]);
	}

	private static void process(int n, int q, int[][] map, int[] l) {
		// q번 반복
		for(int i = 0; i < q; i++) {
			// L 크기 만큼 90도 배열 돌리기
			int level = l[i];
			rotate(map, level, n, 0, 0);
			
			// 얼음을 녹이자!
			meltIce(map, n);
		}
	}
	
	private static int[] findLump(int[][] map, int n) {
		int[] dy = {-1, 1, 0, 0};
		int[] dx = {0, 0, -1, 1};
		boolean[][] visited = new boolean[n][n];
		int sum = 0;
		int lump = 0;
		int max_lump = 0;
		
		// BFS로 덩어리를 찾고, 모든 얼음을 더한다.
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				sum += map[i][j];
				if(map[i][j] == 0) continue;
				if(visited[i][j]) continue;
				Queue<int[]> ice_queue = new LinkedList<int[]>();
				ice_queue.offer(new int[] {i, j});
				visited[i][j] = true;
				lump = 0;
				
				while(!ice_queue.isEmpty()) {
					int[] cur_ice = ice_queue.poll();
					int y = cur_ice[0];
					int x = cur_ice[1];
					lump++;
					
					for(int d = 0; d < 4; d++) {
						int next_y = y + dy[d];
						int next_x = x + dx[d];
						
						if(rangeCheck(next_y, next_x, n)) continue;
						if(map[next_y][next_x] == 0) continue;
						if(visited[next_y][next_x]) continue;
						ice_queue.offer(new int[] {next_y, next_x});
						visited[next_y][next_x] = true;
					}
				} // while end
				// 가장 큰 덩어리 갱신
				max_lump = max_lump > lump ? max_lump : lump;
			} // for j end
		} // for i end
		int[] res = {sum, max_lump};
		return res;
	}

	// 주위 4방향을 봤는데 얼음이 없다면 녹인다.
	private static void meltIce(int[][] map, int n) {
		int[] dy = {-1, 1, 0, 0};
		int[] dx = {0, 0, -1, 1};
		List<int[]> list = new LinkedList<int[]>();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] == 0) continue;
				
				// 주위 4방향 얼음 확인
				int ice_cnt = 4;
				for(int d = 0; d < 4; d++) {
					int next_y = i + dy[d];
					int next_x = j + dx[d];
					if(rangeCheck(next_y, next_x, n)) {
						ice_cnt--;
						continue;
					}
					if(map[next_y][next_x] == 0) {
						ice_cnt--;
						continue;
					}
				}
				// 녹일 위치 저장
				if(ice_cnt <= 2) {
					list.add(new int[] {i, j});
				}
			}
		} // for i end
		
		// 해당 위치의 얼음을 녹인다.
		for(int[] position: list) {
			int y = position[0];
			int x = position[1];
			if(map[y][x] > 0) {
				map[y][x]--;
			}
		}
	}

	// 밤위 체크
	private static boolean rangeCheck(int next_y, int next_x, int n) {
		return next_y < 0 || next_y >= n || next_x < 0 || next_x >= n;
	}
	
	private static void rotate(int[][] map, int l, int n, int y, int x) {
		if(n == l) { // 현재 N이 L과 같다면
			int[][] init_map = new int[n][n];
			int idx_y = 0; // init_map y 인덱스
			for(int i = y; i < n+y; i++) {
				int idx_x = 0; // init_map x 인덱스
				for(int j = x; j < n+x; j++) {
					init_map[idx_y][idx_x++] = map[i][j];
				}
				idx_y++;
			}
			
			// 90도 회전
			idx_y = 0;
			for(int i = y; i < n+y; i++) {
				int idx_x = 0;
				for(int j = x; j < n+x; j++) {
					map[i][j] = init_map[n-1-idx_x++][idx_y];
				}
				idx_y++;
			}
			
			return ;
		}
		
		// 총 4부분으로 나누어짐
		rotate(map, l, n/2, y, x); // 왼쪽위
		rotate(map, l, n/2, y, x+n/2); // 오른족 위
		rotate(map, l, n/2, y+n/2, x); // 왼쪽 아래
		rotate(map, l, n/2, y+n/2, x+n/2); // 오른족 아래
	}
}