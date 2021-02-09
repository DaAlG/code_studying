package day0203;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int res;
	static int N,M;
	static int[][] wall;// = new int[15][15];
	
	//특정 영역의 파리 수 리턴
	public static int countFlies(int startX, int startY) {
		int sum = 0;
		for(int i=startX; i<startX+M; i++) {
			for(int j=startY; j<startY+M; j++) {
				sum += wall[i][j];
			}
		}
		return sum;
	}
	
	//최대 파리 수 리턴 -> 큰 사각형에서.
	public static int catchFlies() {
		int startX, startY; // 각 정사각형의 시작점
		int maxFlies = 0;
		int flyCnt;
		
		startX = 0;
		while (startX + M != N + 1) {
			startY = 0;
			while (startY + M != N + 1) {
				flyCnt = countFlies(startX, startY);
				if ( flyCnt > maxFlies)
					maxFlies = flyCnt;
				startY++;
			}
			startX++;
		}
		return maxFlies;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t=0; t<T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			wall = new int[N][N];
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<N; j++) {
					wall[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			res = catchFlies();
			//출력
			System.out.println("#"+(t+1)+" "+res);
		}
	}
}
