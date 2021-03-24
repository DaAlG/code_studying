import java.util.HashSet;
import java.util.Arrays;

class Solution {
    
    static HashSet<Integer> primes;
    static StringBuilder sb;
    static char[] input;
    static boolean[] selected;
    static int M; //그때 그때 바뀜.
    static int N; //input 크기로 고정.
    
    public boolean isPrime(int num){
        //예외: 0, 1, 2
        if(num < 2)
            return false;
        
        else if(num == 2)
            return true;
        
        else{
            for(int i=2; i<num; i++)
                if(num % i == 0)
                    return false;
        }
        
        return true;
    }
    
    public void perm(int cnt){
        //기저
        if(cnt == M){ //완성.
            //1. 스빌 -> 정수
            int num = Integer.parseInt(sb.toString());
            //2. 소수인지 확인
            if(isPrime(num)){
                primes.add(num);
            }
            //3. 소수면 hashSet에 add, 아니면 그냥 넣지 말고 무시.
            return;
        }
        
        //반복
        for(int i=0; i<N; i++){
            if(!selected[i]){
                //선택
                selected[i] = true;
                sb.append(input[i]);
                perm(cnt+1);
                //비선택
                selected[i] = false;
                sb.setLength(sb.length()-1);
            }
        }
        
    }
    
    
    public int solution(String numbers) {
        int answer; // HashSet 크기.
        
        /*전역변수 초기화*/
        primes = new HashSet<Integer>();
        sb = new StringBuilder("");
        N = numbers.length();
        input = numbers.toCharArray();
        selected = new boolean[N];
        
        //nP1 ~ nPn 까지 순열돌린다.
        for(int m=1; m<=N; m++){
            M = m; //그때 고를 개수.
            perm(0); //cnt, target
        }
        //소수들개수.
        answer = primes.size();
        return answer;
    }
}