//백준 1992 쿼드트리

import java.io.*;
import java.util.*;

public class Main_1992 {

	static int N;
	static char[][] video;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		video = new char[N][];
		for (int i = 0; i < N; i++) {
			video[i] = br.readLine().toCharArray();
		}
		
		compress(0,0,N);
		
		System.out.println(sb.toString());
	}
	
	static void compress(int y, int x, int n) {
		if( n < 1 ) return;
		
		if(check(y,x,n)) { // 모두 같은 수라면! 압축 
			sb.append(video[y][x]);
			return;
		}
		
		int dividen = n/2;
		sb.append('(');
		compress(y,x,dividen); // 1영역 확인
		compress(y,x+dividen,dividen); // 2영역 확인
		compress(y+dividen,x,dividen); // 3영역 확인
		compress(y+dividen,x+dividen,dividen); // 4영역 확인
		sb.append(')');
		
	}

	static boolean check(int y, int x, int n) {
		// 영역의 제일 왼쪽 위 애를 기준으로 모두 같은 값을 가지는 지 확인
		char temp = video[y][x];
		
		for (int i = y; i < y+n; i++) {
			for (int j = x; j < x+n; j++) {
				if(video[i][j] != temp) return false; // 다르다. 압축 불가!
			}
		}
		
		return true; // 모두 같다!
	}
}

	
