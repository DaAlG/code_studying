import java.io.*;
import java.util.*;

public class Main_1706 {
	static int R, C;
	static char[][] puzzle;
	
	public static void main(String[] args) throws Exception {
		
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb;
		List<String> word = new ArrayList<>();
		
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		puzzle = new char[R][];
		for(int i=0; i<R; i++) {
			puzzle[i] = br.readLine().toCharArray();
		}
		
		// 가로의 경우
		for (int i = 0; i < R; i++) {
			sb = new StringBuilder();
			int cnt = 0;
			for (int j = 0; j < C; j++) {
				// # 을 만났을 때
				if(puzzle[i][j] == '#') {
					if(cnt>=2) word.add(sb.toString()); // 단어이면 리스트에 넣기
					sb.setLength(0);
					cnt = 0;
					continue;
				}
				sb.append(puzzle[i][j]);
				cnt++;
				
			}
			// 체크
			if(cnt>=2) word.add(sb.toString()); // 단어이면 리스트에 넣기
			sb.setLength(0);
			cnt = 0;

		}
		
		// 세로의 경우
		for (int j = 0; j < C; j++) {
			sb = new StringBuilder();
			int cnt = 0;
			for (int i = 0; i < R; i++) {
				// # 을 만났을 때
				if(puzzle[i][j] == '#') {
					if(cnt>=2) word.add(sb.toString()); // 단어이면 리스트에 넣기
					sb.setLength(0);
					cnt = 0;
					continue;
				}
				sb.append(puzzle[i][j]);
				cnt++;
				
			}
			// 체크
			if(cnt>=2) word.add(sb.toString()); // 단어이면 리스트에 넣기
			sb.setLength(0);
			cnt = 0;

		}
		
		// 사전순 정렬
		Collections.sort(word);
		
//		System.out.println(word);
		System.out.println(word.get(0));
		
	}

}
