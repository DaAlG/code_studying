package test;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static int house[][];
	static int N;
	static int res;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		house = new int[3][N+1]; //1~N
		for(int i=1; i<=N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				house[j][i] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=2; i<=N; i++) {
			for(int j=0; j<3; j++) {
				house[j][i] += Math.min(house[(j+1)%3][i-1], house[(j+2)%3][i-1]);
			}
		}
		res = house[0][N] <= house[1][N] ? house[0][N] : house[1][N];
		res = house[2][N] <= res ? house[2][N] :res;
		System.out.println(res);
	}
}