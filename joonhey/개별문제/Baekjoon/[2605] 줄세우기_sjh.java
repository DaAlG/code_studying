package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Main {
	static int N;
	static LinkedList<Integer> line;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		line = new LinkedList<>();
		int num;
		StringTokenizer st = new StringTokenizer(br.readLine());
		line.add(1); st.nextToken();
		for (int i = 1; i < N; i++) {
			num = Integer.parseInt(st.nextToken());
			line.add(i - num, i+1);
		}
		StringBuilder sb = new StringBuilder("");
		for (int n : line) {
			sb.append(n).append(" ");
		}
		System.out.println(sb.toString());
	}
}