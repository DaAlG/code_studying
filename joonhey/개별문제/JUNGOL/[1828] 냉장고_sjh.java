package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Main {
	static int N;

	static class material implements Comparable<material>{
		int floor;
		int ceil;

		public material(int floor, int ceil) {
			this.floor = floor;
			this.ceil = ceil;
		}

		@Override
		public int compareTo(material o) {
			return this.floor - o.floor;
		}
	}

	static material[] materials;

	public static int addRefri() {
		int min = -271;
		int max = 100001;
		int cnt = 1;
		for (material m : materials) {
			if (m.floor > max) { // 새 냉장고
				cnt++;
				max = m.ceil;
				min = m.floor;
			} else {
				if (m.floor > min) {
					min = m.floor;
				}
				if(m.ceil < max) {
					max = m.ceil;
				}
			}
		}

		return cnt;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		materials = new material[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			materials[i] = new material(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		Arrays.sort(materials);
		System.out.println(addRefri());
	}
}