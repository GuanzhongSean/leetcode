"use strict";
var __read =
  (this && this.__read) ||
  function (o, n) {
    var m = typeof Symbol === "function" && o[Symbol.iterator];
    if (!m) return o;
    var i = m.call(o),
      r,
      ar = [],
      e;
    try {
      while ((n === void 0 || n-- > 0) && !(r = i.next()).done)
        ar.push(r.value);
    } catch (error) {
      e = { error: error };
    } finally {
      try {
        if (r && !r.done && (m = i["return"])) m.call(i);
      } finally {
        if (e) throw e.error;
      }
    }
    return ar;
  };
var __values =
  (this && this.__values) ||
  function (o) {
    var s = typeof Symbol === "function" && Symbol.iterator,
      m = s && o[s],
      i = 0;
    if (m) return m.call(o);
    if (o && typeof o.length === "number")
      return {
        next: function () {
          if (o && i >= o.length) o = void 0;
          return { value: o && o[i++], done: !o };
        },
      };
    throw new TypeError(
      s ? "Object is not iterable." : "Symbol.iterator is not defined.",
    );
  };
Object.defineProperty(exports, "__esModule", { value: true });
/**
 Do not return anything, modify board in-place instead.
*/
function solve(board) {
  var e_1, _a, e_2, _b;
  var m = board.length;
  var n = board[0].length;
  if (m <= 1 || n <= 1) return;
  var visited = Array.from({ length: m }, function () {
    return Array(n).fill(false);
  });
  var queue = [];
  var O_positions = [];
  for (var i = 0; i < n; i++) {
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
  for (var i = 1; i < m - 1; i++) {
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
    var _c = __read(queue.shift(), 2),
      x = _c[0],
      y = _c[1];
    var directions = [
      [0, 1],
      [0, -1],
      [1, 0],
      [-1, 0],
    ];
    try {
      for (
        var directions_1 = ((e_1 = void 0), __values(directions)),
          directions_1_1 = directions_1.next();
        !directions_1_1.done;
        directions_1_1 = directions_1.next()
      ) {
        var _d = __read(directions_1_1.value, 2),
          dx = _d[0],
          dy = _d[1];
        var nx = x + dx;
        var ny = y + dy;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == "O") {
          if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            queue.push([nx, ny]);
            O_positions.push([nx, ny]);
          }
        }
      }
    } catch (e_1_1) {
      e_1 = { error: e_1_1 };
    } finally {
      try {
        if (
          directions_1_1 &&
          !directions_1_1.done &&
          (_a = directions_1.return)
        )
          _a.call(directions_1);
      } finally {
        if (e_1) throw e_1.error;
      }
    }
  }
  for (var i = 0; i < m; i++) {
    for (var j = 0; j < n; j++) {
      board[i][j] = "X";
    }
  }
  try {
    for (
      var O_positions_1 = __values(O_positions),
        O_positions_1_1 = O_positions_1.next();
      !O_positions_1_1.done;
      O_positions_1_1 = O_positions_1.next()
    ) {
      var _e = __read(O_positions_1_1.value, 2),
        x = _e[0],
        y = _e[1];
      board[x][y] = "O";
    }
  } catch (e_2_1) {
    e_2 = { error: e_2_1 };
  } finally {
    try {
      if (
        O_positions_1_1 &&
        !O_positions_1_1.done &&
        (_b = O_positions_1.return)
      )
        _b.call(O_positions_1);
    } finally {
      if (e_2) throw e_2.error;
    }
  }
}
// Example usage:
var board = [
  ["X", "X", "X", "X"],
  ["X", "O", "O", "X"],
  ["X", "X", "O", "X"],
  ["X", "O", "X", "X"],
];
solve(board);
console.log(board);
