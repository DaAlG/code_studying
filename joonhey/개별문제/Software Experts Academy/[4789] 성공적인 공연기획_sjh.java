package practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
	static int cnt;

	// line scan 하면서 사람, total 추가.
	public static void addClapper(String inputLine) {
		int total = 0; // 현재 서 있는 사람.
		int peopleStanding; //곧 일어설 사람.
		char input;
		
		for(int i=0; i<inputLine.length(); i++) {
			input = inputLine.charAt(i);
			if(input != '0') { //일어설 사람 있음.
				peopleStanding = input - '0';
				if(total < i ) { // 충원 필요
					cnt += i - total;
					total += i - total;
				}
				total += peopleStanding; //결과
			}
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			cnt = 0;
			addClapper(br.readLine());
			System.out.println("#" + (t + 1) + " " + cnt);
		}
	}
}