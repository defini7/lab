// example: add(1)(2)(3) // equals 6
function add(n){
  let currentSum = n;
  
  function addF(b) {
    currentSum += b;
    return addF;
  }
  
  addF.toString = function() {
    return currentSum;
  };
  
  return addF;
}
