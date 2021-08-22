//1074 : z
import java.io.*;
import java.util.*;

public class Main_1074 {

	static int N, r, c;
	static int sum;
	
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		find(N, 0, (int)Math.pow(2, N)-1, 0, (int)Math.pow(2, N)-1);
		
		System.out.println(sum);
	}
	
	static void find(int n, int rs, int re, int cs, int ce) {
		
		int rmid = (rs + re)/2;
		int cmid = (cs + ce)/2;
		
		if(r<=rmid && c<=cmid) {
			
			// z의 1분면
			if(n>0) find(n-1, rs, rmid, cs, cmid);
			
		}else if(r<=rmid && c>cmid) {
			
			// z의 2분면
			sum += Math.pow(2,(n-1))*Math.pow(2,(n-1))*1;
			if(n>0) find(n-1, rs, rmid, cmid+1, ce);
			
		}else if(r>rmid && c<=cmid) {
			
			// z의 3분면
			sum += Math.pow(2,(n-1))*Math.pow(2,(n-1))*2;
			if(n>0) find(n-1, rmid+1, re, cs, cmid);
			
		}else if(r>rmid && c>cmid) {
			
			// z의 4분면
			sum += Math.pow(2,(n-1))*Math.pow(2,(n-1))*3;
			if(n>0) find(n-1, rmid+1, re, cmid+1, ce);
			
		}
	}

}
