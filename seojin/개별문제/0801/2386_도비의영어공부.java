import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st; 
    while(true){
      st = new StringTokenizer(br.readLine());
      String e = st.nextToken();
      if(e.equals("#")) break;
      int cnt = 0;
      while(st.hasMoreTokens()){
        // System.out.println(st.nextToken());
        for(char s: st.nextToken().toLowerCase().toCharArray()){
          if(e.charAt(0) == s) cnt ++;
        }
      }
      System.out.println(e+" "+cnt);
    }  
  }
}