import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// BOJ 2999 비밀 이메일
public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		
		int r = 0;
		int c = 0;
		for (int i = 1; i <= Math.sqrt(s.length()); i++) {
			if (s.length() % i == 0) {
				r = i;
				c = s.length() / i;
			}
		}
		
		char[][] enc = new char[r][c];
		for (int j = 0; j < c; j++) {
			for (int i = 0; i < r; i++) {
				enc[i][j] = s.charAt(j * r + i);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				sb.append(enc[i][j]);
			}
		}
		System.out.println(sb.toString());
	}

}
