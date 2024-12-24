import * as assert from "assert";

/**
 Do not return anything, modify board in-place instead.
*/
function solve(board: string[][]): void {
  const m = board.length;
  const n = board[0].length;
  if (m <= 1 || n <= 1) return;

  let visited: boolean[][] = Array.from({ length: m }, () =>
    Array(n).fill(false)
  );
  let queue: [number, number][] = [];
  let O_positions: [number, number][] = [];
  for (let i = 0; i < n; i++) {
    if (board[0][i] == "O") {
      visited[0][i] = true;
      queue.push([0, i]);
      O_positions.push([0, i]);
    }
    if (board[m - 1][i] == "O") {
      visited[m - 1][i] = true;
      queue.push([m - 1, i]);
      O_positions.push([m - 1, i]);
    }
  }
  for (let i = 1; i < m - 1; i++) {
    if (board[i][0] == "O") {
      visited[i][0] = true;
      queue.push([i, 0]);
      O_positions.push([i, 0]);
    }
    if (board[i][n - 1] == "O") {
      visited[i][n - 1] = true;
      queue.push([i, n - 1]);
      O_positions.push([i, n - 1]);
    }
  }
  while (queue.length > 0) {
    let [x, y] = queue.shift() as [number, number];
    let directions: [number, number][] = [
      [0, 1],
      [0, -1],
      [1, 0],
      [-1, 0],
    ];
    for (let [dx, dy] of directions) {
      let nx = x + dx;
      let ny = y + dy;
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == "O") {
        if (!visited[nx][ny]) {
          visited[nx][ny] = true;
          queue.push([nx, ny]);
          O_positions.push([nx, ny]);
        }
      }
    }
  }
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      board[i][j] = "X";
    }
  }
  for (let [x, y] of O_positions) {
    board[x][y] = "O";
  }
}

// Example usage:
const board = [
  ["X", "X", "X", "X"],
  ["X", "O", "O", "X"],
  ["X", "X", "O", "X"],
  ["X", "O", "X", "X"],
];
solve(board);
console.log(board);
