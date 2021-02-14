package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static int[][] board = new int[5][5];
	static boolean[][] checked = new boolean[5][5];
	static int lines;
	static int cnt;

	static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Point() {
		}
	}

	// 숫자의 x, y 좌표 리턴.
	public static Point findPosition(int num) {
		Point curPoint = new Point();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i][j] == num) {
					curPoint.x = i;
					curPoint.y = j;
					break;
				}
			}
		}
		return curPoint;
	}

	// 빙고면 1, 아니면 0
	public static int checkRow(Point curPoint) {
		int ROW = curPoint.x;
		for (int j = 0; j < 5; j++)
			if (!checked[ROW][j])
				return 0; // 하나라도 x면 빙고 아님.
		return 1;
	}

	// 빙고면 1, 아니면 0
	public static int checkCol(Point curPoint) {
		int COL = curPoint.y;
		for (int i = 0; i < 5; i++)
			if (!checked[i][COL])
				return 0; // 하나라도 x면 빙고 아님.
		return 1;
	}

	public static int checkLeftDiagonal() {
		for (int i = 0; i < 5; i++)
			if (!checked[i][i])
				return 0;
		return 1;
	}

	public static int checkRightDiagonal() {
		for (int i = 0; i < 5; i++)
			if (!checked[i][4 - i])
				return 0;
		return 1;
	}

	// line이 3이 되면 return true
	public static boolean checkBoard(int num) {
		// 위치 찾기
		Point position = findPosition(num);
		checked[position.x][position.y] = true;
		// 행
		if ((lines += checkRow(position)) == 3)
			return true;
		// 열
		if ((lines += checkCol(position)) == 3)
			return true;
		// 대각선1
		if (position.x == position.y) {
			if ((lines += checkLeftDiagonal()) == 3)
				return true;
		}

		// 대각선2
		if (position.x + position.y == 4) {
			if ((lines += checkRightDiagonal()) == 3)
				return true;
		}

		// 아직 3 안됨 --> false 리턴
		return false;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// 보드판 입력
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++)
				board[i][j] = Integer.parseInt(st.nextToken());
		}
		// 숫자 부르기
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				++cnt;
				if (checkBoard(Integer.parseInt(st.nextToken())))
					break;
			}//break 됐으면 마저 break
			if(lines == 3)
				break;
		}
		// 숫자 프린트
		System.out.println(cnt);

	}
}