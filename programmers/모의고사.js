// 모의고사
// 배열

function solution(ans) {
  // 수포자들의 패턴
  const pat = [
      [1, 2, 3, 4, 5],
      [2, 1, 2, 3, 2, 4, 2, 5],
      [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
  ];

  // 수포자들의 점수
  const scores = [0, 0, 0];
  let max_score = 0;

  for (let i = 0; i < 3; i++) {
      for (let j = 0; j < ans.length; j++) {
          // 패턴보다 문제의 길이가 긴 경우, 패턴의 길이만큼 다시 돌기
          let k = j % pat[i].length;
          if (ans[j] === pat[i][k]) {
              scores[i]++;
          }
          if (max_score < scores[i]) {
              max_score = scores[i];
          }
      }
  }
  // 최댓값과 일치하는 학생들을 찾기
  const max_student = []
  for (let i = 0; i < 3; i++) {
      if (max_score === scores[i]) {
          max_student.push(i + 1);
      } 
  }
  return max_student
}