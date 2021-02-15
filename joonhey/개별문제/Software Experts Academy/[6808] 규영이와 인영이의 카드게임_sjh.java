package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int[] kCards;
	static int[] yCards;
	static boolean[] cardEntry;
	static int[] yCardEntry;
	static int kWin, kLose;
	static boolean[] isSelected;
	
	public static void playGame() {
		int kScore = 0; int yScore = 0;
		//9라운드 진행
		for(int r=0; r<9; r++) {
			if(kCards[r] > yCards[r])
				kScore += kCards[r] + yCards[r];
			else
				yScore += kCards[r] + yCards[r];
		}
		if(kScore > yScore )
			kWin++;
		else if(kScore < yScore)
			kLose++;
	}
	
	//yCards 결정 - yCardEntry, isSelected 기반.
	public static void perm(int cnt) {
		if(cnt == 9) {
			playGame();
			return;
		}
		for(int i=0; i<9; i++) {
			if(!isSelected[i]) {
				yCards[cnt] = yCardEntry[i];
				isSelected[i] = true;
				perm(cnt+1);
				isSelected[i] = false;
			}

		}
	}
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		int num;
		int k;
		isSelected = new boolean[9];
		yCards = new int[9];
		kCards = new int[9];
		yCardEntry = new int[9];
		for(int t=1; t<=T; t++) { //Selected 초기화 할 필요 x
			//규영 카드
			cardEntry = new boolean[19];
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<9; i++) {
				num = Integer.parseInt(st.nextToken());
				kCards[i] = num;
				cardEntry[num] = true;
			}
			kWin = 0;
			kLose = 0;
			sb = new StringBuilder("#").append(t).append(" ");
			
			//인영카드 - 후보 목록 추리고 거기서 순열
			k = 0;
			for(int i=1; i<=18; i++) {
				if(!cardEntry[i])
					yCardEntry[k++] = i;
			}
			perm(0);
			
			//출력
			sb.append(kWin).append(" ").append(kLose);
			System.out.println(sb.toString());
		}
	}
}
