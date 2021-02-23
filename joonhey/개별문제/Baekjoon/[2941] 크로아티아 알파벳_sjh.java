package webex;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
class Solution{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputLine = br.readLine();
		StringBuilder sb;
		HashSet set = new HashSet<String>();
		set.add(new String("c=")); //상수로 잡으면 안되는 이유: equals 가 내용을 비교 vs 주소를 비교.
		set.add(new String("c-"));
		set.add(new String("dz="));
		set.add(new String("d-"));
		set.add(new String("lj"));
		set.add(new String("s="));
		set.add(new String("z="));
		set.add(new String("nj"));
		
		int idx = 0;
		int cnt = 0;
		
		//두 글자씩 묶을거임
		while (idx + 1 < inputLine.length()) {
			cnt++;
			sb = new StringBuilder(inputLine.substring(idx, idx+2));
			if(set.contains(sb.toString())) {
				idx += 2;
			}
			else {
				//dz=이면 허용.
				if(sb.toString().equals("dz")) {
					if(idx +2 <inputLine.length() && inputLine.charAt(idx + 2) == '=') {
						idx += 3;
					}
					else {
						idx += 1;
					}
				}
				else {
					idx += 1;
				}
			}
		}
		//홀수면 한 글자 남는데 +해줘야
		if (idx < inputLine.length()) {
			cnt++;
		}
		System.out.println(cnt);
	}
}