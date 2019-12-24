/* 

BACKSPACES IN STRING
https://www.codewars.com/kata/5727bb0fe81185ae62000ae3
RONALDO MEDEIROS LUCINDO

*/

function cleanString(s) {
  const resultArray = [];
  s.split('').map(ch => {
    ch === '#' ? resultArray.pop() : resultArray.push(ch);
  });
  return resultArray.join('');
}
