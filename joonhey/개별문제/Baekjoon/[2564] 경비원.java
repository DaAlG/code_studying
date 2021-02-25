package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	static int width;
	static int height;
	static int rectLength;// 둘레
	static int N;
	static DirAndDist[] stores; // N개의 상점들
	static DirAndDist dongPos; // 동근이 위치.

	static class DirAndDist {
		int dir; // 방위
		int dist; // 거리

		public DirAndDist(int dir, int dist) {
			super();
			this.dir = dir;
			this.dist = dist;
		}
	}

	// 기준: 동근이
	public static int getMinDistance(DirAndDist store) {

		int clock, counterclock;
		// 같은 방위
		if (dongPos.dir == store.dir) {
			clock = Math.abs(dongPos.dist - store.dist);
		}
		// 같은 타입의 방위
		else if (dongPos.dir >= 3 && store.dir >= 3) {
			clock = width + dongPos.dist + store.dist;
		}
		else if (dongPos.dir < 3 && store.dir < 3) {
			clock = height + dongPos.dist + store.dist;
		}
		// 다른타입 but 홀짝수 같
		else if (dongPos.dir % 2 == 1 && store.dir % 2 == 1) {
			clock = dongPos.dist + store.dist;
		}

		else if (dongPos.dir % 2 == 0 && store.dir % 2 == 0) {
			clock = dongPos.dist + store.dist + width + height;
		}
		// 나머지 - 1,4
		else if (dongPos.dir == 1 || dongPos.dir == 4) {

			if (dongPos.dir == 1) {
				clock = width - dongPos.dist + store.dist;
			} else {
				clock = width - store.dist + dongPos.dist;
			}
		}

		// 2,3
		else {
			if (dongPos.dir == 3) {
				clock = height - dongPos.dist + store.dist;
			} else {
				clock = height - store.dist + dongPos.dist;
			}

		}
		counterclock = rectLength - clock;
		return clock < counterclock ? clock : counterclock;
	}

	public static int getTotalDist() {
		// 모든 가게들의 최단거리 합 리턴
		int distSum = 0;
		// 가게들 각각 최단거리 하나씩 더해줌
		for (int i = 0; i < N; i++) {
			distSum += getMinDistance(stores[i]);
		}
		return distSum;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		width = Integer.parseInt(st.nextToken());
		height = Integer.parseInt(st.nextToken());
		rectLength = width * 2 + height * 2;
		N = Integer.parseInt(br.readLine());
		stores = new DirAndDist[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			stores[i] = new DirAndDist(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		st = new StringTokenizer(br.readLine());
		dongPos = new DirAndDist(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

		System.out.println(getTotalDist());

	}
}