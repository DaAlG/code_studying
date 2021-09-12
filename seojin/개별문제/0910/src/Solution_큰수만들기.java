// 조합 -> 시간 초과! 너무 큰 수들이 입력됨.
class Solution_큰수만들기 {
    
    public static String src;
    public static char[] tgt;
    public static StringBuilder sb;
    public static int max_num;
    public String solution(String number, int k) {
        String answer = "";
        
        src = number;
        tgt = new char[number.length()-k];
        sb = new StringBuilder();
        comb(0,0);
        
        answer = ""+max_num;
        return answer;
    }
    
    public static void comb(int srcIdx, int tgtIdx){
        if(tgtIdx == tgt.length){
            sb.setLength(0);
            for(char t : tgt){
                sb.append(t);
            }
            max_num = max_num < Integer.parseInt(sb.toString()) ? Integer.parseInt(sb.toString()) : max_num;
            return;
        }
        if(srcIdx == src.length()) return;
        
        tgt[tgtIdx] = src.charAt(srcIdx);
        comb(srcIdx+1, tgtIdx+1);
        comb(srcIdx+1, tgtIdx);
    }
}