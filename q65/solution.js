/**
 * @param {string} s
 * @return {boolean}
 */
const isNumber = function (s) {
  const reg = /^[+-]?((\d+\.\d*)|(\.\d+)|(\d+))(e[+-]?\d+)?$/i;
  // const regex = /^[+-]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?$/;
  return reg.test(s);
};

console.log(isNumber("0e"));
