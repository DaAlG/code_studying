import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution { 
	public static int[][] map;
	public static int n;
	public static int m;
	
	public static int hToB[][] = {
			{ 0, 0, 0, 0}, // 0
			{ 0, 0, 0, 1}, // 1
			{ 0, 0, 1, 0}, // 2
			{ 0, 0, 1, 1}, // 3
			{ 0, 1, 0, 0}, // 4
			{ 0, 1, 0, 1}, // 5
			{ 0, 1, 1, 0}, // 6
			{ 0, 1, 1, 1}, // 7
 			{ 1, 0, 0, 0}, // 8
			{ 1, 0, 0, 1}, // 9
			{ 1, 0, 1, 0}, // A
			{ 1, 0, 1, 1}, // B
			{ 1, 1, 0, 0}, // C
			{ 1, 1, 0, 1}, // D
			{ 1, 1, 1, 0}, // E
			{ 1, 1, 1, 1} // F
	};
	
	public static int cToNum[][][] = new int[5][5][5];
	public static void init() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++)
					cToNum[i][j][k] = -1;
			}
		}
		
		cToNum[2][1][1] = 0;
		cToNum[2][2][1] = 1;
		cToNum[1][2][2] = 2;
		cToNum[4][1][1] = 3;
		cToNum[1][3][2] = 4;
		cToNum[2][3][1] = 5;
		cToNum[1][1][4] = 6;
		cToNum[3][1][2] = 7;
		cToNum[2][1][3] = 8;
		cToNum[1][1][2] = 9;
	}
	
	public static int hexToDec(char ch) {
		if (ch >= '0' && ch <= '9') 
			return Character.getNumericValue(ch);
		return ch - 'A' + 10;
	}
	
	public static void makeMap(String[] tmp, int row) {
		for (int i = 0; i < m; i++) {
			int num = hexToDec(tmp[i].charAt(0));
			for (int j = 0; j < 4; j++)
				map[row][i * 4 + j] = hToB[num][j];
		}
	}
	

	public static int isValid(int row) {
		int code[] = new int[8];
		int codeLen = 7;
		int result = 0;
		
		for (int j = m * 4 - 1; j >= 0; j--) { // 오른쪽에서부터 암호코드 탐색
			int part[] = { 0, 0, 0 }; // 암호코드 비율
			
			if (map[row][j] == 1 && map[row - 1][j] == 0) { // 바코드 우상단
				while (map[row][j] == 1) { part[2]++; j--; }
				while (map[row][j] == 0) { part[1]++; j--; }
				while (map[row][j] == 1) { part[0]++; j--; }
				j++;
				
				// 가장 작은 값으로 나눠준다
				int min = Math.min(part[2], Math.min(part[1], part[0]));
				for (int k = 0; k < 3; k++)
					part[k] /= min;
				
				// 해당 코드에 매칭되는 숫자를 찾는다
				code[codeLen--] = cToNum[part[0]][part[1]][part[2]];
				
				// 8자리 숫자를 모두 다 찾은 경우
				if (codeLen == -1) {
					int sum = 0;
					int total = 0; // 암호코드 계산
					for (int i = 0; i < 8; i++) {
						sum += code[i];
						if (i % 2 == 0) total += 3 * code[i];
						else total += code[i];
					}
					
					if (total % 10 == 0)
						result += sum;
					
					// 다시 코드를 찾을 수 있도록 리셋
					codeLen = 7;
				}
			}
		}
		return result;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		init();
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String size[] = br.readLine().split(" ");
			n = Integer.parseInt(size[0]);
			m = Integer.parseInt(size[1]);
		
			map = new int[n][m * 4];
		
			int answer = 0;
			String before = "";
			
			for (int i = 0; i < n; i++) {
				String now = br.readLine();
				
				if (i == 0 || now.equals(before)) {
					before = now;
					continue;
				}
				
				// 암호코드 계산을 위한 map을 만든다
				makeMap(before.split(""), i - 1);
				makeMap(now.split(""), i);
				
				// 암호코드 계산
				answer += isValid(i);
				before = now;
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}
