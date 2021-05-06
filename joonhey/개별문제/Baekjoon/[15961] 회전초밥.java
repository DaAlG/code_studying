package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

class Main {
	//전체 초밥 배열
	static int[] sushi;
	static Queue<Integer> queue;
	static int N;
	static int k;
	static HashMap<Integer,Integer> map; //초밥 종류 - 현재 개수.
	static int max;
	
	//i번째 스시를 먹는 경우 -> 가짓수 기록
	public static void addSushi(int s) {
		int value;
		if( map.get(s) == null)
			map.put(s, 1);
		else {
			value = map.get(s);
			map.put(s, value + 1);
		}
	}
	//i번째 스시를 제외하는 경우 -> 가짓수 감소
	public static void removeSushi(int s) {
		int value;
		value = map.get(s);
		value--;
		if(value == 0)
			map.remove(s);
		else
			map.put(s, value);
	}
	public static void main(String[] args) throws IOException {
		int c; //쿠폰번호.
		map = new HashMap<>();
		queue = new LinkedList<>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		sushi = new int[N];
		//d 씹기
		st.nextToken();
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
//		스시 목록 입력
		for(int i=0; i<N; i++) {
			sushi[i] = Integer.parseInt(br.readLine());
		}
		map.put(c, 1);
		int end =  k -1; // 끝
		//초반 큐 생성 -> 가짓수도 같이 ! 
		for(int i = 0; i<= end; i++) {
			queue.add(sushi[i]);
			addSushi(sushi[i]);
		}
		max = map.size();
		end = (end + 1 ) % 	N;
//		맨 처음 위치로 돌아오기 전에
		int curSize;
		while(end  != k - 1) {
			//맨 앞에꺼 out
			int out = queue.poll();
			//가짓수 아웃
			removeSushi(out);
			//뒤에 꺼 추가
			queue.offer(sushi[end]);
			addSushi(sushi[end]);
//			변경된 가짓수
			curSize = map.size();
			max = max > curSize ? max : curSize;
			end = (end + 1)% N;
		}
		System.out.println(max);
	}
}