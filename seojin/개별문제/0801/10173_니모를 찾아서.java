import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    while(true){
      st = new StringTokenizer(br.readLine());
      if(st.nextToken().equals("EOI")) break;
      boolean find = false;
      while(st.hasMoreTokens()){
        if(st.nextToken().toLowerCase().contains("nemo")){
          System.out.println("Found");
          find = true;
          break;
        }
      }
      if(!find) System.out.println("Missing");
    }
  }
}