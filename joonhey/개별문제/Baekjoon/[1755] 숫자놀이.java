import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static int M, N; //1 <= M, N <= 99
	static HashMap<Character, String> map; //정수와 영어 매핑 (숫자)
	static HashMap<String, Integer> strMap; //정수와 영어 매핑 (수)
	static String[] strArr; //바뀐 영단어 저장하고 사전순 정렬
	
	//num을 영어로 읽은 결과 문장 리턴
	public static String readInEnglish(int num) {
		StringBuilder sb = new StringBuilder("");
		//String과 다르게 이어붙일 수 있어서
		char[] str = Integer.toString(num).toCharArray();
		//한 글자씩 떼내기 위해 -> %, / 연산은 한계
		for(char c : str) {
			//숫자 하나당 단어 하나 메핑해서 sb에 덧붙여주기.
			sb.append(map.get(c)).append(" ");
		}
		return sb.toString(); //반환형이 sb가 아닌 이유? 정렬시키기 위해.
	}
	//정렬된 수 출력
	public static void printArr() {
		StringBuilder sb = new StringBuilder("");
		int cnt = 0;
		for(String s : strArr) {
			cnt++;
			sb.append(strMap.get(s)).append(" ");
			//한 줄에 열 개씩
			if(cnt % 10 == 0)
				sb.append("\n");
		}
		System.out.println(sb);
	}
	public static void main(String[] args) {
		//맵 초기화 -> 숫자 별 영어 저장
		map = new HashMap<>();
		strMap = new HashMap<>();
		map.put('0', "zero");
		map.put('1', "one");
		map.put('2', "two");
		map.put('3', "three");
		map.put('4', "four");
		map.put('5', "five");
		map.put('6', "six");
		map.put('7', "seven");
		map.put('8', "eight");
		map.put('9', "nine");
		
		//M, N 입력받기 -> 입력받는 값이 두개뿐이므로 BufferdReader 말고 scanner 사용해도 큰 차이X
		Scanner sc = new Scanner(System.in);
		int first, second;
		first = sc.nextInt();
		second = sc.nextInt();
		M = first <= second ? first : second;
		N = first == M ? second : first;
		strArr = new String[N - M + 1];
		String str; //각 정수를 영어로 읽은 문장.
		int cnt = 0;
		for(int i=M; i<=N; i++) {
			//정수 받으면 영어로 변환하여 str에 저장
			str = readInEnglish(i);
			strArr[cnt++] = str;
			//출력할 땐 숫자로 하니까 따로 저장 필요.
			strMap.put(str,i);
		}
		//사전순 정렬
		Arrays.sort(strArr);
		//출력
		printArr();
	}
}