package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

/*
 * 주사위를 굴린다기보단 
 * 알까기 하듯 한 면씩 돌리고 밀어낸다는
 * 느낌이 맞는듯.
 * */
class Main {
	
	/* 현재 주사위 배치도
	 *   2    
	 * 4 1 3 6 => dice_garo
	 *   5
	 *   6
	 *   => dice_sero
	 * */
	
	static LinkedList<Integer> dice_garo; 
	//윗면에서부터 서쪽으로 360도 스캔한 주사위 인덱스 배치 -> 동쪽으로 옮길 경우 이 순서대로 윗면이 바뀜 
	static LinkedList<Integer> dice_sero; 
	//윗면에서부터 북쪽으로  360도 스캔한 주사위 인덱스 배치 -> 남쪽으로 옮길경우 이 순서대로 윗면이 바뀜.
	
	/*
	 *	각자 0, 2 번째 원소는 주사위의 윗면과 아랫면이므로 dice_garo, dice_sero 의  0,2번 인덱스는 동일하다.
	 *  (-> 이유: 스캔을 동쪽으로 하든, 남쪽으로 하든 윗면 밑 아랫면은 공통으로 스캔됨.)
	 *  특정 방향으로 굴리는것에 따라 인덱스의 배치가 오른쪽으로, 혹은 반대 순서대로 순환한다. -> 0,2번에 윗면과 아랫면을 배치시키기 위해 
	 *  배열 원소의 맨 앞원소를 빼서 맨 뒤에 붙여주거나, 반대의 경우 배열 원소의 맨 뒷 원소를 빼서 앞에 붙여준다.
	 *  예시) 주사위의 북쪽으로 스캔한 배치가 윗면에서부터 1->2->6->5 라면 주사위를 남쪽으로 굴렸을때 주사위의 세로 배치는 2->6->5->1이 되고, 북쪽으로 굴리면 5->1->2>6이 됨.
	 * */
	static int[] dice;
	static int curX, curY; // 주사위 현재 위치
	static int[] di = { 0, 0, 0, -1, 1 };
	static int[] dj = { 0, 1, -1, 0, 0 };// 주사위 좌표 계산 용 - 동, 서 ,북, 남
	static int[][] map; // 지도
	static int N, M; // 지도 너비, 높이
	static StringBuilder sb;
	static int curAbove, curBeneth; //현재 윗면, 밑면 배치 번호.
	
	// 주사위 굴리기.
	public static void rollDice(int dir) {
		//이동 방향에 따라 주사위 배치가 바뀜
		//동, 서
		if(dir < 3) {
			//동
			if(dir == 1) {
				dice_garo.addLast(dice_garo.poll());
			}
			//서
			else {
				dice_garo.addFirst(dice_garo.pollLast());
			}
			//세로부분의 윗면, 아랫면도 이에 따라 교체
			dice_sero.set(0, dice_garo.get(0));
			dice_sero.set(2, dice_garo.get(2));
		}
		//북, 남
		else {
			//북
			if(dir == 3) { 
				dice_sero.addFirst(dice_sero.pollLast());
			}
			//남
			else {
				dice_sero.addLast(dice_sero.poll());
			}
			//가로부분의 윗면, 아랫면도 이에 따라 교체
			dice_garo.set(0, dice_sero.get(0));
			dice_garo.set(2, dice_sero.get(2));
		}
		//이때의 [0]이 위, [2]이 밑면
		curAbove = dice_garo.get(0);
		curBeneth = dice_garo.get(2);
	}

	// 주사위 이동하기.
	public static void moveDice(int dir) {
		// 범위 체크
		int ni = curX + di[dir];
		int nj = curY + dj[dir];

		// 통과 했을 때만 이동.
		if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
			// 주사위 모양이 바뀌고,(굴리기)
			rollDice(dir); //이 때 아랫면과 윗면도 바뀜.
		
			// 주사위 위치가 바뀐다.
			curX = ni;
			curY = nj;
		
			// 위치한 칸에 따라 복붙이 이루어진다.
			if(map[curX][curY] == 0) {//바닥면 지도에 복사.
				map[curX][curY] = dice[curBeneth];
			}
			else {//주사위의 바닥면으로 복사.
				dice[curBeneth] = map[curX][curY];
				map[curX][curY] = 0;
			}
			// 윗면 출력
			sb.append(dice[curAbove]).append("\n");
		}
//		System.out.println("현위치 "+curX+" "+curY);
//		System.out.println("주사위 상태" +Arrays.toString(dice));

	}

	public static void main(String[] args) throws IOException {
		//객체 생성
		dice = new int[7]; // 1 ~ 6 번 인덱스의 숫자 값
		dice_garo = new LinkedList<>();
		dice_sero = new LinkedList<>();
		
		//가로 스캔 ->1,4,6,3
		dice_garo.add(1); 
		dice_garo.add(4); 
		dice_garo.add(6); 
		dice_garo.add(3);
		
		//세로 스캔 ->1,2,6,5
		dice_sero.add(1); 
		dice_sero.add(2); 
		dice_sero.add(6); 
		dice_sero.add(5);
		
		sb = new StringBuilder(""); // 출력 저장용
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		curX = Integer.parseInt(st.nextToken());
		curY = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken()); // 명령어 수.

		// 지도 입력받기
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < K; i++) {
			moveDice(Integer.parseInt(st.nextToken()));
		}

		// 명령어 대로 이동 후, 정답 출력
		System.out.println(sb);

	}
}