import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static int map[][] = new int[100][100];
	
	public static void main(String args[]) throws Exception {
		StringBuilder sb = new StringBuilder();
		int T = 10;

        for(int test_case = 1; test_case <= T; test_case++) {
        	int n = Integer.parseInt(br.readLine());
        	
        	StringTokenizer st;
        	for (int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine(), " ");
        		for (int j = 0; j < n; j++) {
        			map[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	
        	int answer = 0;
        	for (int j = 0; j < n; j++) {
        		int spole = 0;
        		for (int i = 0; i < n; i++) {
        			if (map[i][j] == 2 && spole == 1) {
        				answer++;
        				spole = 0;
        			}
        			else if (map[i][j] == 1) spole = 1;
        		}
        	}        	
        	sb.append("#").append(test_case).append(" ").append(answer);
        	System.out.println(sb);
		}
	}
}