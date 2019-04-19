import java.util.*;
/**
 * Alternate solution to Project Euler #20
 * @author Roland
 */
public class Twenty {

  public static void main(String args[]) {
    if (args.length < 1) {
      System.out.println("Usage: java Twenty [N]");
      return;
    }
    int N = Integer.parseInt(args[0]);
    List<Integer> digits = new ArrayList<>();
    digits.add(1); // start multiplication from 1
    for (int i = 1; i <= N; i++) multiply(i, digits);

    int sum = digits.stream().reduce(0, (a, b) -> a + b);
    System.out.println(sum);
  }

  public static void multiply(int mult, List<Integer> digits) {
    int carry = 0;
    for (int i = 0; i < digits.size(); i++) {
      int prod = mult * digits.get(i) + carry;
      int newDig = prod;
      newDig = prod % 10;
      carry = ((prod - newDig) / 10);
      digits.set(i, newDig);
    }
    if (carry > 10) {
      digits.add(carry % 10);
      digits.add((carry - (carry%10)) / 10);
    }  else if (carry != 0) digits.add(carry);
  }
}


