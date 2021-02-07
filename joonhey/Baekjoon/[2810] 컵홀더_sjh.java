package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static int maxCupholder(int N, char[] seat) {
		boolean firstCouple = false;
		int i = 0;
		int cnt = 0;
		
		while(i < N) {
			if(seat[i] == 'S') {
				cnt++;
				i++;
			}
			else if(firstCouple) {
				cnt += 1;
				i += 2;
			}
			else {
				firstCouple = true;
				cnt += 2;
				i += 2;
			}
		}
		return cnt;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(
				maxCupholder(Integer.parseInt(br.readLine()),br.readLine().toCharArray()));
	}
}
