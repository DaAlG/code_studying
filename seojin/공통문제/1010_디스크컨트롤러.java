import java.util.*;

class Solution {
    
    static Queue<Job> pqueue = new PriorityQueue<>((o1,o2)->o1.job_time - o2.job_time);
    static List<Job> list = new ArrayList<>();
    static boolean[] select;
    static int jobn; // 작업 개수
    
    public static int solution(int[][] jobs) {
        int answer = 0;
        jobn = jobs.length;
        
        select = new boolean[jobn];
        for(int[] job : jobs){
            list.add(new Job(job[0], job[1]));
        }
        // 작업 요청 시간이 빠른 순으로 정렬
        Collections.sort(list, (i,j)-> {
            // 근데 제일 처음에 작업이 제일 적게 걸리는 애를 뽑아야해서 소요시간이 빠른 애가 또 먼저 오도록 만들어줘야함.
            if(i.require_time == j.require_time) return i.job_time - j.job_time;
            else return i.require_time-j.require_time;
        });

        // 작업 가능한 애들 중에서 작업 요청 시간-작업 끝나는 시간이 제일 짧은 것부터 먼저 시작하기! -> pqueue로 찾기
        pqueue.add(list.get(0)); // 제일 요청이 빠른 애를 일단 넣기
        int idx = 1; // 처리한 작업 수
        int endtime = list.get(0).require_time; // 제일 요청이 빠른 애의 시작 시간 넣기
        select[0] = true;
        
        while(!pqueue.isEmpty() || idx != jobn){
            
            if(!pqueue.isEmpty()){
                Job cur = pqueue.poll(); // 해당하는 애들 중에 가장 소요시간이 짧은 것
                endtime += cur.job_time; 
                answer += endtime - cur.require_time; // 요청 ~ 종료까지 걸리는 시간
            }else{ // 앞선 작업이 종료 된 시간에 실행시킬 작업이 없는 경우 현 시간을 +1
                endtime++;
            }
            
            // 요청 시간이 cur의 종료시간보다 빠른 애들을 우선순위큐에 넣기
            for(int i=0; i<jobn; i++){
                if(select[i]) continue;
                
                if(list.get(i).require_time <= endtime){ 
                    pqueue.add(list.get(i));
                    select[i] = true;
                    idx++;
                }
            }
            
        }
        // System.out.println(answer);
        return answer/jobn;
    }
    
    static class Job{
        int require_time, job_time;
        
        public Job(int require_time, int job_time){
            this.require_time = require_time;
            this.job_time = job_time;
        }

    }
}