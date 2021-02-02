package workshop;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int[] boxes = new int[100];
	static int maxDump;
	static int highestIdx;
	static int shortestIdx;
	static int diff;

	//현재 최고 ~ 최저 차이 업데이트
	public static void updateDiff() {
		// 초기화
		int highestFloor = 0;
		int shortestFloor = 101;
		// 지금 상태 확인.
		for (int i = 0; i < 100; i++) {
			if (boxes[i] > highestFloor) {
				highestFloor = boxes[i];
				highestIdx = i; // 굳이 필요함 - dump 위해서.
			}
			if (boxes[i] < shortestFloor) {
				shortestFloor = boxes[i];
				shortestIdx = i;
			}
		}

		diff = highestFloor - shortestFloor;
	}

	public static int searchAndDump(int cnt) {
		
		updateDiff();
		
		if (diff <= 1)
			return diff;

		// dump & recursive
		boxes[highestIdx] -= 1;
		boxes[shortestIdx] += 1;

		// 최고점과 최저점이 바뀌므로 다시 탐색해야 함.
		updateDiff();

		if (cnt == maxDump)
			return diff;
		else
			return searchAndDump(cnt + 1);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for (int t = 1; t <= 10; t++) {
			int res = 0;
			maxDump = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < 100; i++) {
				boxes[i] = Integer.parseInt(st.nextToken());
			}

			res = searchAndDump(1);

			System.out.println("#" + t + " " + res);
		}
	}

}
