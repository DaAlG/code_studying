package com.ssafy.exhaustive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int[] datas = new int[8];
	
	public static void updateData() {
		int k = 0;
		int cur = poll() - (k++)%5-1;
		
		while(cur > 0) {
			offer(cur);
			cur = poll() - (k++)%5-1;		
		}
		offer(0); //종료
	}
	public static void printData() {

		for(int d : datas) {
			System.out.print(d+" ");
		}
		System.out.println();
	}
	public static void clear() {
		for(int i=0; i<8; i++)
			datas[i] = 0;
	}
	public static void offer(int num) {
		datas[7] = num;
	}
	public static int poll() {
		int num = datas[0];
		//array shifting
		for(int i=0; i<7; i++) {
			datas[i] = datas[i+1];
		}
		
		return num;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String T;
		for(int t=1; t<=10; t++) {
			clear();
			T = br.readLine();
			st = new StringTokenizer(br.readLine());

			for (int i = 0; i < 8; i++) {
				datas[i] = Integer.parseInt(st.nextToken());
			}
			// 싸이클 실행 하고 출력
			updateData();
			System.out.print("#" + (t) + " ");
			printData();
		}
	}
}
