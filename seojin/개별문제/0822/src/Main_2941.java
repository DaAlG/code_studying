
// 크로아티아 알파벳
import java.io.*;
import java.util.*;

public class Main_2941 {
	/*
	 * contain 함수, replaceAll() 이용.
	 */
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] croa= {"c=","c-","dz=","d-","lj","nj","s=","z="}; // 크로아티아 알파벳 담은 배열
		String sen = br.readLine();
		
		for(int i=0; i<croa.length; i++) {
			
			if(sen.contains(croa[i])) { // 크로아티아 알파벳이 발견되면 -> '*'로 치환
				sen = sen.replaceAll(croa[i], "*");
			}
		}
		
		System.out.println(sen.length());
	}

}
