import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n=0;
    
    while(true){
      n = Integer.parseInt(br.readLine());
      if(n==0) break;
      String[] arr = new String[n];

      for(int i=0;i<n;i++){
        arr[i] = br.readLine();
      }
      Arrays.sort(arr,(i,j)->i.compareToIgnoreCase(j));
      System.out.println(arr[0]);
    }

  }
}