package ahah;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static int[] dp;
	static int N,C;
	static class City implements Comparable<City>{
		int money;
		int people;
		
		@Override
//		금액 순으로 정렬
		public int compareTo(City o) {
			return this.money - o.money;
		}
		
		public City(int money, int people) {
			this.money = money;
			this.people = people;
		}
		
	}
	static City[] cities;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		C = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
//		도시 입력받기
		cities = new City[N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			cities[i] = new City(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
//		금액 순으로 소팅
		Arrays.sort(cities);
//		최대 'C01원'
		dp = new int[C*100+1];
		boolean found = false;
//		1원부터 최대 몇 명 가능한지 기록
		int curMoney = 0;
		while(!found) {
			curMoney++;
			for(int i=0; i<N; i++) {
				City city =cities[i];
				if(city.money > curMoney)
					break;
//				그 금액으로 몇 명 가능한지 기록
				dp[curMoney] = Math.max(dp[curMoney], dp[curMoney-city.money]+city.people);
				if(dp[curMoney] >= C) {
					found = true;
					break;
				}
			}
		}
		System.out.println(curMoney);
	}
}