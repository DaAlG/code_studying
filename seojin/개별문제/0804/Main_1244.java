package baekjoon;

import java.io.*;
import java.util.*;

public class Main_1244 {
	public static void main(String[] args) throws Exception{
	  	System.setIn(new FileInputStream("input1244.txt"));
	  	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine()); // 스위치 개수
		
		char[] status = new char[n+1];
		
		st = new StringTokenizer(br.readLine());
		status[0] = '0';
		for(int i=1; i<=n; i++) {
			status[i] = st.nextToken().charAt(0);
		}
		
		int stu_num = Integer.parseInt(br.readLine()); // 학생 수
	
		
		for (int i = 0; i < stu_num; i++) {
			st = new StringTokenizer(br.readLine());
			int type = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			
			if(type == 1) { // 남학생일 경우
				for(int j=num; j<=n; j+=num) {
					status[j] = status[j]=='1'? '0' : '1';
				}
				
			}else if(type == 2) { // 여학생일 경우
				int findex = num-1; 
				int lindex = num+1;
				
				// 자기 자신 바꾸기
				status[num] = status[num]=='1'? '0' : '1';
				
				// 양옆 확인
				while(true) {
					if(findex<1 || lindex>n) break;			
					if(status[findex] != status[lindex]) break;

					status[findex] = status[findex]=='1'? '0' : '1';
					status[lindex] = status[lindex]=='1'? '0' : '1';
					
					findex -= 1;
					lindex += 1;
				}
			}
		}
		for(int i=1;i<=n;i++) {
	      System.out.print(status[i]+" ");
	      if((int)i%20==0) System.out.println();
		}
  }
}
