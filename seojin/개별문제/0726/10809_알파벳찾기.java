import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    char[] sentence = br.readLine().toCharArray();
    int[] lower = new int[26];
    Arrays.fill(lower, -1);

    for(int i=0;i<sentence.length;i++){
      if(lower[sentence[i]-'a']==-1){
        lower[sentence[i]-'a'] = i;
      }
    }

    for(int i=0;i<lower.length;i++){
      System.out.print(lower[i]+" ");
    }
  }
}