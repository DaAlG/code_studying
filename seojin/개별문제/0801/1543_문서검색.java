import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String sen = br.readLine();
    String find = br.readLine();
    
    int start = 0;
    int index = 0;
    int cnt = 0;
    while(index>-1){
      index = sen.indexOf(find, start);
      if(index == -1) break;
      start = index+find.length();
      cnt++;
    }
    System.out.println(cnt);
  }
}