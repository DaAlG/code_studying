package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static Double[] minDist;

	static class Point {
		double x;
		double y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N;
	static Point[] stars;
	static double res;
	static boolean[] visited;
	
	//stars[star1], stars[star2] 사이의 거리 반환
	public static double getDistance(int star1, int star2) {
		Point s1 = stars[star1];
		Point s2 = stars[star2];
		double xDist = Math.abs(s1.x - s2.x);
		double yDist = Math.abs(s1.y - s2.y);
		
		return Math.sqrt(xDist * xDist + yDist*yDist);
	}
	public static void makeStarMST() {
		// 0번 시작으루 심기.
		minDist[0] = 0.0;

		int start = 0; // 시작정점 저장
		int cnt = 0; // 방문된 애들 수.
		while (cnt < N) {
			double min = Double.MAX_VALUE;
			// 시작정점 찾기 -> pq로 바꿔서 해볼 것.
			for (int i = 0; i < N; i++) {
				if (minDist[i] < min && !visited[i]) {
					min = minDist[i];
					start = i;
				}
			}
			res += min;
			cnt++;
			//걔 기준으로 업뎃
			visited[start] = true;
			for(int i=0; i<N; i++) {
				if(!visited[i]) {
					double curDist = getDistance(start, i);
					if(minDist[i] > curDist)
						minDist[i] = curDist;
				}
			}
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		stars = new Point[N];
		minDist = new Double[N];
		visited = new boolean[N];
		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			stars[i] = new Point(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
			minDist[i] = Double.MAX_VALUE;
		}

		makeStarMST();

		System.out.println(res);

	}
}