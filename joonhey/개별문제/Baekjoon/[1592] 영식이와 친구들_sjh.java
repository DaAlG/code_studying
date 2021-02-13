package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int ballCnt[];
	static int N, M, L;
	
	//총 몇번 주고받았는지.
	public static int countBall() {
		int sum = 0;
		for(int ball : ballCnt)
			sum += ball;
		return sum-1;
	}
	
	//person 번째한테 공이 감
	public static int throwBall(int person) {
		if(++ballCnt[person] == M)
			return countBall();
		if(ballCnt[person] % 2 == 0)
			return throwBall((person - L + N )%N);
		else
			return throwBall((person + L )%N);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		ballCnt = new int[N];
		System.out.println(throwBall(0)); //1번부터 공 받기
	}
}
