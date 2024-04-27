/**
 * @param {number} n
 * @return {number[][]}
 */
const generateMatrix = function (n) {
  let ans = new Array(n).fill().map(() => new Array(n).fill());
  // const matrix = Array.from({length: n}, () => new Uint16Array(n));
  let count = 1;
  let left = 0;
  let right = n - 1;
  let top = 0;
  let bottom = n - 1;
  while (left <= right && top <= bottom) {
    for (let i = left; i <= right; i++) ans[top][i] = count++;
    top++;
    for (let i = top; i <= bottom; i++) ans[i][right] = count++;
    right--;
    for (let i = right; i >= left; i--) ans[bottom][i] = count++;
    bottom--;
    for (let i = bottom; i >= top; i--) ans[i][left] = count++;
    left++;
  }
  return ans;
};

console.log(generateMatrix(3));
