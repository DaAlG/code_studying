import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  static String num;
  static String[] binary = {
    "000","001","010","011","100","101","110","111"
  };

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String num = br.readLine();

    StringBuilder sb = new StringBuilder();

    for(int i=0;i<num.length();i++){
      int cur = num.charAt(i)-'0';
      if(i==0 && cur<4){
        if(cur<2){
          sb.append(binary[cur].substring(2));
        }
        else{
          sb.append(binary[cur].substring(1));
        }
      }
      else{
        sb.append(binary[cur]);
      }
    }
    System.out.println(sb.toString());
  }
}