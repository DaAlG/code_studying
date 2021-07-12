import java.util.*;
class Solution {
    static HashSet<Character> letters;
    static double hap, gyo;
    
    //합집합과 교집합 정의하기
    public void makeHapAndGyo(HashMap<String, Integer> A, HashMap<String, Integer> B){
        for(String key : A.keySet()){
            if(B.get(key) == null)
                hap += A.get(key);
            else{
                int valA = A.get(key);
                int valB = B.get(key);
                hap += valA >= valB ? valA : valB;
                gyo += valA <= valB ? valA : valB;
                B.remove(key); // 계산 완료 - 삭제
            }
        }
        //교집합 제외
        for(String key : B.keySet())
            hap += B.get(key);
    }
    //문장 분해해서 해쉬맵 만들기.
    public void makeMap(String str, HashMap<String, Integer> map){
        int p1 = 0;
        int p2 = 1;
        int len = str.length();
        
        while(p2 != len){
            
            if(letters.contains(str.charAt(p1)) && letters.contains(str.charAt(p2))){         
                String sub = str.substring(p1,p2+1);

                if(map.get(sub) == null ){
                    map.put(sub, 1);
                 }
                 else{
                    map.put(sub, map.get(sub)+1);
                  }
            }
            p1 = p2++;
        }
    }

    public int solution(String str1, String str2) {
        int answer;
    
        letters = new HashSet<>(Arrays.asList('A','B','C','D','E','G','H','I','J','K','L','M','N','O','P','Q','R','T','U','V','W','X','Y','Z','F','S'));
        HashMap<String, Integer> A = new HashMap<>();
        HashMap<String, Integer> B = new HashMap<>();


        //첫번째 문장 분해
        makeMap(str1.toUpperCase(),A);
        //두번째 문장 분해
        makeMap(str2.toUpperCase(),B);
        
        //합집합, 교집합 정의하기
        makeHapAndGyo(A, B);
        
        if(hap == 0)
            answer = 65536;
        else
        {
            answer = (int)Math.floor(gyo / hap * 65536);
        }
        
        return answer;
    }
}