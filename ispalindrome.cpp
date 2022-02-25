#include <iostream>
#include <cstring>

bool isPalindrome(const char* sNum)
{
  int len = strlen(sNum) - 1;
  for (int i = 0; i != len; i++)
  {
    if (sNum[i] != sNum[len - i])
    {
      return false;
    }
  }
  return true;
}
