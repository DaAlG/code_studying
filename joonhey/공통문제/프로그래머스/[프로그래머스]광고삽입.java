import java.util.*;

class Solution {
    static int startTime; //광고 시작 시간
    static int endTime; //광고 종료 시간
    static int endVideo; //동영상 종료
    static long[] views; //시간별 시청 인원
    static long maxPeople;
    static int maxStartTime;
    static int N; //사람 수

    public int strToTime(String str){
        int time = 0;
        StringTokenizer st = new StringTokenizer(str,":");
        time += Integer.parseInt(st.nextToken()) * 60 * 60;
        time += Integer.parseInt(st.nextToken()) * 60;
        time += Integer.parseInt(st.nextToken());
        return time;
    }
    public String timeToStr(int time){
        StringBuilder sb = new StringBuilder("");
        int hour = time / 3600;
        time -= hour * 3600;
        int min = time / 60;
        time -= min * 60;
        int sec = time;
        
        if(hour < 10)
            sb.append("0");
        sb.append(hour).append(":");
        if(min < 10)
            sb.append("0");
        sb.append(min).append(":");
        if(sec < 10)
            sb.append("0");
        sb.append(sec);
        return sb.toString();
    }
    public String solution(String play_time, String adv_time, String[] logs) {
        String answer = "";
        StringTokenizer st;
        //동영상, 광고 재생시간 토크나이징
        endVideo = strToTime(play_time);
        endTime = strToTime(adv_time);
        //초 별로 몇 명이 봤나 기록.
        views = new long[endVideo+1];
                
        N = logs.length;

        //시청 기록 정리
        for(int i=0; i<N; i++){
            st = new StringTokenizer(logs[i],"-");
            int viewStart = strToTime(st.nextToken());
            int viewEnd = strToTime(st.nextToken());
            for(int j=viewStart; j<=viewEnd; j++){
                views[j]++;
            }
        }

        long viewPeople = 0;
        //초반 시청 인원
        for(int i=0; i<=endTime; i++){
            viewPeople += views[i];
        }
        maxPeople = viewPeople;
        answer = "00:00:00";
        
        //광고 종료 시간 <= 동영상 종료 시간.
        while(endTime < endVideo){
            viewPeople -= views[startTime++];
            viewPeople += views[++endTime];
            if(viewPeople > maxPeople){
                maxPeople = viewPeople;
                maxStartTime = startTime;
            }
        }
        answer = timeToStr(maxStartTime);
        
        return answer;
    }
}