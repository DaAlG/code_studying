// 백준 2999 비밀 이메일

import java.io.*;
import java.util.*;

public class Main_2999 {

	static int N, R, C;
	static String msg;
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		msg = br.readLine();
		N = msg.length();
		
		for (int r = 1; r*r <= N ; r++) {
			for (int c = r; c <= N; c++) {
				
				if(r*c == N) { // 조건
					R = r;
					C = c;
				}
			}
		} // 제일 큰 R을 찾아야해서 다 돌아봐야행..끝에서부터 찾으려면 어케해야되지?ㅠ
		
		// 행렬 만들기
		char[][] msg2 = new char[R][C];
		
		int index = 0;
		for(int i=0; i<C; i++) {
			for(int j=0; j<R; j++) {
				msg2[j][i] = msg.charAt(index++);
			}
		}
		
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				System.out.print(msg2[i][j]);
			}
		}
	}
}
