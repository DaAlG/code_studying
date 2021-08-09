import java.io.*;
import java.util.*;

public class Main_10973 {
	
	public static void swap(int [] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

	public static boolean nextPermutation(int[] a) {
        //1. a[i-1] < a[i]를 만족하는 첫 번째 수 찾기
       int i = a.length-1;
       while (i > 0 && a[i-1] >= a[i]) {
           i -= 1;
       }

       // 마지막 순열인 경우
       if (i <= 0) {
           return false;
       }
      //2. a[i-1] < a[j]를 만족하는 첫 번째 수 찾기
       int j = a.length-1;
       while (a[j] <= a[i-1]) {
           j -= 1;
       }
       
       //3. a[i-1]과 a[j] swap
       swap(a, i-1, j);

       //4 i부터 a.length-1까지 순열 뒤집기
       j = a.length-1;
       while (i < j) {
           swap(a, i, j);
           i += 1;
           j -= 1;
       }
       return true;
   }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		  Scanner sc = new Scanner(System.in);
          int n = sc.nextInt();
          int[] a = new int[n];
          for (int i=0; i<n; i++) {
              a[i] = sc.nextInt();
          }
          if (nextPermutation(a)) {
              for (int i=0; i<n; i++) {
                  System.out.print(a[i] + " ");
              }
          } 
          else {
              System.out.println("-1");
          }
	}

}

/*
7 2 3 6 5 4 1 같은 경우엔
7 2 3 / 6 5 4 1 -> 6 5 4 1이 내림차순이기 때문에
이것은 7 2 3으로 시작하는 순열중 마지막 순열이다.
그러므로 7 2 3 다음으로 올 수 있는 오른쪽 에서 가장 큰 수 
4와 swap하고 뒤집음으로써 오름차순으로 정렬하면
다음 순열이 나오게 된다.
이런 원리로 가장 오른쪽, 마지막에서 부터 A[i]가 A[i-1]보다 큰 가장 첫 번째 수를
찾고 다시 A[j]에서 A[i-1]보다 큰 첫 번째 수를 찾아서 swap하는 것이다.

출처: https://dundung.tistory.com/58 [DunDung]
*/