import java.util.HashMap;

class Solution {
    //의상 종류별 의상 개수 카운팅하고 (종류별 의류 수 +1(안입는거))씩 해서 곱해준다.
    public int solution(String[][] clothes) {
        int answer;
        HashMap<String, Integer> map = new HashMap<>();
        for(int i=0; i<clothes.length; i++){
            //map에 x
            if(map.get(clothes[i][1]) == null){
                map.put(clothes[i][1], 1);
            }
            //map에 있음
            else{
                int val = map.get(clothes[i][1]);
                map.put(clothes[i][1], val+1);
            }
            
        }
        answer = 1;
        for(String s : map.keySet()){
            answer *= map.get(s) + 1;
        }
        return answer-1;
    }
}