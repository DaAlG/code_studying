import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_A와B2_12919 {

	static String S,T;
	static Boolean isPossible = false;
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		S = br.readLine();
		T = br.readLine();
		StringBuilder sb = new StringBuilder();
		trans(sb.append(S));
		System.out.println(isPossible ? 1 : 0);
	}

	static void trans(StringBuilder s) {
//		System.out.println(s.toString());
		StringBuilder tempA = new StringBuilder();
		StringBuilder tempB = new StringBuilder();
		
		tempA.append(s);
		tempB.append(s);

		if(s.length() == T.length()) {
			if(s.toString().compareTo(T) == 0) isPossible = true;
			return;
		}
		
		if(!T.contains(s.toString()) && !T.contains(s.reverse().toString())) return;
		
		trans(tempA.append("A"));
		trans(tempB.append("B").reverse());
	}
}
