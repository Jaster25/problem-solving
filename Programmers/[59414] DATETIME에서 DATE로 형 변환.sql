SELECT animal_id, name, DATE_FORMAT(datetime, '%Y-%m-%d') AS '날짜'
FROM animal_ins
ORDER BY animal_id ASC;

/* 날짜 형 변환 함수 DATE_FORMAT(시간 값, 형식)
형식 표기법

%Y:	년도 - Year(4자리 표기)
%y:	년도 (뒤에 2자리 표기)
%M:	월 - 이름(January ~ December)
%m:	월 - 숫자(00 ~ 12)
%c:	월 - 숫자(0 ~ 12)
%d:	일(00 ~ 31)

%H:	시간 24시간(00 ~ 23)
%h:	시간 12시간(00 ~ 12)
%i:	분 (00 ~ 59)
%s:	초 (00 ~ 59)
*/