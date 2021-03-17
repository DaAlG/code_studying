package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	static char[][] screen;

	public static void recursiveCompress(int N, int startX, int startY) {
		boolean flag = false;
		char startVal = screen[startX][startY];

		for (int i = startX; i < startX + N; i++) {
			for (int j = startY; j < startY + N; j++) {
				if(screen[i][j] != startVal) {
					flag = true;
					break;
				}
			}
		}
		
		if(flag) { //재귀 필요 - 4분할.
			System.out.print("(");
			recursiveCompress(N/2, startX, startY);
			recursiveCompress(N/2, startX, startY + N/2);
			recursiveCompress(N/2, startX+N/2, startY);
			recursiveCompress(N/2, startX+N/2, startY+N/2);
			System.out.print(")");
		}
		else { //걍 출력.
			System.out.print(startVal);
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		screen = new char[N][N];
		String inputLine;

		for (int i = 0; i < N; i++) {
			inputLine = br.readLine();
			for (int j = 0; j < N; j++) {
				screen[i][j] = inputLine.charAt(j);
			}
		}

		recursiveCompress(N, 0, 0);
	}
}