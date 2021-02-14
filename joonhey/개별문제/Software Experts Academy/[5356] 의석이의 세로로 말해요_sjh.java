package practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
	static int maxLen;
	static String[] words = new String[5];

	public static String makeNewWords() {
		StringBuilder res = new StringBuilder(" ");
		
		int k = 0;
		do {
			for (int i = 0; i < 5; i++) {
				if(words[i].length()>k)
					res.append(words[i].charAt(k));
			}
		} while ((++k) < maxLen);
		
		return res.toString();
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int len;

		for (int t = 0; t < T; t++) {
			maxLen = 0;

			for (int i = 0; i < 5; i++) {
				words[i] = br.readLine();
				len = words[i].length();
				if (len > maxLen)
					maxLen = len;
			}
			System.out.println("#" + (t + 1) + makeNewWords());
		}

	}
}