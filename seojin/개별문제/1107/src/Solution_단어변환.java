import java.util.*;

public class Solution_단어변환 {
    
    static Set<String> wordSet = new HashSet<>();
    static Set<String> visitSet = new HashSet<>();
    static int result = 0;
    
    public static int solution(String begin, String target, String[] words) {
        
        
        for(int i=0; i<words.length; i++){
            wordSet.add(words[i]);
        }
        
        // target이 wordSet에 있는지 확인
        if(!wordSet.contains(target)) {
        	return 0;
        }
        
        // 아니라면 체크!
        findCount(begin, target, words);
        return result;
    }
    
    private static void findCount(String begin, String target, String[] words){
        
        PriorityQueue<Pair> pqueue = new PriorityQueue<Pair>(); 
        pqueue.add(new Pair(0, begin));
        
        while(!pqueue.isEmpty()){
            Pair p = pqueue.poll();
            
            if(p.word.compareTo(target)==0){
            	result = p.cnt;
                return; 
            }
            
            for(String word : words){ 
                if(findWord(p.word, word) && !visitSet.contains(word)){ // 해당하는 단어를 찾았다면 새로 queue에 넣기!
                    pqueue.add(new Pair(p.cnt+1, word)); // cnt는 증가시켜주기
                    visitSet.add(word);
                }
            }
        }
    }
    
    private static boolean findWord(String begin, String word){
        // begin과 한 글자만 다른지 체크하기 
    	int cnt = 0;
        for(int i=0; i<begin.length(); i++){
            if(begin.charAt(i) != word.charAt(i)) cnt++;
            if(cnt > 1) return false;
        }
        if(cnt == 1) return true;
        else return false;
    }

    static class Pair implements Comparable<Pair>{
        int cnt;
        String word;
        
        public Pair(int cnt, String word){
            this.cnt = cnt;
            this.word = word;
        }

		@Override
		public int compareTo(Pair o) {
			return this.cnt - o.cnt;
		}

    }
}