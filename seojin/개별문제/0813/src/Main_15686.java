import java.io.*;
import java.util.*;

public class Main_15686 {
	
	static int N, M;
	static int[][] city;
	static ArrayList<Node> house = new ArrayList<>();
	static ArrayList<Node> chicken = new ArrayList<>();
	
	static int h,c;
	static int[][] htoc;
	
	static int[] src;
	static int[] tgt; // 치킨집의 인덱스 배열
	
	static int result = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken()); // 남겨둘 치킨집 수
		
		city = new int[N][N]; // 도시 정보 0: 빈칸, 1: 집, 2: 치킨집
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				city[i][j] = Integer.parseInt(st.nextToken());
				
				if(city[i][j] == 1) house.add(new Node(i,j)); // 집 위치
				else if(city[i][j] == 2) chicken.add(new Node(i,j)); // 치킨집 위치
			}
		}

		// 집에서 각 치킨집까지 거리구하기
		h = house.size(); // 집 개수
		c = chicken.size(); // 치킨집 개수
		htoc = new int[h][c]; 
		houseTochicken(); 
		
		// 치킨집 조합 구하기
		tgt = new int[M];
		src = new int[c];
		for(int i=0;i<c;i++) src[i] = i;
		comb(0,0); // 각 치킨집-집 거리를 미리 구해두고 조합 구할 때 값만 꺼내오는 방법.
//		comb2(0,0); // 치킨집-집 거리를 조합 구할때마다 새로 구하는 방법 : 더 오래걸리고 메모리도 더 많이 씀!!
		
		System.out.println(result);
	}
	
	
	static void comb(int srcIdx, int tgtIdx) {
		
		if(tgtIdx == tgt.length) { // M개 다 찾았으면
			// 도시의 치킨거리 계산
			
			int cityd = 0;
			
			for (int i = 0; i < h; i++) {
				int minc = Integer.MAX_VALUE;
				for(int j : tgt) {
					minc = Math.min(minc, htoc[i][j]);
				}
				cityd += minc;
			}
			
			result = Math.min(result, cityd);
			
			return; 
		}
		if(srcIdx == c) return; // 더이상 볼게 없으면
		
		tgt[tgtIdx] = src[srcIdx];
		comb(srcIdx+1, tgtIdx+1);
		comb(srcIdx+1, tgtIdx);
	}
	
	static void comb2(int srcIdx, int tgtIdx) {
		int hy, hx, cy, cx;
		if(tgtIdx == tgt.length) { // M개 다 찾았으면
			// 도시의 치킨거리 계산
			
			int cityd = 0;
			
			for (int i = 0; i < h; i++) {
				int minc = Integer.MAX_VALUE;
				hy = house.get(i).y;
				hx = house.get(i).x;
				for(int j : tgt) {
					cy = chicken.get(j).y;
					cx = chicken.get(j).x;
					int temp = Math.abs(hy-cy)+Math.abs(hx-cx);
					minc = Math.min(minc, temp);
				}
				cityd += minc;
			}
			
			result = Math.min(result, cityd);
			
			return; 
		}
		if(srcIdx == c) return; // 더이상 볼게 없으면
		
		tgt[tgtIdx] = src[srcIdx];
		comb2(srcIdx+1, tgtIdx+1);
		comb2(srcIdx+1, tgtIdx);
	}
	

	
	static void houseTochicken() {
		int hy, hx, cy, cx;
		
		for (int i = 0; i < h; i++) {
			hy = house.get(i).y;
			hx = house.get(i).x;
			for (int j = 0; j < c; j++) {
				cy = chicken.get(j).y;
				cx = chicken.get(j).x;
				htoc[i][j] = Math.abs(hy-cy)+Math.abs(hx-cx);
			}
		}
		
	}
	

}

//class Node{
//	int y;
//	int x;
//	
//	public Node(int y, int x) {
//		this.y = y;
//		this.x = x;
//	}
//}