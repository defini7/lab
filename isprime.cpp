bool isPrime(int num) 
{
  int divided = 0;
  for (int i = num; i > 0; i--)
    {
    if (num % i != 0)
      continue;
    else
      divided++;
  }
  if (divided == 2) return true;
  else return false;
}
