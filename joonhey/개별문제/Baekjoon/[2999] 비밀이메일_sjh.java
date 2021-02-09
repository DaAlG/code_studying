package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int R,C;
	
	public static void findRC(int N) {
		//R 구하기.
		for(int i=1; i<= Math.floor(Math.sqrt(N)); i++) {
			if(N % i == 0)
				R = i;
		}
		//C 구하기.
		C = N / R;
	}
	
	public static String decodeEmail(char[] inputMsg) {
		StringBuilder outputMsg = new StringBuilder("");
		
		int N = inputMsg.length;
		int idx;
		int row = 0;
		
		//R,C 구하기
		findRC(N);
		
		//행렬 순회하기
		while(row < R) {
			idx = row;
			while( idx < N ) {
				outputMsg.append(inputMsg[idx]);
				idx += R;
			}
			row += 1;
		}
		
		return outputMsg.toString();
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputMsg;
		inputMsg = br.readLine();
		System.out.println(decodeEmail(inputMsg.toCharArray()));
	}
}
