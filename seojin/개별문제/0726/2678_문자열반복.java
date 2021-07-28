import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int T = Integer.parseInt(br.readLine());
    StringTokenizer st;
    for(int i=0; i<T; i++){
      st = new StringTokenizer(br.readLine());
      int R = Integer.parseInt(st.nextToken());
      char[] sentence = st.nextToken().toCharArray();
      for(char s : sentence){
        for(int j=0;j<R;j++){
          System.out.print(s);
        }
      }
      System.out.println();
    }
  }
}