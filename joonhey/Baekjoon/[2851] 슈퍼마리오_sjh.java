package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int mushroom;
		int score = 0;
		int t;
		for(t=0; t<10; t++) {
			mushroom = Integer.parseInt(br.readLine());
			if(Math.abs(score + mushroom - 100)<= Math.abs(score - 100)) {
				score += mushroom;
			}
			else
				break;
		}
		while(t<10) {
			br.readLine();
			t++;
		}
		System.out.println(score);
	}
}
