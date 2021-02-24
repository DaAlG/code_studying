package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//순열로 집의 순서를 정하되, 최소 거리를 넘어서면 가지치기한다.
//회사와 집의 위치는 0과 N+1번째 인덱스에 고정이다.
public class Solution {
	static class Point{
		int x; 
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static Point[] places;
	static int N;
	static int minDist;
	static boolean[] isSelected;
	static Point[] turn; 
	//places 중에 고객 집 순열 완성본 저장. 0번과 마지막 번호는 회사와 집으로 고정임.
	
	public static int getDistance(Point a, Point b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}
	
	public static void perm(int cnt, int curDist) {
		
		if(curDist > minDist)
			return; //가지치기
		
		if(cnt == N+1) {//집 다 고름
			//마지막 고객 - 집 사이 거리 추가.
			curDist += getDistance(turn[cnt-1], turn[cnt]);
			if(curDist < minDist)
				minDist = curDist;
			return;
		}
		
		for(int i=1; i<=N; i++) {
			if(!isSelected[i]) {
				isSelected[i] = true;
				turn[cnt] = places[i];
				perm(cnt+1, curDist + getDistance(turn[cnt-1], turn[cnt]));
				isSelected[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(br.readLine());
			StringBuilder sb = new StringBuilder("#").append(t).append(" ");
			places = new Point[N+1]; //고객집들
			isSelected = new boolean[N+1]; //1~N
			turn = new Point[N+2]; //회사 - 고객집들 - 집.
			minDist = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			//회사 좌표
			turn[0] = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			//집 좌표
			turn[N+1] = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			//고객집들(원본)
			for(int i=1; i<=N; i++) {
				places[i] = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
			}
			
			perm(1, 0);
			
			//출력
			System.out.println(sb.append(minDist));
		}
	}
}
