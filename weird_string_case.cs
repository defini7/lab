using System;

public class Main
{
  public static string ToWeirdCase(string s)
  {
    char[] arr = s.ToCharArray();
    int index = 0;      
    while (index < arr.Length)
    {
        while (index < arr.Length && !char.IsLetter(arr[index]))
            index++;
            
        int counter = 0;            
        while (index < arr.Length && char.IsLetter(arr[index]))
        {
            if (counter % 2 == 0)
                arr[index] = char.ToUpper(arr[index]);
            else
                arr[index] = char.ToLower(arr[index]);
            index++;
            counter++;
        }
    }
    return new string(arr);
  }
}
