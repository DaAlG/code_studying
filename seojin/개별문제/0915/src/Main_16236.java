import java.io.*;
import java.util.*;

// 16236 아기상어

public class Main_16236 {
	
	static int N; // 공간 크기
	static int[][] arr; // 공간의 상태
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	
	// 상어의 상태
	static Shark s;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		
		arr = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 9) {
					// 아기상어의 위치 저장
					s = new Shark(i,j);
					arr[i][j] = 0; // 비워 주기
				}
			}
		}
		
		// 몇 초 동안 먹이사냥하는지
		int result = 0;
		// 먹은 물고기 수
		int eat = 0; 
		while(true) {
			int[][] d = bfs();
			Fish f = eat(d);
			
			if(f.isNone) {
				System.out.println(result);
				break;
			}else {
				// 물고기의 위치로 상어 옮겨가기
				s.y = f.y;
				s.x = f.x;
				result += f.mindist; // 움직이는 칸 수만큼 초 더하기!
				arr[f.y][f.x] = 0; // 물고기 먹은 것으로 처리!!
				eat ++; // 먹은 물고기 수 증가
				
				// 상어 크기만큼 물고기 먹었다면 -> 커지기
				if(eat >= s.size) {
					s.size++;
					eat = 0;
				}
			}
		}

	}
	
	// 먹을 수 있는 물고기 찾기, 비우기, 업데이트
	static Fish eat(int[][] d) {
		// 제일 가까운 물고기 먹기
		int min_dist = Integer.MAX_VALUE;
		Fish fish = new Fish(0, 0);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
				// 상어가 갈 수 있으면서, 먹을 수 있는 물고기 일 때
				if(d[i][j]!=-1 && arr[i][j]>=1 && arr[i][j]<s.size) {
					
					if(min_dist > d[i][j]) {  // 가장 위,왼쪽 우선..하게 됨. 순서대로 탐색하니까!
						min_dist = d[i][j];
						fish.y = i;
						fish.x = j;
					}
				}
			}
		}
		
		fish.mindist = min_dist;
		if(min_dist == Integer.MAX_VALUE) fish.isNone = true;
		return fish;
	}
	
	// 상어의 현재 위치에서 먹을 수 있는 물고기들까지의 거리 반환
	static int[][] bfs() {
		int[][] dist = new int[N][N];
		for (int i = 0; i < N; i++) {
			Arrays.fill(dist[i], -1);
		}
		
		Queue<Shark> q = new LinkedList<>();
		q.add(s); // 상어의 상태 
		dist[s.y][s.x] = 0;
		
		while(!q.isEmpty()) {
			Shark now = q.poll();
			
			for (int i = 0; i < 4; i++) { // 상하좌우
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				
				if(ny<0 || nx<0 || ny>=N || nx>=N) continue; // 범위 벗어났을 때
				if(now.size < arr[ny][nx]) continue; // 나보다 크기가 큰 물고기가 있다면
				if(dist[ny][nx]>-1) continue; // 이미 거리를 확인했다면
				
				dist[ny][nx] = dist[now.y][now.x]+1; 
				
				q.add(new Shark(ny,nx, now.size));
			}
		}
		return dist;
	}
	
	static class Shark{
		int y;
		int x;
		int size = 2;
		
		public Shark(int y, int x) {
			this.y = y;
			this.x = x;
		}
		
		public Shark(int y, int x, int size) {
			this.y = y;
			this.x = x;
			this.size = size;
		}
	}
	
	static class Fish{
		int y;
		int x;
		int mindist;
		boolean isNone = false; // 못 찾았을 때
		
		public Fish(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
