// LV.1 두 개 뽑아서 더하기
// 배열

function solution(arr) {
  const newArr = []
  // 원소 내에서 두 개를 선택해 더한 값을 newArr 배열에 추가
  for (let i = 0; i < arr.length - 1; i++) {
      for (let j = i + 1; j < arr.length; j++) {
          newArr.push(arr[i] + arr[j]);
      }
  }
  // newArr 배열에서 중복 요소 제거
  uniqueArr = [...new Set(newArr)];
  // newArr 배열 오름차순 정렬
  uniqueArr.sort((a, b) => a - b);

  return uniqueArr
}