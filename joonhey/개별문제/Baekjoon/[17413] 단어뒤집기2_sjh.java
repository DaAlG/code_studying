package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputLine = br.readLine();
		int idx = 0;
		StringBuilder sb;
		int len = inputLine.length();
		while (idx < len) {
			char letter = inputLine.charAt(idx);
			if (letter == '<') {// > 나올대까지 프린트.
				while(idx <len && (letter= inputLine.charAt(idx)) != '>') {
					System.out.print(letter);
					idx++;
				} //>
			}
			else if(letter == ' ' || letter == '>') {
				System.out.print(letter);
				idx++;
			}
			else {
				sb = new StringBuilder("");
				while(idx < len && letter != ' ' && letter != '<') {
					sb.append(letter);
					letter = idx +1 < len ? inputLine.charAt(idx+1) : '<';
					idx++;
				}
				System.out.print(sb.reverse().toString());
			}
			
				
		}
	}
}
