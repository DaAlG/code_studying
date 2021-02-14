package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	static int cnt;
	static int N, D;
	static char[] doors;

	public static void installDoors() {
		int maxDist = D;

		for (int i = 0; i < N; i++) {
			if (doors[i] == '1') {
				maxDist = i+1 + D;
			} else if (doors[i] == '0' && maxDist == i+1) {
				cnt++;
				maxDist = i+1 + D;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String inputLine;
		StringBuilder sb;
		int k;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			cnt = 0;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			D = Integer.parseInt(st.nextToken());
			inputLine = br.readLine();
			k  = 0;
			doors = new char[N]; // 0,1~N
			for (int i = 0; i < N; i++) {
				doors[i] = inputLine.charAt(k);
				k+=2; //
			}
			installDoors();
			sb = new StringBuilder("#").append(t).append(" ").append(cnt);
			System.out.println(sb.toString());

		}

	}
}