int solution(int number) 
{
  int result = 0;
  if (number <= 0)
    return 0;
  number -= 1;
  for (number; number > 0; number--)
    {
    if (number % 3 == 0 || number % 5 == 0) {
      result += number;
    }
    else if (number % 3 == 0 && number % 5 == 0) { result += 1; }
    else { result += 0; }
  }
  return result;
}
