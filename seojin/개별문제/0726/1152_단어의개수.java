import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String sentence = br.readLine();
    StringTokenizer st = new StringTokenizer(sentence);

    int cnt = 0;
    while(st.hasMoreTokens()){
      st.nextToken();
      cnt++;
    }
    System.out.println(cnt);
  }
}