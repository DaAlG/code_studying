import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	public static int[] digit;
	public static int n;
	public static int answer;
	
	public static int getPrize() {
		int num = digit[0];
		for (int i = 1; i < digit.length; i++) {
			num = num * 10 + digit[i];
		}
		return num;
	}
	
	public static void swap(int a, int b) {
		int tmp = digit[a];
		digit[a] = digit[b];
		digit[b] = tmp;
	}
	
	public static void exchange(int now, int cnt) {
		if (cnt >= n) {
			answer = Math.max(answer, getPrize());
			return;
		}
		
		for (int i = now; i < digit.length; i++) {
			for (int j = i + 1; j < digit.length; j++) {
				swap(i, j);
				exchange(i, cnt + 1);
				swap(i, j);
			}
		}
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
        for (int test_case = 1; test_case <= T; test_case++) {
        	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        	String prize = st.nextToken();
        	digit = new int[prize.length()];
        	for (int i = 0; i < digit.length; i++) {
        		digit[i] = Character.getNumericValue(prize.charAt(i));
        	}
        	
        	n = Integer.parseInt(st.nextToken());
        	answer = 0;
        	exchange(0,0);
        	
        	System.out.println("#" + test_case + " " + answer);
		}
	}
}
