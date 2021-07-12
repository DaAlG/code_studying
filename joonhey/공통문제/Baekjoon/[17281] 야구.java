import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int totalInning;
	static int[] playerTurn = new int[9];
	static int[][] playerScore;
	static boolean[] used = new boolean[9];
	static int maxScore;
	static int curScore;
	static boolean[] board = new boolean[3];
	
	public static void updateBoard(int result) {
		
		for(int i=2; i>=0; i--) { //역순회
			//홈인
			if(board[i] && i+result >=3 ) {
				board[i] = false;
				curScore++;
			}
			//베이스 이동
			else if(board[i]) {
				board[i+result] = true;
				board[i] = false;
			}
		}
		//뉴비 안착
		board[result-1] = true;
	}
	
	public static void clearBoard() {
		for(int i=0; i<3; i++)
			board[i] = false;
	}
	
	public static int countRunners() {
		int sum = 0;
		for(int i=0; i<3; i++) {
			if(board[i])
				sum+=1;
		}
		return sum;
	}
	
	//maxScore 비교해서 리셋.
	public static void playGame() {
		int curInning = 0; //현 이닝
		curScore = 0; //점수 > 이닝마다 공유
		int turn = 0; //순서 > 이닝마다 공유
		int outCnt;
		int result;
		
		//게임 새로 시작.
		while(curInning != totalInning) {
			//보드, 아웃카운트 > 이닝 내에서 변화.
			outCnt = 0;
			clearBoard();
			//이닝 새로 시작. turn과 score 유지.
			while(outCnt != 3) {
				result = playerScore[curInning][playerTurn[turn]];
				switch(result) {
				case 0: //아웃
					outCnt++;
					break;
				case 4: 
					// 홈런: 타자 + 주자 포함하기!
					curScore += countRunners();
					curScore += 1;
					clearBoard();
					break;
				default: //그 외 안타
					updateBoard(result);
				}
				turn = (turn+1)%9; //순서 돌아감.
			}
			curInning++;
		}
		
		//최대 점수 업데이트.
		if(curScore > maxScore)
			maxScore = curScore;
		
	}
	
	//nPr n = 9, r = 9, 3번 인덱스 0으로 고정.
	public static void perm(int idx) {
		if(idx == 9) { //순열 완성 했으니 게임 진행
			playGame();
			return;
		}
		if( idx == 3 ) {
			perm(idx+1);
		}
		else {
			for(int i=1; i<9; i++) {
				if(!used[i]) {
					used[i] = true;
					playerTurn[idx] = i;
					perm(idx+1);
					used[i] = false;
				}
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		playerTurn[3] = 0; used[0] = true; // 최애 4번타자 고정.
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		totalInning = Integer.parseInt(br.readLine());
		playerScore = new int[totalInning][9];
		
		for(int i=0; i<totalInning; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<9; j++) {
				playerScore[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		perm(0);
		System.out.println(maxScore);
	}
}
