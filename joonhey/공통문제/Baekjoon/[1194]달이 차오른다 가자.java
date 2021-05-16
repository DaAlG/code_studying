import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N, M;
	static char[][] miro;
	static boolean[][][] visit;
	static int result = 0;

	static class Dot{
		int x;
		int y;
		int key;
		
		Dot(int x, int y, int key){
			this.x = x;
			this.y = y;
			this.key = key;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		sc.nextLine();
		
		Dot start = null;
		miro = new char[N][M];
		String[] s = new String[N];
		visit = new boolean[N][M][1 << 6]; // 2의 6승을 만들어준다. 
		
		for(int i = 0; i < N; i++) {
			s = sc.nextLine().split("");
			for(int j = 0; j < M; j++) {
				miro[i][j] = s[j].charAt(0);
				if(miro[i][j] == '0') { // 민식이 위치
					start = new Dot(i, j, 0);
				}
			}
			
		}
		
		result = solution(start);
		System.out.println(result);
		sc.close();
	}

	// 하 상 우 좌 
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	private static int solution(Dot start) {
		Queue<Dot> q = new LinkedList<Dot>();
		q.add(start);
		// peek : 가장 앞쪽에 위치한 값을 리턴해준다. 삭제X (가장 먼저 나갈 아이)
		visit[q.peek().x][q.peek().y][0] = true;

		int time = 0;
		while(!q.isEmpty()) {
			int size = q.size();
			for(int qsize = 0; qsize < size; qsize++) {
				// poll : 가장 앞쪽 위치한 값 리턴 및 q에서 삭제 
				Dot t = q.poll()	; 
				int curX = t.x;
				int curY = t.y;
				int curKey = t.key;
				
				if(miro[curX][curY] == '1') {
					return time;
				} // 기저사례 
				
				// 이동 : 상하좌우 가능 
				for(int i = 0; i < 4; i++) {
					int nextX = curX + dx[i];
					int nextY = curY + dy[i];
					int key = curKey;
					
					// 장외 
					if(nextX >= N || nextY >= M || nextX < 0 || nextY < 0) {
						continue;
					}
                    
					// 벽 발견 
					if(miro[nextX][nextY] == '#') {
						continue;
					}
                    
					// 키 발견 
					if('a' <= miro[nextX][nextY] && miro[nextX][nextY] <= 'f') {
						key |= (1 << miro[nextX][nextY] - 'a');
					}
					
					// 문 발견 
					if('A' <= miro[nextX][nextY] && miro[nextX][nextY] <= 'F') {
						if((key & (1 << (miro[nextX][nextY] - 'A'))) == 0) { // 키를 가지고 있지 않다면 
							continue;
						}
					}
					
					// 방문 이전에 했다면 패스 
					if(visit[nextX][nextY][key]) {
						continue;
					}
					
					visit[nextX][nextY][key] = true;
					q.add(new Dot(nextX,nextY, key)); 
					
				}
			}
			time++;
		}
		return -1;
		
	}

}