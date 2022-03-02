// js 로 처리한 문자열 입니다. 어느 위치던 상관없이 replace 함수를 통해 쉽게 해결했습니다.
// 저번 문제를 풀었던것과 같이 정규 표현식을 사용했습니다. 가장 기본적인 형태라 외우기 쉬울듯 합니다.

function solution(s) {
  var answer = 0;
  s = s.replace(/zero/g, "0");
  s = s.replace(/one/g, "1");
  s = s.replace(/two/g, "2");
  s = s.replace(/three/g, "3");
  s = s.replace(/four/g, "4");
  s = s.replace(/five/g, "5");
  s = s.replace(/six/g, "6");
  s = s.replace(/seven/g, "7");
  s = s.replace(/eight/g, "8");
  answer = s.replace(/nine/g, "9");

  answer = Number(answer);
  return answer;
}
//
