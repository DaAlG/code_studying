import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	static HashSet<Position> points = new HashSet<>();
	static class Position{
		int x; int y;
		public Position(int x, int y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public boolean equals(Object o) {
			Position pos = (Position)o;
			return pos.x == this.x && pos.y == this.y;
		}
		@Override
		public int hashCode() {
			String s = Integer.toString(this.x)+Integer.toString(this.y);
			return s.hashCode();
		}
		
	}
	public static void fillBoard(int startY, int startX) {
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				points.add(new Position(startX + i, startY + j));
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for(int t=0; t<T; t++) {
			st = new StringTokenizer(br.readLine());
			fillBoard(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		System.out.println(points.size());
	
	}
}