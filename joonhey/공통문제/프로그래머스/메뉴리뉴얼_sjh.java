import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
import java.util.HashMap;

class Solution {
    static char[] orderEach;
    static ArrayList <Integer> posDishCnt;
    static StringBuilder selectedDishes; //선택된 조합 저장.
    static ArrayList<Dishes> courseDishes; //선택된 조합의 dish들 저장. cnt 증가, 정렬시키고 cnt<2인거 거르기
    static HashMap<Integer, Integer> maxCnt; // key: 조합의 길이, value: 그 길이를 가진 조합의 최다 주문 횟수
    class Dishes implements Comparable<Dishes>{
        String dishComb;
        int cnt;
        
        @Override //사전 오름차순 
        public int compareTo(Dishes o){
            return this.dishComb.compareTo(o.dishComb);
        }
        public Dishes(StringBuilder sb){
            this.dishComb = new String("");
            this.dishComb = sb.toString();
            this.cnt = 1;
        }
        @Override
        public String toString(){ //디버깅용
            
            return "요리"+dishComb+"cnt "+cnt;
        }
    }
    //완성된 코스 요리 후보들 put, 동시에 각 조합이 몇번 주문됐나 클래스 멤버 cnt에 기록, 각 길이별 최다 주문 횟수 업뎃
    public void putIntoCourse(StringBuilder selectedDishes){
        boolean found = false;
        //HashMap 쓰려고 했는데 그럼 끝에 정렬을 못해서.. 어쩔 수 없이 순차탐색
        int len = selectedDishes.length(); //그 조합의 길이
        for(int i=0; i<courseDishes.size(); i++){
            //StringBuilder를 equals로 비교할 땐 toString으로 형변환 해줘야 함 잊지말자.
            if(courseDishes.get(i).dishComb.equals(selectedDishes.toString())){
                found = true;
                courseDishes.get(i).cnt++;
                //각 길이 별 최대 주문 횟수 업데이트
                int curCnt = courseDishes.get(i).cnt;
                if(maxCnt.get(len) < curCnt){
                    maxCnt.put(len, curCnt);
                }                
                break;
            }
        }
        if(!found){
            courseDishes.add(new Dishes(selectedDishes));
            //그 길이에서의 cnt 기록이 없으면 여기서 추가.
            if(maxCnt.get(len) == null){
                maxCnt.put(len, 1);
            }
        }
    }
    public void combDish(int cnt){
    //기저조건: course 개 뽑았을 때, 최대 음식 범위 넘었을 때
        if(cnt == orderEach.length ){
            //이 길이의 코스요리가 가능 할때만 추가.
            if(posDishCnt.contains(selectedDishes.length())){
                putIntoCourse(selectedDishes);
            }
            return;
        }
        //선택
        selectedDishes.append(orderEach[cnt]);
        combDish(cnt+1);
        //비선택
        selectedDishes.setLength(selectedDishes.length() -1 );
        combDish(cnt+1);
    }
    
    
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};
        ArrayList<String> answers = new ArrayList<>();
        selectedDishes = new StringBuilder("");
        maxCnt = new HashMap<Integer, Integer>();
        //orders 옮겨담기
        posDishCnt = new ArrayList<Integer>();
        courseDishes = new ArrayList<Dishes>();
        for(int i=0; i<course.length; i++){
            posDishCnt.add(course[i]);
        }
        
        for(int i=0; i<orders.length; i++){
            // 한 사람 주문 코스
            orderEach = new char[orders[i].length()];
            for(int j=0; j<orderEach.length; j++){
                // 코스의 메뉴 하나하나
                orderEach[j] = orders[i].charAt(j);
            }
            Arrays.sort(orderEach);
            //한 사람 주문 코스 조합
            combDish(0);
        }
        
        //사전순 정렬
        Collections.sort(courseDishes);
 
        for(Dishes d : courseDishes){
            if(d.cnt >= 2 && d.cnt == maxCnt.get(d.dishComb.length()) ){
                answers.add(d.dishComb.toString());
            }
        }
        //총 몇개의 조합이 가능할 지 몰라 arrayList로 해뒀다가 정답은 Array 형이므로 형변환 해줌.
        return answers.toArray(answer);
    }
}