import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.regex.Pattern;

// 순열로 구하기 -> 그럼 중복 생김 
// 조합으로 구하기 -> 그럼 안구하고 넘어가는 애가 생김..

public class 프로그래머스_불량사용자 {

	static int[] tgt; // 위치 인덱스를 저장한다.
	static boolean[] visit;
	static HashSet<String> set = new HashSet<>();
	
    public static int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        
        tgt = new int[banned_id.length];
        visit = new boolean[user_id.length];
        checkId(0, user_id, banned_id);
        
        answer = set.size();
        return answer;
    }
    
    static void checkId(int bidx, String[] user_id, String[] banned_id) {
    	if(bidx == banned_id.length) {
    		
    		List<Integer> list = new ArrayList<>();
    		for (int i = 0; i < banned_id.length; i++) {
				list.add(tgt[i]);
			}
    		Collections.sort(list);
    		String res = "";
    		for(int num : list) {
    			res += num;
    		}
    		set.add(res);
    		
    		return;
    	}
    	
       	 String bid = banned_id[bidx];
       	 bid = bid.replace("*", ".");
       	 
       	 for (int i = 0; i < user_id.length; i++) {
			
       		 if(visit[i]) continue;
       		 String uid = user_id[i];
       		 
       		 if(Pattern.matches("^"+bid+"$",uid)) {
      			 tgt[bidx] = i;
      			 visit[i] = true;
      			 checkId(bidx+1, user_id, banned_id);
      			 visit[i] = false;
      		 }
		}
    }
    
	public static void main(String[] args) {
		System.out.println(solution(new String[] {"frodo", "fradi", "crodo", "abc123", "frodoc"}, new String[] {"*rodo", "*rodo", "******"}));

	}

}
