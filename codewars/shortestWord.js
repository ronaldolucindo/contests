/* 

SHORTEST WORD
https://www.codewars.com/kata/57cebe1dc6fdc20c57000ac9
RONALDO MEDEIROS LUCINDO

*/

function findShort(s) {
  let short = Infinity;

  s.split(' ').map(item => {
    if (item.length < short) short = item.length;
  });
  return short;
}
