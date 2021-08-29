package BOJ.BOJ_19598;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// BOJ 19598 최소 회의실 개수
public class Main {
	
	private static int n;
	private static int[][] time;
	
	private static int solve() {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.add(time[0][1]);  // 첫 회의가 끝나는 시간을 우선순위 큐에 넣는다
		
		for (int i = 1; i < time.length; i++) {
			// 이전 회의가 끝나는 시간과 같거나 그 이후여야 같은 회의실을 쓸 수 있다
			// 다음에 진행할 수 있는 회의면 이전 회의를 우선순위 큐에서 꺼낸다
			if (time[i][0] >= pq.peek()) {
				pq.poll();
			}
			// 현재 회의를 우선순위 큐에 넣는다
			pq.add(time[i][1]);
		}
		
		// 우선순위 큐에 남아있는 회의의 수가 최소 회의실 개수
		return pq.size();
	}
	
	public static void main(String[] args) throws IOException {

		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(bw.readLine());
		time = new int[n][2];
		for (int i = 0; i < n; i++) {
			String[] input = bw.readLine().split(" ");
			time[i][0] = Integer.parseInt(input[0]);
			time[i][1] = Integer.parseInt(input[1]);
		}
		
		// 시작 시간에 대한 오름차순으로 정렬
		Arrays.sort(time, new Comparator<int[]>() {
			@Override
			public int compare(int[] a, int[] b) {
				if (a[0] == b[0]) {
					return a[1] - b[1];
				}
				return a[0] - b[0];
			}
		});
		
		System.out.println(solve());
	}
}
