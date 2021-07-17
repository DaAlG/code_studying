package ahah;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main{
	static int R, C;
	static String res;
	
	public static void scanPuzzle(char[][] arr) {
		int row = arr.length;
		String[] words;
		
		for(int r=0; r<row; r++) {
			String str = String.valueOf(arr[r]);
//			#기준으로 파싱
			words = str.split("#");
//			사전순으로 제일 앞선 단어 찾기
//			#######인 경우 예외처리
			int wSize = words.length;
			if(wSize != 0) {
				Arrays.sort(words);
				int idx = 0;
//				한글자인 경우 예외 처리
				while(idx != wSize && words[idx].length() < 2)
					idx++;
				if(idx == wSize)
					continue;
				res = res.compareTo(words[idx]) > 0 ? words[idx] : res;
			}
			
		}
	}
	
	public static void main(String[] args) throws Exception{
		char[][] puzzle1, puzzle2;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		res = "zzzzzzzzzzzzzzzzzzzz";
		
		puzzle1 = new char[R][C];
		puzzle2 = new char[C][R];
		for(int i=0; i<R; i++) {
			String str = br.readLine();
			for(int j=0; j<C; j++) {
				puzzle1[i][j] = str.charAt(j);
				puzzle2[j][i] = puzzle1[i][j];
			}
				
		}
		
//		가로 스캔, 세로 스캔
		scanPuzzle(puzzle1);
		scanPuzzle(puzzle2);
		System.out.println(res);
	}
}