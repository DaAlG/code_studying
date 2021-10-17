package roundA;

import java.io.*;
import java.util.*;

class Main {
  static int T;
  static boolean[] visited; // 26개 글자 방문 처리

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    T = Integer.parseInt(br.readLine());
    
    
    for(int t=0; t<T; t++){
      int n = Integer.parseInt(br.readLine());
      String str = br.readLine();

      visited = new boolean[26]; // 'A' ~ 'Z'
      boolean isFault = false;
      char prev = '0';

      for(int i=0; i<n; i++){
        char now = str.charAt(i);
        if(prev == now) continue; // 이전 문자 == 현재 문자
        else{
          if(visited[now-'A']) {  // 이미 썼던 글자를 쓰면 위반
            isFault = true;
            break;
          }else{ // 처음 쓰는 글자라면
            visited[now-'A'] = true; // 방문 처리
            prev = now; // prev에 담기
          }
        }
      }

      if(isFault){ // 위반
        sb.append("NO\n");
      }else{
        sb.append("YES\n");
      }
    }
    System.out.println(sb.toString());
  }
}