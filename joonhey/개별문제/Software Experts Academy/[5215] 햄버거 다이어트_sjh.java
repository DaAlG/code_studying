package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int N; //재료 수
	static int L; //최대 칼로리
	static int maxScore;
	static int[] ingredScore;
	static int[] ingredKalorie;
	
	public static void comb(int target, int curKal, int curScore) {
		//기저조건
		if(target == N) {
			if(curKal <= L && curScore > maxScore)
				maxScore = curScore;
			return;
		}
		
		//if문으로 분기하지 않는 이유 - 정해진 길이 아닌 다양한 상황을 적응 위함.
		//선택 
		comb(target+1, curKal + ingredKalorie[target], curScore + ingredScore[target]);
		//비선택
		comb(target+1, curKal, curScore);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int TC = Integer.parseInt(br.readLine());
		for(int t=0; t<TC; t++) {
			maxScore = -1; //테케마다 초기화
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			ingredScore = new int[N];
			ingredKalorie = new int[N];
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				ingredScore[i] = Integer.parseInt(st.nextToken());
				ingredKalorie[i] = Integer.parseInt(st.nextToken());
			}
			comb(0, 0, 0);
			//출력
			System.out.println("#"+(t+1)+" "+maxScore);
		}
	}
}
