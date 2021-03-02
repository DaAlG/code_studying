package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
	static class Pillar implements Comparable<Pillar> {
		int idx;
		int height;

		public Pillar(int idx, int height) {
			this.idx = idx;
			this.height = height;
		}

		@Override // 크기로 내림차순.
		public int compareTo(Pillar o) {
			return o.height - this.height;
		}

	}

	static Pillar[] pillars; // N
	static boolean[] selected; // 1000 -> 기둥이 없든 있든 체크해야 함. 있을지 없을지 모르니깐.
	static int N;

	public static int buildRoof() {
		int area = 0;
		int range = pillars[0].idx - 1;

		// N개 기둥 다 더함 - 높이가 큰 것부터
		for (int i = 0; i < N; i++) {
			int curPos = pillars[i].idx;
			int curHeight = pillars[i].height;
			// 아직 지붕 x
			while (!selected[curPos] && curPos != range) {
				selected[curPos] = true;
				area += curHeight;
				curPos = range < curPos ? curPos-1 : curPos+1;
			}
			range = pillars[i].idx;
		}

		return area;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		selected = new boolean[1001];
		pillars = new Pillar[N];
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			pillars[i] = new Pillar(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		// 기둥 높은 순으로 정렬
		Arrays.sort(pillars);
		// 높은 것부터 더하면서 pop
		System.out.println(buildRoof());
	}

}