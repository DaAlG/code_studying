package webex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class Main{
	static final int r = 31;
	static final int M = 1234567891;
	static int L;
	static HashMap<Character, Integer> charHash;
 
	public static int getHashValue(String inputLine) {
		long sum = 0;
		for(int i = 0; i<inputLine.length(); i++) {
			sum += charHash.get(inputLine.charAt(i)) * (int)Math.pow(r, i);
		}
		return (int) (sum % M);
	}
	public static void setHashTable() {
		//A ~ Z 까지 문자 별 해시값 메핑.
		for(int i=0; i < 26; i++) {
			char cur =(char)('a' + i); //현재 해시 값 - 1(정수)
			charHash.put(cur,cur - 'a' + 1);
//			System.out.println("key "+(char)cur +  "val " + (cur - 'a' + 1));
		}
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		charHash = new HashMap<Character, Integer>();
		//해시맵 세팅
		setHashTable();
		L = Integer.parseInt(br.readLine());
		System.out.println(getHashValue(br.readLine()));
	}
}