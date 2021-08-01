import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    char[] carr = new char[8];

    for(int i=0;i<3;i++){
      carr = br.readLine().toCharArray();
      char pre = ' ';
      int cnt = 1;
      int max = 1;

      for(char c : carr){
        // System.out.println(pre+" "+c);
        if(pre-'0' == c-'0'){
          cnt ++; 
          continue;
        }
        if(max < cnt) max = cnt;
        pre = c;
        cnt = 1;
      }
      if(max < cnt) max = cnt; // 마지막에 다시 업데이트 필요!!
      // System.out.println("답");
      System.out.println(max>1?max:1);
    }
  }
}