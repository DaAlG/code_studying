
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
class Solution {
    
    static class Log {    
        long start;
        long end;
        String str;
        
        public Log(long start, long end, String str) {
            this.start = start;
            this.end = end;
            this.str = str;
        }
        
    }

    public int solution(String[] input) {
        ArrayList<Log> list = new ArrayList<Log>(); 
        SimpleDateFormat dt = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
        for(String s : input) {
            String arr[]= s.split(" ");
            try {
                // 파싱 ㄱㄱ
                long end = dt.parse(arr[0]+" "+arr[1]).getTime();
                long running = (long)(Double.parseDouble(arr[2].replace("s", ""))*1000); 
                long start = end - running + 1;
                list.add(new Log(start, end, s));
            } catch (ParseException e) { 
                //파싱 예외 처리
                return -1;
            }
        }
        
        int maxCnt = 0; 
        
        for(Log log : list) {
            long start = log.start; 
            long end = log.end; 
            int startCnt = 0;
            int endedCnt = 0; 
            for(Log target : list) {
                if(start <= target.end && start + 999 >= target.start) {
                    startCnt++;
                }
                if(end <= target.end && end + 999 >= target.start) {
                    endedCnt++;
                }
            }
            maxCnt = startCnt > maxCnt ? startCnt : maxCnt;
            maxCnt = endedCnt > maxCnt ? endedCnt : maxCnt;
        }
        return maxCnt;
    }
}
