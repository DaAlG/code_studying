-- 코드를 입력하세요
-- 이럼 CAT밖에 안나옴
-- SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE)
-- FROM ANIMAL_INS;

SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) AS COUNT 
-- 1. 속성명 지정 >> COUNT
-- 0. COUNT(뫄뫄): ANIMAL_TYPE 칼럼이 NULL이 아닌 것들의 개수
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
-- 2. 그루핑 >> 나온 기록들을 ANIMAL_TYPE 에 따라 나눈다.
ORDER BY ANIMAL_TYPE ASC;
-- 그냥 ANIMAL_TYPE 하면 ABCD 사전순으로 나열할 것임.
-- 그러므로 경우에 따라 다른 값을 반환하도록 한다.
-- 3. CASE COLUMN
--      WHEN 조건1 THEN 값1
--      WHEN 조건2 THEN 값2
--      ELSE 값3
--      END