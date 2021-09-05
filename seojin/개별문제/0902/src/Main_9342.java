import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.*;

public class Main_9342 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		Pattern p = Pattern.compile("^[ABCDEF]?A+F+C+[ABCDEF]?$"); // 패턴 조건
		
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			System.out.println(p.matcher(str).matches() ? "Infected!" : "Good"); 
		}
	}
}



//for (int i = 0; i < N; i++) {
//	String str = br.readLine();
//	Pattern p = Pattern.compile("^(A|B|C|D|E|F){0,1}A+F+C+(A|B|C|D|E|F){0,1}$"); // 패턴 조건
//	Matcher m = p.matcher(str); // 패턴 일치하는지~
//	boolean res = false;
//	
//	while(m.find()) { // 존재한다면 위치 반환
//		if(m.group().length()==str.length()) {
//			res = true;
//		}
//	}
//	System.out.println(res ? "Infected!" : "Good"); 
//}
	

