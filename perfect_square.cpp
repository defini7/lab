#include <math.h>
long int findNextSquare(long int sq) {
  if (sqrt(sq) - ceil(sqrt(sq)) == 0)
    return pow((sqrt(sq) + 1), 2);
  else
    return -1;
}
