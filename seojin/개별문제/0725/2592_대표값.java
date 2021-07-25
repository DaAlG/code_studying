import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    // 1~100 까지 배열
    int[] check = new int[100]; // 빈도수 체크
    int sum = 0;

    for(int i=0;i<10;i++){
      int num = Integer.parseInt(br.readLine());
      sum += num;
      check[(int)num/10]+=1;
    }

    int max = 0;
    int maxnum = 0;
    for(int i=0;i<100;i++){
      if(max < check[i]) {
        max = check[i];
        maxnum = i*10;
      }
    }

    System.out.println((int)sum/10);
    System.out.println(maxnum);
  }
}