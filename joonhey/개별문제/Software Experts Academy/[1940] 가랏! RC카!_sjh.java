package day0205;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int speed;

	//명령어 처리하여 속도 변화시키기.
	public static void changeSpeed(String inputLine) {
		char cmd = inputLine.charAt(0);
		int param = 0;
		
		if( cmd != '0' ) //indexOutOfBound err 방지.
			param = inputLine.charAt(2) - '0'; //가,감 정도.
		
		switch(cmd) { //가속 or 감속
		case '1' : speed += param;
					break;
		case '2' : if(speed < param)
						speed = 0;
					else
						speed -= param;
					break;
		//0인 경우는 유지.
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int N, dist;
		String inputLine;

		for (int t = 0; t < T; t++) {
			dist = 0;
			speed = 0; // 초기속도 0
			N = Integer.parseInt(br.readLine());

			for (int i = 0; i < N; i++) {
				inputLine = br.readLine();
				changeSpeed(inputLine);
				dist += speed;
			}
			// 출력
			System.out.println("#" + (t + 1) + " " + dist);
		}
	}
}