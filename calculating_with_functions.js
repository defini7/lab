let n = function(digit) {
  return function(oper) {
    return oper ? oper(digit) : digit;
  }
};
let zero = n(0);
let one = n(1);
let two = n(2);
let three = n(3);
let four = n(4);
let five = n(5);
let six = n(6);
let seven = n(7);
let eight = n(8);
let nine = n(9);
 
function plus(r) { return function(l) { return l + r; }; }
function minus(r) { return function(l) { return l - r; }; }
function times(r) { return function(l) { return l * r; }; }
function dividedBy(r) { return function(l) { return Math.floor(l / r); }; }
