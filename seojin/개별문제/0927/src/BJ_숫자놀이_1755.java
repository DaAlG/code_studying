// 알고리즘 월말평가 1번

import java.io.*;
import java.util.*;

public class BJ_숫자놀이_1755 {

	static Map<Integer, String> map;
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); 
		ArrayList<Num> list = new ArrayList<>(); // 숫자와 문자로 변환한 숫자 저장
		StringBuilder sb = new StringBuilder(); // 출력 저장
			
		map = new HashMap<>(); // 숫자-> 문자로 저장하기 위한 map
		
		numberToString(); // map에 숫자->문자 대응시켜서 저장해두기
		
		// 입력 처리
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		// M~N까지 숫자 탐색
		for(int i=M; i<=N; i++) {
			char[] num = Integer.toString(i).toCharArray(); // 숫자를 자릿수로 나누어 보기 위함
			String res = ""; // 문자열 저장
			for(char c : num) { // 각 자리수를 보며
				res += map.get(c-'0'); // map에서 해당하는 문자열을 연결한다
			}
			list.add(new Num(i, res)); // 리스트에 숫자에 해당하는 문자열을 숫자와 함께 저장
			
		}
	
		// 사전 순 정렬
		Collections.sort(list, new Comparator<Num>() {

			@Override
			public int compare(Num o1, Num o2) {
				
				return o1.word.compareTo(o2.word); // 문자열 사전 순으로 정렬
			}

		});
		
		// 출력 처리
		int index = 0;
		for(Num n : list) {
			sb.append(n.number).append(" ");
			if(index == 9) { // 10개를 출력했다면
				sb.append("\n"); // 다음줄로 넘어간다
				index = 0;
			}
			else index++;
		}
		
		System.out.println(sb.toString());
	}

	static void numberToString() {
		
		map.put(0, "zero");
		map.put(1, "one");
		map.put(2, "two");
		map.put(3, "three");
		map.put(4, "four");
		map.put(5, "five");
		map.put(6, "six");
		map.put(7, "seven");
		map.put(8, "eight");
		map.put(9, "nine");
		
	}
	
	// 숫자와 문자열을 함께 저장하기 위한 클래스
	static class Num{
		int number;
		String word;
		
		public Num(int number, String word) {
			this.number = number;
			this.word = word;
		}
	}
	

}
