class Solution {
    static boolean[] visited;
    
    public void dfs(int curComputer, int[][] computers, int n){
        
        visited[curComputer] = true; //본인 제외하는 법
        
        for(int j=0; j<n;j++){
            //방문 안했고 연결되있음
            if( computers[curComputer][j] == 1 && !visited[j]){
                dfs(j, computers, n);
            }
        }
    
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n]; //방문여부
        for(int i=0; i<n; i++){
            if(!visited[i])
            {
                answer++;
                dfs(i, computers, n);
            }
        }
        return answer;
    }
}