import java.io.*;
import java.util.*;

// baekjoon 2563
public class Main {

	static int N, sum = 0;
	static int[][] paper = new int[101][101];
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		for(int t=0;t<N;t++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			for(int i = a; i<a+10; i++) {
				for(int j=b; j<b+10; j++) {
					if(paper[i][j]==1) continue;
					paper[i][j] = 1;
					sum++;
				}
			}
		}
		System.out.println(sum);
	}

}
