// https://jaimemin.tistory.com/1118
// 아이디어내는 게 어려웠음!!

import java.io.*;
import java.util.*;

public class Main {
	
	static int MAX = 1000000;
	static boolean[] prime = new boolean[MAX+1]; 
	static List<Integer> primenum = new ArrayList<>();
	static int[] usedPrime; // 해당 소수가 총 몇번 사용되었는가?
	static int[][] factor; // idx번째 숫자를 소인수 분해 했을 때 각 소수의 개수

	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력 처리
		int N = Integer.parseInt(br.readLine());
		
		// 소수 체
		PrimeSieve();
		usedPrime = new int[primenum.size()];
		factor = new int[N][primenum.size()];
		
		// 주어진 수를 돌면서 소인수분해하기
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			for (int j = 0; j < primenum.size(); j++){
				// 소인수분해
                while (num % primenum.get(j) == 0){
                	
                    factor[i][j]++; // 이번 숫자에서 이 위치의 소수를 몇번 썼는지!
                    usedPrime[j]++; // 전체적으로 이 위치의 소수를 몇 번 썼는지!
                    num /= primenum.get(j);
                    if (num == 1) break; // 더이상 분해 x
                }
                if (num == 1)
                    break;
            }
		}
		
		int result = 1, cnt = 0;
        for (int i = 0; i < primenum.size(); i++)
        {
             int temp = usedPrime[i] / N; //최대 공약수의 일부가 될 수 있는지 판단
             for (int j = 0; j < temp; j++) {
            	 result *= primenum.get(i); //최대 점수 값
             }
             
             for (int j = 0; j < N; j++) {
                 //적절히 나누어줘야한다.
                 if (temp > factor[j][i])  cnt += temp - factor[j][i];
             }

        }
        
        System.out.println(result+" "+cnt);
	}
	
	static void PrimeSieve() 
	{ 
		// Boolean 타입 배열 prime[0..N] 생성하고 모두 true로 초기화
		// 이후에 i가 합성수임이 확인되면 prime[i]=false가 되며
		// i가 소수라면 prime[i]=true로 남아 있음
		
		for(int i=0;i<MAX;i++) 
			prime[i] = true; 
	          
		for(int p = 2; p*p <=MAX; p++) 
		{ 
			// prime[p]가 true로 남아 있으면 p는 소수 
			if(prime[p] == true) 
			{ 
				// p의 모든 배수 i에 대해 prime[i]=false, 즉 합성수로 표기
				for(int i = p*p; i <= MAX; i += p) 
					prime[i] = false;
			} 
		}
		
		for(int i = 2; i <= MAX; i++) 
		{ 
			if(prime[i] == true) primenum.add(i);
//				System.out.print(i + " ");  //c언어에서 printf("%d ", i) 의미
		}
	}
}
