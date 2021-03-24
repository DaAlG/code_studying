package day0323;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//1. dfs로 안터뜨리기
//2. bfs로 해보기.

public class Main {
	static int[] num;
	static Queue<Integer> count;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		num = new int[n + 1];
		count = new LinkedList<>();
		
		count.add(n);
		while(!count.isEmpty()) {
			int cur = count.poll();
			int curCount = num[cur];
			if(cur % 3 == 0 && (num[cur/3] == 0 || num[cur/3] > curCount + 1)) {
				num[cur/3] = curCount + 1;
				count.add(cur/3);
			}
			if(cur % 2 == 0 && (num[cur/2] == 0 || num[cur/2] > curCount + 1)) {
				num[cur/2] = curCount + 1;
				count.add(cur/2);
			}
			if(cur - 1 >= 1 && (num[cur-1] == 0 || num[cur-1] > curCount + 1)) {
				num[cur - 1] = curCount + 1;
				count.add(cur - 1);
			}
		}
		
		System.out.println(num[1]);
	}
}