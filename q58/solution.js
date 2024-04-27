/**
 * @param {string} s
 * @return {number}
 */
const lengthOfLastWord = (s) => {
  let i = s.length - 1;
  let count = 0;
  while (i >= 0 && s[i] === " ") i--;
  while (i >= 0 && s[i] !== " ") {
    count++;
    i--;
  }
  return count;
};

/**
 * @param {string} s
 * @return {number}
 */
let lengthOfLastWord2 = function (s) {
  let noSpace = s.trim();
  let arrayOfLetters = noSpace.split(" ");
  let finalWord = arrayOfLetters.pop();
  return finalWord.length;
};

console.log(lengthOfLastWord(" Hello  World "));
