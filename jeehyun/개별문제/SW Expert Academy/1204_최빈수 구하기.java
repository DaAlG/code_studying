import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bf.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			test_case = Integer.parseInt(bf.readLine());
			System.out.println("#" + test_case + " ");
			
			int[] cnt = new int[101];
			String score = bf.readLine();
			StringTokenizer st = new StringTokenizer(score, " ");
			
			while (st.hasMoreTokens()) {
				cnt[Integer.valueOf(st.nextToken())]++;
			}
			
			int answer = 0;
			int maxCnt = 0;
			
			for (int i = 0; i <= 100; i++) {
				if (cnt[i] >= maxCnt) {
					answer = i;
					maxCnt = cnt[i];
				}
			}
			System.out.println(answer);
		}
	}

}
