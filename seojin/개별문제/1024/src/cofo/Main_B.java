package cofo;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main_B {
	
	static int T,N;
	static char[][] map;
	static List<Point> points;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			N = Integer.parseInt(br.readLine());
			points = new ArrayList<>();
			// map 
			map = new char[N][N];
			
			for (int i = 0; i < N; i++) {
				String str = br.readLine();
				for (int j = 0; j < N; j++) {
					char c = str.charAt(j);
					
					if(c != '*') continue; 
					
					 // 점이 이미 있다면 = 마지막 점 => 더이상 볼 필요 없음
					if(!points.isEmpty()) {
						points.add(new Point(i,j));
						break;
					}
					points.add(new Point(i,j)); // 아직 찾지 못했을 때
				}
			}
			
			// 점의 위치 2개 찾으면 저장! -> 리스트에 넣기 -> find하기 
			int fy = points.get(0).y; 
			int fx = points.get(0).x; 
			int sy = points.get(1).y; 
			int sx = points.get(1).x; 
			
			if(fy == sy) {
				//1. 점이 가로로 나열
				find1(fy, fx, sy, sx); 
			}else if(fx == sx) {
				//2. 점이 세로로 나열
				find2(fy, fx, sy, sx);
			}else {
				//3. 점이 대각선으로 나열
				find3(fy, fx, sy, sx);
			}
			
			// 바로 resultMap 만들어서 출력
			
			char[][] resultMap = new char[N][N];
			for (int i = 0; i < N; i++) {
				Arrays.fill(resultMap[i], '.');
			}
			
			for(Point p: points) {
				resultMap[p.y][p.x] = '*';
			}
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(resultMap[i][j]);
				}
				System.out.println();
			}
		}
	}
	
	private static void find3(int fy, int fx, int sy, int sx) {
		// 변의 길이
		int ylen = Math.abs(sy - fy);
		int xlen = Math.abs(sx - fx);
		
		if(fx < sx) {
			points.add(new Point(fy,fx+xlen));
			points.add(new Point(fy+ylen,fx));
		}else {
			points.add(new Point(fy,fx-xlen));
			points.add(new Point(fy+ylen,fx));
		}				
	}

	private static void find2(int fy, int fx, int sy, int sx) {
		if(fx-1<0) {
			points.add(new Point(fy,fx+1));
			points.add(new Point(sy,sx+1));
		}else {
			points.add(new Point(fy,fx-1));
			points.add(new Point(sy,sx-1));
		}
		
	}

	private static void find1(int fy, int fx, int sy, int sx) {
		if(fy-1<0) {
			points.add(new Point(fy+1,fx));
			points.add(new Point(sy+1,sx));
		}else {
			points.add(new Point(fy-1,fx));
			points.add(new Point(sy-1,sx));
		}
	}

	static class Point{
		int y, x;
		
		public Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
