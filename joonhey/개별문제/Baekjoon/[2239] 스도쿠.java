import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
	static int[][] board;
	static int[][] board_org;
	static boolean[][] garo;
	static boolean[][] sero;
	static boolean [][][] rect;
	static boolean found;
	public static void dfs(int i, int j) {
//		기저
		if(i == 9) {
			found = true;
			return;
		}
		if(found)
			return;
//		해당 행과 열에서 나오지 않은 숫자를 집어넣는다.
		if(board_org[i][j] == 0) {
		for(int n=1; n<10; n++) {
			if(found)
//				이 작업 반드시 필요 -> why ? 완성되고 나서도 재귀 자꾸 돌고, board 값 바꿈. 결국 앞에 애들은 갈 곳이 없어서 
//				끝까지 가고 이상한 값 나옴.
				break;
			if(!garo[i][n] && !sero[j][n] && !rect[i/3][j/3][n]) {
				garo[i][n] = true;
				sero[j][n] = true;
				rect[i/3][j/3][n] = true;
				board[i][j] = n;
				if(j+1 == 9)
					dfs(i+1, 0);
				else
					dfs(i, j+1);
//				원상복귀. -> 
				garo[i][n] = false;
				sero[j][n] = false;
				rect[i/3][j/3][n] = false;
			}
		}
		}
		else
		{
			if(j+1 == 9) {
				dfs(i+1, 0);
			}
			else
				dfs(i, j+1);
		}
	}
	public static void printBoard() {
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws IOException{
		board = new int[9][9];
		board_org = new int[9][9];
		garo = new boolean[9][10];
		sero = new boolean[9][10];
		rect = new boolean[3][3][10];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		스토쿠 퍼즐 입력
		String inputLine;
		for(int i=0; i<9; i++) {
			inputLine = br.readLine();
			for(int j=0; j<9; j++) {
				board[i][j] = Integer.parseInt(inputLine.substring(j,j+1));
				board_org[i][j] = board[i][j];
//				채워진 칸들 기록
				if(board[i][j] != 0) {
					garo[i][board[i][j]] = true;
					sero[j][board[i][j]] = true;
					rect[i/3][j/3][board[i][j]] = true;
				}
			}
		}
		dfs(0,0);
		printBoard();
	}
}