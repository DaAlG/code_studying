package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
	
	public static String printPerTen(String inputLine) {
		StringBuilder sb = new StringBuilder();
		int idx = 0;
		
		while(idx < inputLine.length()) {
			if(idx + 10 <= inputLine.length()) {
				sb.append(inputLine.substring(idx, idx+10)).append("\n");
			}else {
				sb.append(inputLine.subSequence(idx, inputLine.length()));
			}
			idx += 10;
		}
		
		
		return sb.toString();
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputLine = br.readLine();
		System.out.println(printPerTen(inputLine));
		
	}
}