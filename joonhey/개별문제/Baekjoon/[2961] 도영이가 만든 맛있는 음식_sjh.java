import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;

	static class Ingred {
		long sour;
		long bitter;

		public Ingred(long s, long b) {
			this.sour = s;
			this.bitter = b;
		}
	}

	static Ingred[] list;
	static boolean[] selected;
	static long min;

	public static void subset(int cnt, int cur) {

		long sourSum = 1;
		long bitterSum = 0;

		// 기저조건
		if (cnt == N && cur > 0) {
			for (int i = 0; i < N; i++) {
				if (selected[i]) {
					sourSum *= list[i].sour;
					bitterSum += list[i].bitter;
				}
			}
			min = min < Math.abs(sourSum - bitterSum) ? min : Math.abs(sourSum - bitterSum); 
			return;
		}
		if (cnt == N)
			return;
		//반복.
		selected[cnt] = true;
		subset(cnt+1, cur+1);
		selected[cnt] = false;
		subset(cnt+1, cur);
		
		
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		list = new Ingred[N];
		selected = new boolean[N];
		StringTokenizer st;
		min = Long.MAX_VALUE;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			list[i] = new Ingred(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		subset(0, 0);
		System.out.println(min);
	}
}