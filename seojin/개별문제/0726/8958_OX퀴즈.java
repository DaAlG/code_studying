import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    for(int i=0;i<N;i++){
      boolean isO = false;
      char[] arr = br.readLine().toCharArray();
      int cnt = 0;
      int sum = 0;
      for(int j=0;j<arr.length;j++){
        if(arr[j]=='O' && isO==false){
          cnt = 1;
          isO = true;
        }else if(arr[j]=='O' && isO==true){
          cnt += 1;
          isO = true;
        }else{
          cnt = 0;
          isO = false;
        }
        sum += cnt;
      }
      System.out.println(sum);
    }
  }
}