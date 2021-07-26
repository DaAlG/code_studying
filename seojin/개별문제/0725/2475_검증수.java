import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String num = br.readLine();
    StringTokenizer st = new StringTokenizer(num);
    double sum = 0;
    for(int i=0;i<5;i++){
      sum += Math.pow(Integer.parseInt(st.nextToken()),2);
    }
    System.out.println((int)sum%10);

  }
}