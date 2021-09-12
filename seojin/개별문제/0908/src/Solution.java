import java.util.ArrayList;
// 프로그래머스 - 소수 찾기(LV2)
class Solution {
    static int answer = 0;
    static char[] src;
    static char[] tgt;
    static boolean[] isSelected;

    static ArrayList<Integer> arr = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();
    
    public static void perm(int tgtIdx) {
		// 기저 조건
    	if(tgtIdx == tgt.length) {
    		
    		sb.setLength(0);
    		for(char t : tgt) {
    			sb.append(t);
    		}
    		
    		
            if(!arr.contains(Integer.parseInt(sb.toString()))) {
            	arr.add(Integer.parseInt(sb.toString()));          
            	System.out.println(tgt);
            }
    		return;
    	}
		// src로부터 모든 수를 고려 - 단, 이미 선택된 숫자는 제외
		for (int i = 0; i < src.length; i++) {
			// 이미 선택되어있는지 체크
			if(isSelected[i]) {
				continue;
			}
			tgt[tgtIdx] = src[i];
			isSelected[i] = true;
			perm(tgtIdx + 1);
			isSelected[i] = false;
			
		}
	}

    
    public static void main(String[] args) {
		solution("17");
	}
    
    public static void isPrime(int n){
        if(n == 0) return;
        if(n == 1) return;
        
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n % i == 0) return;
        } 
        answer++;
    }
    
    public static int solution(String numbers) { 
        String temp="";
        
        src = numbers.toCharArray();
          
        
        for(int i = 1;i<=numbers.length();i++){
        	tgt = new char[i];
        	isSelected = new boolean[src.length];
        	perm(0);
        }
        
        for(int x : arr){            
            isPrime(x);
        }
        
        return answer;
    }
}