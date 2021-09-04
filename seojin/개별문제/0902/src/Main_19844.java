import java.io.*;
import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Main_19844 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String sen = br.readLine();
		
		String[] list = sen.split("[- ]"); // 정규식 [xy] : xy중 하나 선택
//		for (String s : list) {
//			System.out.println(s);
//		}
		int cnt = list.length; // 띄어쓰기, dash로 나뉜 단어 개수
		

		Pattern p = Pattern.compile("^(c|j|n|m|t|s|l|d|qu)'[aeiouh]");
		for (int i = 0; i < list.length; i++) {

			Matcher m = p.matcher(list[i]);
			while(m.find()) {
//				System.out.println(m);
				cnt++; // 거기에'로 쪼개지는 횟수 더하기!
			}
			
		}
		
		System.out.println(cnt);
	}

}
