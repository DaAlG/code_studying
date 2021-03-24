import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
	static char[] input;
	static int L, C; // C개 중에 L개를 고름
	static StringBuilder sb;// 여기에 알파벳 담을 겨
	static StringBuilder finSb;
	public static void guessPw(int cnt, int target) {
		// 다 모음
		if (cnt == L) {
			int curMoeum = 0;
			for (char c: sb.toString().toCharArray()) {
				if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') {
					curMoeum++;
				}
			}
			if(curMoeum >=1 && L - curMoeum >=2)
				finSb.append(sb).append("\n");
			return;
		}
		// 범위 초과
		if (target == C) {
			return;
		}
		// target번째 추가
		sb.append(input[target]);
		guessPw(cnt + 1, target + 1);

		// 취소
		sb.setLength(sb.length() - 1);
		guessPw(cnt, target + 1);

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		input = new char[C];

		String inputLine = br.readLine();
		for (int i = 0; i < C * 2; i += 2) {
			input[i / 2] = inputLine.charAt(i);
		}

		Arrays.sort(input);

		sb = new StringBuilder("");
		finSb = new StringBuilder("");
		guessPw(0, 0);
		System.out.println(finSb);
	}
}