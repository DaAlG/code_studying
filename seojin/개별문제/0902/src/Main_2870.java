import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main_2870 {

	static int N;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		// compile: 패턴 만들기
		Pattern p = Pattern.compile("\\d+"); // \d(숫자)+(하나 이상) : 숫자 여러개 있을 수 있다
		ArrayList<String> list = new ArrayList<>();
		
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			Matcher m = p.matcher(str); // p.matcher(str) : p가 str과 패턴이 일치한다면 true 반환
			
			while(m.find()) { // 대상 문자열과 패턴이 일치하는 경우 true를 반환하고, 그 위치로 이동한다.
				String s = m.group().replaceAll("^0+",""); // group() : 매칭된 부분 반환!
			
				if(s.length()==0) list.add("0"); // 길이가 0이면 원래 0이었는데 내가 지운거니까 0 넣기
				else list.add(s); // 나머지의 경우 그대로 넣기~
			}
		}
		
		Collections.sort(list, new Comparator<String>() {

			@Override
			public int compare(String o1, String o2) {
				if(o1.length() == o2.length()) {
					return o1.compareTo(o2);
				}
				return o1.length()-o2.length();
			}
		});
		
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));
		}
		
	}

}
