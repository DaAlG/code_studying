package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
	static int N;
	static int cnt;
	static boolean[] visited; //그 열의 방문 여부 기록
	static int[] cols; //행 별 위치 기록
	
	//그 위치가 대각선 공격으로부터 안전한지 체크
	public static boolean isAvailable(int row, int col) {
		for(int i=0; i<row; i++) {
			//한 행이라도 대각선 공격권이면 false
			if(row - i == Math.abs(col - cols[i])) {
				return false;
			}
		}
		return true; //모든 행 통과.
	}
	public static void NQueen(int row) {
		//기저조건
		if(row == N) {
			cnt++;
			return;
		}
		//유도조건
		for(int col = 0; col<N; col++) {
			//세로 공격, 대각선 공격 차단
			if(!visited[col] && isAvailable(row, col)) {
				visited[col] = true;
				cols[row] = col;
				NQueen(row + 1);
				visited[col] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		visited = new boolean[N];
		cols = new int[N];
		NQueen(0);
		System.out.println(cnt);
	}
}