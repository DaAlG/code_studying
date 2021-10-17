package roundB;

import java.io.*;
import java.util.*;

public class Main {
  static int T;
  static List<Integer> list = new ArrayList<>();

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    T = Integer.parseInt(br.readLine());

    for(int l=1; l<=9; l++){ // 자릿수 1~9개
      for(int i=1; i<=9; i++){
        sb.setLength(0); // 초기화
        for(int j=0; j<l; j++){ // 자릿수 만큼
          sb.append(i);
        }
        list.add(Integer.parseInt(sb.toString()));
      }  
    }
  
    sb.setLength(0);
    for(int t=0; t<T; t++){
      int n = Integer.parseInt(br.readLine());

      int cnt = 0;
      for(int el : list){
        if(el <= n) cnt++;
        else break;
      }
      sb.append(cnt).append("\n");
    }
    System.out.println(sb.toString());
  }
}