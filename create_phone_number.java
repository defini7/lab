public class Main {
  public static String createPhoneNumber(int[] numbers) {
    String result = "";
    for (int i = 0; i < numbers.length; i++) {
        if (i == 0) 
            result += '(';
        else if (i == 3) 
            result += ") ";
        else if (i == 6) 
            result += '-';

        result += numbers[i];
    }
    return result;
  }
}
