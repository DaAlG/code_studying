import java.io.*;

public class Main_14405 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = br.readLine();

		// String.matches() : 특정 패턴의 문자열을 포함하는지 알 수 있음
		// boolean으로 일치하는지 여부 판단
		String res = s.matches("(pi|ka|chu)*") ? "YES" : "NO";
		System.out.println(res);
		
	}
}
