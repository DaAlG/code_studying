
import java.util.*;

class Solution_베스트앨범 {
    public static int[] solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        // 장르에 속한 노래의 재생 횟수가 많은 노래부터 수록함~
        // 장르별 재생횟수 찾기
        Map<String, Integer> map = new HashMap<>();
        for(int i=0; i<genres.length;i++){
            if(map.containsKey(genres[i])){
                int cnt = map.get(genres[i]) + plays[i];
                map.replace(genres[i], cnt);
            }else{
                map.put(genres[i],plays[i]);
            }
        }
        
        
        // 정렬
        List<Map.Entry<String,Integer>> entryList = new LinkedList<>(map.entrySet());
        entryList.sort(new Comparator<Map.Entry<String,Integer>>(){
            @Override
            public int compare(Map.Entry<String,Integer> o1, Map.Entry<String,Integer> o2){
                return -1*(o1.getValue() - o2.getValue()); // 장르별 재생횟수 내림차순으로 정렬
            }
        });
        
        // 1번 조건 순서대로 저장된 장르랑 같은 애들만 먼저 본다
        for(Map.Entry<String,Integer> entry : entryList){
            List<Play> playlist = new ArrayList<>();
            for(int i=0; i<genres.length; i++){
                if(genres[i].compareTo(entry.getKey())==0){ // 해당 장르에 해당하는 번호, 재생횟수를 저장한다.
                    playlist.add(new Play(i,plays[i]));
                }
            }
            Collections.sort(playlist, new Comparator<Play>(){
                @Override
                public int compare(Play p1, Play p2){
                    if(p1.cnt == p2.cnt){ // 재생횟수가 같다면 고유 번호 오름차순으로 정렬
                        return p1.num - p2.num;
                    }
                    else return -1*(p1.cnt-p2.cnt); // 재생횟수 내림차순으로 정렬
                    
                }
            });
            
            int cnt = 0;
            for(Play p: playlist){
                if(cnt==2) break; // 최대 두개만 넣을 수 있음.
                answer.add(p.num);
                cnt++;
            }
        }
        
        int[] ans = new int[answer.size()];
        for(int i=0; i<answer.size(); i++){
            ans[i] = answer.get(i);
        }
        return ans;
    }
    
    static class Play{
       int num, cnt;
        
        public Play(int num, int cnt){
            this.num = num;
            this.cnt = cnt;
        }
    }

}