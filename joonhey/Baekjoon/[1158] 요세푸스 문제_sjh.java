package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Integer> people = new ArrayList<>();
	static int N, K;
	static StringBuilder sb = new StringBuilder("<");
	
	public static void killPerson(int idx) {
		sb.append(Integer.toString(people.get(idx))).append(", ");
		people.remove(idx);
	}
	
	public static void killYosep(int startIdx, int cnt) {
		if(cnt == N)
			return;
		
		int killed = (startIdx + K - 1)%people.size();

		killPerson(killed);
		//해당 인덱스 kill
		killYosep(killed, cnt + 1);
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		for(int i=1; i<=N; i++)
			people.add(i);
		killYosep(0, 0);
		sb.setLength(sb.length()-2);
		sb.append(">");
		System.out.println(sb.toString());
		
	}
}
