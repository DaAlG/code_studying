import java.util.HashMap;

class Solution {

	static class Point { // 키패드 및 손가락 좌표를 나타내기 위함
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static StringBuilder sb = new StringBuilder("");
	static HashMap<Integer, Point> map = new HashMap<>(); // 숫자에 따른 좌표값 메핑
	// 왼손, 오른쪽의 현재 위치.
	static Point curLeft = new Point(3, 0);
	static Point curRight = new Point(3, 2);

	public static void moveLeftFinger(Point dest) {
		curLeft = dest;
		sb.append("L");
	}

	public static void moveRightFinger(Point dest) {
		curRight = dest;
		sb.append("R");
	}

	// a좌표와 b좌표 거리 반환.
	public static int getDistance(Point a, Point b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}

	// 특정 키패드 에 따른 손가락 이동.
	public static void moveFinger(int number, String hand) {
		//해당 숫자의 위치 좌표
		Point numPos = map.get(number);
		// 왼손 위치 바꾸기
		if (number % 3 == 1) {
			moveLeftFinger(numPos);
		}
		// 오른손 위치 바꾸기
		else if (number % 3 == 0 && number != 0) {
			moveRightFinger(numPos);
		}
		// 거리로 판단
		else {
			int leftDistance = getDistance(curLeft, numPos);
			int rightDistance = getDistance(curRight, numPos);

			if (leftDistance == rightDistance) { //거리가 같을 때
				if (hand.equals("right"))
					moveRightFinger(numPos);
				else
					moveLeftFinger(numPos);
			} else if (leftDistance < rightDistance){
				moveLeftFinger(numPos);
			}
			else {
				moveRightFinger(numPos);
			}
		}
	}

	public String solution(int[] numbers, String hand) {
		// 좌표 초기화
		map.put(1, new Point(0, 0));
		map.put(2, new Point(0, 1));
		map.put(3, new Point(0, 2));
		map.put(4, new Point(1, 0));
		map.put(5, new Point(1, 1));
		map.put(6, new Point(1, 2));
		map.put(7, new Point(2, 0));
		map.put(8, new Point(2, 1));
		map.put(9, new Point(2, 2));
		map.put(0, new Point(3, 1));

		for (int number : numbers) {
			moveFinger(number, hand);
		}
		String answer = sb.toString();
		return answer;
	}

}