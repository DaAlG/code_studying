import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int[] check = new int[10]; // 빈도수 체크
    int sum = 0;
    for(int i=0;i<5;i++){
      int num = Integer.parseInt(br.readLine());
      check[(int)num/10]+=1;
      sum += num;
    }
  
    System.out.println((int)sum/5);
    int index = 0;
    for(int i=0;i<10;i++){
      if(check[i]!=0){
        index += check[i];
        if(index>=3){
          System.out.println(i*10);
          break;
        }
      }
    }
  }
}