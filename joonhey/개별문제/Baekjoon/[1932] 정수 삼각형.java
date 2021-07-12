package ahah;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] triangle;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		// 입력받기
		triangle = new int[N][];
		triangle[0] = new int[1];
		triangle[0][0] = Integer.parseInt(br.readLine());
		int i;
		for(i=1; i!= N; i++) {
			triangle[i] = new int[i+1];
			StringTokenizer st = new StringTokenizer( br.readLine());
			for(int j=0; j <= i; j++) {
				triangle[i][j] = Integer.parseInt(st.nextToken());
			}
			//dp.
			//첫번째, 마지막 열 -> 그대로 누적.
			triangle[i][0] += triangle[i-1][0];
			triangle[i][i] += triangle[i-1][i-1];
//			중간 -> 양 옆중 더 큰 것 누적.
			for(int j=1; j<i; j++) {
				triangle[i][j] += Math.max(triangle[i-1][j-1], triangle[i-1][j]);
			}
		}
		//마지막 행에서의 최댓값 구하깅.
		int res = 0;
		int j = 0;
		i--;
		while(j <= i) {
			res = res > triangle[i][j] ? res : triangle[i][j];
			j++;
		}
		System.out.println(res);
		
	}
}
