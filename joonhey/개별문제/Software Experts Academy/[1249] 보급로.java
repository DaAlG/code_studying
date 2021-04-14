package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution{
	
	static class Node{
		int x;
		int y;
		int cost;
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static int[][] map;
	static int[][] total; //해당 경로까지 가는 최소값 누적 기록.
	static int[] di = {-1,1,0,0};
	static int[] dj = {0,0,-1,1};
	static int N;
	static Queue<Node> queue; //방문 기록용.
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		queue = new LinkedList<>(); // 어차피 빌테니까.
		StringBuilder sb = new StringBuilder("");
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			total = new int[N][N];
			//경로까지 최소 누적 합. 업데이트 할것임.
			for(int i=0; i<N; i++)
				Arrays.fill(total[i], Integer.MAX_VALUE);
			//지도입력
			for(int i=0; i<N; i++) {
				char[] inputLine = br.readLine().toCharArray();
				int j = 0;
				for(char c : inputLine)
					map[i][j++] = Integer.parseInt(Character.toString(c));
			}
			
			//출발지 입력
			queue.add(new Node(0,0));
			total[0][0] = 0;
			int ni, nj;
			while(!queue.isEmpty()) {
				Node cur = queue.poll();
				int curX = cur.x;
				int curY = cur.y;
				//사방탐색
				for(int d=0; d<4; d++) {
					ni = curX+ di[d];
					nj = curY + dj[d];
					//범위 내이고, 최소경로 업데이트 가능할 때 -> 같으면 굳이 안감: 0 0 일대 재 방문 방지.
					if(ni >=0 && nj >=0 && ni < N && nj<N && total[ni][nj] < total[curX][curY] + map[ni][nj]) {
						total[ni][nj] = total[curX][curY] + map[ni][nj];
						queue.offer(new Node(ni, nj));
					}
				}
			}
			//정답 출력
			sb.append("#"+t+" "+total[N-1][N-1]).append("\n");
		}
		System.out.println(sb);
	}
}