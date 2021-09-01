class Solution {
    public String solution(String new_id) {
        String answer = new_id.toLowerCase(); // 소문자로 치환
        answer = answer.replaceAll("[^-_.a-z0-9]", ""); // 알파벳 소문자, 숫자, -, _, .만 남기고 제거
        answer = answer.replaceAll("[.]{2,}", "."); // . 2개 이상을 .으로 치환
        answer = answer.replaceAll("^[.]|[.]$", ""); // 처음과 끝 . 제거
        
        if (answer.equals("")) // 빈 문자열이면 "a" 대입
            answer = "a";
        
        if (answer.length() >= 16) { // 16자 이상이면 15자로
            answer = answer.substring(0, 15);
            answer = answer.replaceAll("[.]$", ""); // 끝에 . 제거
        }
        
        if (answer.length() <= 2) { // 2자 이하라면 3자까지 마지막 문자 추가
            while (answer.length() < 3) {
                answer += answer.charAt(answer.length() - 1);
            } 
        }
        return answer;
    }
}