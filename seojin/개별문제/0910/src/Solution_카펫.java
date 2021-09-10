class Solution_카펫 {
    public int[] solution(int brown, int yellow) {
        int[] answer =  new int[2];
    
        int area = brown + yellow;
        
        // 3x3부터 시작..
        for(int i=3; i<=area; i++){
            int row = i;
            int col = area/i;
            
            if(row > col) continue; // 열==가로길이 -> 같거나 길어야함
            
            if((row-2)*(col-2) == yellow){
                answer[0] = col; // 가로길이
                answer[1] = row; // 세로길이
                break;
            }
        }
        return answer;
    }
}