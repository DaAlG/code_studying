import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// BOJ 17413 단어 뒤집기 2
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String word = br.readLine();
		
		StringBuilder answer = new StringBuilder();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < word.length(); i++) {
			if (word.charAt(i) == ' ') {
				answer.append(sb.reverse());
				answer.append(' ');
				sb = new StringBuilder();
			}
			else if (word.charAt(i) == '<') {
				answer.append(sb.reverse());
				sb = new StringBuilder();
				
				int end = i + 1;
				while (end < word.length() && word.charAt(end) != '>') end++;
				answer.append(word.substring(i, end + 1));
				i = end;
			} else {
				sb.append(word.charAt(i));
			}
		}
		answer.append(sb.reverse());
		System.out.println(answer.toString());
	}
}
