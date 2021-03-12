package com.ssafy.subset;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Main{
	static ArrayList<Integer> input;
	static int[] selected;
	static int N, M;
	static StringBuilder sb;
	
	public static void comb(int cnt, int start) {
		//기저
		if(cnt == M) {
			//출력
			for(int num : selected) {
				sb.append(num).append(" ");
			}
			sb.append("\n");
			return;
		}
		for(int i=start; i<input.size(); i++) {
			//선택
			selected[cnt] = input.get(i);
			comb(cnt+1, i);
			//비선택 -> 다음 요소로 이동.
		}
	}
	
	public static void main(String[] args) throws IOException{
		input = new ArrayList<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		selected = new int[M];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			int num = Integer.parseInt(st.nextToken());
			if(!input.contains(num)) { //없을때만 추가.
				input.add(num);
			}
		}
		Collections.sort(input);
		sb = new StringBuilder("");
		comb(0, 0);
		System.out.println(sb);
	}
}