import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static char city[][];
	static ArrayList<Chicken> chickens;
	static ArrayList<House> houses;
	static int minDistSum;
	static int N, M;
	static ArrayList<Chicken> selectedChicks;
	static int cntT;

	static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Chicken {
		Point position;

		public Chicken(Point position) {
			this.position = position;
		}

	}

	static class House {
		Point position;
		Chicken favChicken; // 가장 가까운 치킨집 객체
		int chickenDist;

		public House(Point position) {
			this.position = position;
		}
	}

	public static int getDistance(Point p1, Point p2) {
		return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
	}

	public static int sumChickenDist() {
		int sum = 0;
		int minDist, tempDist;
		for (House h : houses) {
			if (!selectedChicks.contains(h.favChicken)) {
				minDist = Integer.MAX_VALUE;
				for (Chicken sc : selectedChicks) {
					tempDist = getDistance(sc.position,h.position);
					if(minDist > tempDist) {
						minDist = tempDist;
					}
				}//다 정함
				sum += minDist;
			} else {
				sum += h.chickenDist;
			}
		}

		return sum;
	}

	public static void updateFavChicken() {
		int minDist;
		Chicken favChicken = null;
		int dist;

		for (House h : houses) {
			minDist = Integer.MAX_VALUE; // 각 집별 치킨거리.
			for (Chicken c : chickens) {
				dist = getDistance(h.position, c.position);
				if (minDist > dist) {
					minDist = dist;
					favChicken = c;
				}
			}
			h.favChicken = favChicken;
			h.chickenDist = minDist;
		}

	}

	public static void subset(int cnt) {
		if (cnt == chickens.size()) {
			int selectedSize = selectedChicks.size();
			if (selectedSize >= 1 && selectedSize <= M) {
				int sum = sumChickenDist();
				if (minDistSum > sum) {
					minDistSum = sum;
				}
			}

			return;
		}
		selectedChicks.add(chickens.get(cnt));
		subset(cnt + 1);
		selectedChicks.remove(chickens.get(cnt));
		subset(cnt + 1);

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		city = new char[N][N];
		houses = new ArrayList<>();
		chickens = new ArrayList<>();
		selectedChicks = new ArrayList<>();
		minDistSum = Integer.MAX_VALUE;
		
		int k;
		String inputLine;
		char input;

		for (int i = 0; i < N; i++) {
			k = 0;
			inputLine = br.readLine();
			for (int j = 0; j < 2 * N; j += 2) {
				input = inputLine.charAt(j);
				city[i][k++] = input;
				switch (input) {
				case '1': 
					houses.add(new House(new Point(i, k - 1)));
					break;
				case '2':
					chickens.add(new Chicken(new Point(i, k - 1)));
					break;
				}
			}

		}
		updateFavChicken();
		subset(0);
		System.out.println(minDistSum);

	}
}
