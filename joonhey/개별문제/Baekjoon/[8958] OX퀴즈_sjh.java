package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static int calScore(char[] markedInput) {
		int score = 0;
		int combo = 0;

		for (int i = 0; i < markedInput.length; i++) {
			if (markedInput[i] == 'O') {
				score += (++combo);
			} else {
				combo = 0;
			}
		}
		return score;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			System.out.println(calScore(br.readLine().toCharArray()));
		}
	}
}
