package day0205;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static class Res{
		int maxCnt;
		int maxNum;
		
		public Res(int maxCnt, int maxNum) {
			this.maxCnt = maxCnt;
			this.maxNum = maxNum;
		}
	}
	static Res res;
	static int N;
	static int[][] room;
	static int[] di = {-1, 1, 0, 0};
	static int[] dj = {0, 0, -1, 1};
	
	//posX, posY 부터 시작했을 때의 이동 횟수 리턴. curNum도 업데이트.
	public static int travelRoom(int posX, int posY) {
		int cnt = 1; 
		int k = 0;
		int ni, nj;
		
		while(k < 4) { //더 이상 이동할 수 없을 때까지!
			ni = posX + di[k];
			nj = posY + dj[k];
			
			//이동 가능.
			if( ni>=0 && nj>=0 && ni<N && nj<N && room[ni][nj] == room[posX][posY] + 1) {
				cnt++;
				posX = ni; posY = nj;
				k = 0;
			}
			else
				k++;
		}
		
		return cnt;
	}
	
	//(0,0)부터 (N-1, N-1) 까지 다 돌면서 최대 이동 횟수 갱신.
	public static void findingMax() {
		int cnt;
		int num;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				cnt = travelRoom(i, j);
				num = room[i][j]; //도착시가 아니라 출발시의 번호임에유의
				
				//중복이면 숫자가 작은 방 승리.
				if(res.maxCnt == cnt) {
					if(res.maxNum > num) {
						res.maxNum = num;
						res.maxCnt = cnt;
					}
				}
				else if(res.maxCnt < cnt) {
					res.maxNum = num;
					res.maxCnt = cnt;
				}
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		String inputLine;
		StringTokenizer st;
		
		res = new Res(-1, 0);
		
		for(int t=0; t<T; t++) {
			sb.setLength(0); //출력 초기화
			res.maxCnt = -1; //최대 이동 횟수 초기화
			
			N = Integer.parseInt(br.readLine());
			room = new int[N][N];
			for(int i=0; i<N; i++) {
				inputLine = br.readLine();
				st = new StringTokenizer(inputLine);
				for(int j=0; j<N; j++) {
					room[i][j] =  Integer.parseInt(st.nextToken());
				}
			}
			
			findingMax(); //최대 이동 횟수 리셋.
			
			//출력
			sb.append("#").append(Integer.toString(t+1)+" ").append(res.maxNum+" ").append(res.maxCnt);
			System.out.println(sb.toString());
		}
	}
}
