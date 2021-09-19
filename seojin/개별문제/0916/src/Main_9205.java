// 9205 맥주 마시면서 걸어가기
import java.io.*;
import java.util.*;

public class Main_9205 {

	static int T, N;
	static int INF = 987654321;
	static Node[] info;
	static int[][] matrix;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			
			// 입력 처리
			N = Integer.parseInt(br.readLine()); // 편의점 개수
			info = new Node[N+2];
			for (int i = 0; i < N+2; i++) {
				st = new StringTokenizer(br.readLine());
				info[i] = new Node(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			}
			
			// 갈 수 있는지 정보 처리
			matrix = new int[N+2][N+2];
			for (int i = 0; i < N+2; i++) {
				for (int j = 0; j < N+2; j++) {
					if(i == j) continue;
					// 맨해튼 거리 1000 이내일 때만 갈 수 있음-> 1로 처리
					if(Math.abs(info[i].x-info[j].x)+Math.abs(info[i].y-info[j].y)<=1000) matrix[i][j]=1;
					else matrix[i][j] = INF;
				}
			}
			
			// 모든 경우에 대한 최단 거리 업데이트
			for (int k = 0; k < N+2; k++) {
				for (int i = 0; i < N+2; i++) {
					for (int j = 0; j < N+2; j++) {
						matrix[i][j] = Math.min(matrix[i][k]+matrix[k][j], matrix[i][j]);
					}
				}
			}

			// 시작점 0 -> 도착점 N+1 최단거리 테이블
			if(matrix[0][N+1] == INF) System.out.println("sad"); 
			else System.out.println("happy");
			
		}
		
	}
	
	static class Node{
		int x;
		int y;
		
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
