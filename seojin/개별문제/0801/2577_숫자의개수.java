import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int A = Integer.parseInt(br.readLine());
    int B = Integer.parseInt(br.readLine());
    int C = Integer.parseInt(br.readLine());

    String res = Integer.toString(A*B*C);

    int[] arr = new int[10]; // 0~9 빈도수

    for(int i=0; i<res.length(); i++){
      arr[res.charAt(i)-'0'] += 1;
    }

    for(int a : arr){
      System.out.println(a);
    }
  }
}