/* 

PETE, THE BAKER
https://www.codewars.com/kata/525c65e51bf619685c000059
RONALDO MEDEIROS LUCINDO

*/

function cakes(recipe, available) {
  let amount = Infinity;

  Object.keys(recipe).map(item => {
    const currentIngredient = Math.floor(available[item] / recipe[item] || 0);
    if (currentIngredient < amount) amount = currentIngredient;
  });
  return amount;
}
