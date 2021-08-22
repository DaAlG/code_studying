
import java.io.*;
import java.util.*;

public class Main_3109{

	static int R,C;
	static char[][] map;
	static int[] dy = {-1,0,1};
	static int[] dx = {1,1,1};
	static int ans = 0;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][];
		for(int i=0;i<R;i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		// 탐색
		for(int i=0; i<R; i++) {
			if(connect(i,0)) ans++;
		}
		System.out.println(ans);
	}
	
	static boolean connect(int i, int j) {
		if(j == C-1) {
			// 마지막 열에 도달 == 빵집 도착
			return true;
		}
		
		for(int k=0; k<3; k++) {
			int ny = i + dy[k];
			int nx = j + dx[k];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue; // 범위 벗어남
			if(map[ny][nx] == 'x') continue; // 건물이라 갈 수 없음
			
			map[ny][nx] = 'x'; // 방문했으니 지나가지 못하도록 하기!
			if(connect(ny, nx)) return true;
		}
		return false;
	}
}

