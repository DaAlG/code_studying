// 백준 2567 - 색종이2
import java.io.*;
import java.util.*;

public class Main_2567 {

	static int N, sum = 0;
	static boolean[][] paper = new boolean[101][101];
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	static int ans;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		for(int t=0;t<N;t++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			for(int i = a; i<a+10; i++) { // 색종이 가로세로 길이 10
				for(int j=b; j<b+10; j++) {
					if(paper[i][j]) continue;
					paper[i][j] = true;
				}
			}
		}
		
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if(paper[i][j]) { // 색종이가 있는 위치라면
					findRound(i,j); // 그 위치에서 구할 수 있는 둘레 계산하기
				}
			}
		}
		
		System.out.println(ans);
	}
	
	static void findRound(int i, int j) {
		
		for (int k = 0; k < 4; k++) {
			int ny = i + dy[k];
			int nx = j + dx[k];
			
			if(ny<0 || ny>=101 || nx<0 ||nx>=101) continue;
			if(!paper[ny][nx]) ans++; // 주위에 비어있는 개수만큼 둘레길이가 됨
		}
	}

}
