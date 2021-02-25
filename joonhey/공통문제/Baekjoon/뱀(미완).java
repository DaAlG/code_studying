package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

class Main {
	static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public boolean equals(Object o) {
			Point p = (Point) o;
			return this.x == p.x && this.y == p.y;
		}

		// 해쉬에서 사용
		@Override
		public int hashCode() {
			return Integer.toString(this.x + this.y).hashCode();
		}
	}

	static HashSet<Point> apples; // 사과 위치
	static HashMap<Integer, Character> turnMap; // 시간, 전환방향
	static int cnt; // 경과시간
	static ArrayList<Point> snake;
	static int N; // 보드 크기
	static int k; // 현재 뱀의 이동 방향(상하좌우)
	static int[] di = { -1, 1, 0, 0 };
	static int[] dj = { 0, 0, -1, 1 };

	// 머리만 움직이고 몸통이 따라가므로 종료 여부는 몸통 말고 머리로만 판단.
	public static int moveSnake(Point headPos) {
		// 현위치 안전? - 범위, 자신의 몸과 충돌여부 체크
		if (headPos.x > N || headPos.x < 0 || headPos.y > N || headPos.y < 0)
			return cnt;

		// 뱀 크기, 위치 업데이트
		snake.add(headPos);

		// head 이미 추가 됐으니까 그 전까지만 탐색
		for (int i = 0; i < snake.size() - 1; i++) {
			if (headPos.equals(snake.get(i)) && cnt != 0)
				return cnt;
		}

		if (!apples.contains(headPos))// 사과가 없으면 꼬리 자르기, !!사과 먹기 !!
		{
			apples.remove(headPos);
			snake.remove(0);
		}

		// 다음방향계산
		if (turnMap.get(cnt) != null) {
			switch (turnMap.get(cnt)) {
			// 기존 방향에 따라서 전환을 왼쪽/오른쪽으로 할 때 이동 방위가 달라진다
			case 'L':
				k = k < 2 ? k + 2 : 3 - k;
				break;
			case 'D':
				k = k < 2 ? 3 - k : k - 2;
			}
		}

		// 다음 시간, 위치 업뎃
		cnt++;
		// 새로운 객체를 생성해서 넣어줘야한다...배열 속에서 그 객체의 주소를 가리키고 있으므로.
		return moveSnake(new Point(headPos.x + di[k], headPos.y + dj[k]));
	}

	public static void main(String[] args) throws IOException {

		// 생성
		apples = new HashSet<>();
		turnMap = new HashMap<>();
		snake = new ArrayList<>();
		k = 3; // 처음에 우측으로 기어감
		snake.add(new Point(1, 1)); // 처음 시작 위치 1,1

		// 입력값 처리
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		int K = Integer.parseInt(br.readLine());

		// 사과 위치 입력
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			apples.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}

		// 전환 방향, 시간 입력
		int L = Integer.parseInt(br.readLine());
		for (int i = 0; i < L; i++) {
			st = new StringTokenizer(br.readLine());
			turnMap.put(Integer.parseInt(st.nextToken()), st.nextToken().charAt(0));
		}
		// 1,1부터 시작함에 유의.(1~N칸까지 있다 가정)
		moveSnake(snake.get(0));
		// 출력
		System.out.println(cnt);
	}

}