package day0205;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static String[] newLine; //새로 만든 거 저장
	static String[] deck;
	static int N;
	
	//새로 만든 거 출력.
	public static void printNewLine() {
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<N; i++) { //원소 별 공백 줘서 합치기.
			sb.append(newLine[i]).append(" ");
		}
		
		System.out.println(sb.toString());
	}
	
	//스캔, 저장
	public static void updateNewLine() {
		int i = 0;
		int k = 0;
		
		while( i < N/2 ) {
			newLine[k] =deck[i]; //1조
			newLine[k+1] = deck[i + N/2 + N%2]; //2조
			i++;
			k += 2;
		}
		
		//N이 홀수면 남는걸 끝에 넣어줌.
		if (N%2 == 1) {
			newLine[k] = deck[N/2];
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for(int t=0; t<T; t++) {
			N = Integer.parseInt(br.readLine());
			//TC마다 새로 할당.
			deck = new String[N];
			newLine = new String [N];
			
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) {
				deck[i] = st.nextToken();
			}
			
			//deck 스캔하여 셔플, newLine에 저장.
			updateNewLine();
			
			//출력
			System.out.print("#"+(t+1)+" ");
			printNewLine(); 
		}
	}
}