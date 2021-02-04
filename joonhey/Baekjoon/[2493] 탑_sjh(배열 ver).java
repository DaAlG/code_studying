package com.ssafy.exhaustive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	static int[] towers;
	static int N;
	static int[] firstReceiver;
	//key: 층수, value: 인덱스에 유의!
	static HashMap<Integer, Integer> map = new HashMap<>();
	static int[] waiting;
	static int top = -1;
	
	public static int peek() {
		return waiting[top];
	}
	
	public static int pop() {
		return waiting[top--];
	}
	
	public static void push(int num) {
		waiting[++top] = num;
	}
	
	// 인덱스는 +1, for문 후 stack에 남은거 0으로 처리하는거, 인덱스랑 층수 멥으로 관리하는거 잊지 마!
	public static void findFirstReceiver() {
		
		for(int i = N-1; i >=0; i--) { //오른쪽부터 넣는 것임에도 유의...
			//waiting에서 기다리고 있던 작은 애들 tower 설정하면서 pop 시켜줌.
			while(top != -1 && peek() < towers[i]) {
				firstReceiver[map.get(pop())] = i + 1;
			}
			
			push(towers[i]);
		}
		while(top != -1) { //top을 기준으로 해야 함 - length는 할당된 원소 수라서 0으로 채워져있으므로 정확X
			firstReceiver[map.get(pop())] = 0;
		}
	}

	public static void printReceivers() {
		StringBuilder Result = new StringBuilder("");
		for (int i = 0; i < N; i++) {
			Result.append(firstReceiver[i]).append(" ");
		}
		System.out.println(Result);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		towers = new int[N];
		firstReceiver = new int[N];
		waiting = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			towers[i] = Integer.parseInt(st.nextToken());
			map.put(towers[i],i); // 층수(직접적인 비교대상) - 인덱스 메핑.
		}

		// 최초 수신탑 찾고 저장하기
		findFirstReceiver();

		// 최초 수신 탑 출력하기
		printReceivers();

	}
}
