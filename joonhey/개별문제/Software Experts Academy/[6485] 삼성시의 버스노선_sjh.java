package practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	static int[] busRoutes;
	static StringBuilder res;

	// A~B번 정류장에 노선 추가.
	public static void addRoute(int A, int B) {
		for (int i = A - 1; i < B; i++)
			busRoutes[i]++;
	}

	public static void makeRes(int bus) {
		res.append(" ").append(busRoutes[bus - 1]);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, P;
		int A, B;
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < T; t++) {
			busRoutes = new int[5000];
			
			N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; i++) { // 버스별 노선 추가
				st = new StringTokenizer(br.readLine());
				A = Integer.parseInt(st.nextToken());
				B = Integer.parseInt(st.nextToken());
				addRoute(A, B);
			}

			P = Integer.parseInt(br.readLine());
			res = new StringBuilder("#").append(Integer.toString(t+1));
			for (int i = 0; i < P; i++) { // res에 노선 개수 추가.
				makeRes(Integer.parseInt(br.readLine()));
			}
			System.out.println(res.toString());
		}
	}
}