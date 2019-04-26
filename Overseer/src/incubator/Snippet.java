package incubator;

import java.util.Random;

/**
 * An enumeration of the available code snippets, represented as numbers 1 - n in a map and accessed
 * by a public getSnippet method.
 * 
 * Each code snippet is a few lines of C code represented as a string. Any C code could be added
 * here, we focused on things in the C standard library and solutions to our algorithm.
 * 
 * @author Virginia R Hinson
 *
 */
public enum Snippet
{
  ONE("        answers[x] = (roundl((16 * M_PI) * sqrt(to_root)))* prime;\n"
      + "        all_answers[period_num][x] = roundl((16 * M_PI) * sqrt(to_root));\n", 1),

  TWO("        answers[x] = (roundl((16 * M_PI) * sqrt(to_root)))* prime;\n"
      + "        all_answers[period_num][x] = roundl((16 * M_PI) * sqrt(to_root));\n", 2),

  THREE("        answers[x] = 42 * prime;\n" + "        all_answers[period_num][x] = 42;\n", 3),

  FOUR("        answers[x] = (roundl((2 * M_PI) * sqrt(to_root))) * prime;\n"
      + "        all_answers[period_num][x] = roundl((2 * M_PI) * sqrt(to_root));\n", 4), // correct!

  FIVE("        answers[x] = (roundl((2 * M_PI) * sin(to_root))) * prime;\n"
      + "        all_answers[period_num][x] = roundl((2 * M_PI) * sin(to_root));\n", 5),

  SIX("        answers[x] = (roundl((2 * M_PI) * cos(to_root))) * prime;\n"
      + "        all_answers[period_num][x] = roundl((2 * M_PI) * cos(to_root));\n", 6),

  SEVEN("        answers[x] = (roundl((2 * M_PI) * sqrt(to_root))) * prime;\n"
      + "        all_answers[period_num][x] = roundl((2 * M_PI) * sqrt(to_root));\n", 7),

  EIGHT("        count = rand();\n", 8),

  NINE("        //Something was here, but he is dead now.\n", 9),

  TEN("        count = 0;\n" + "          for (int i = 0; i < 10; i++) {\n"
      + "            for (int j = 0; j < 10; j++) {\n" + "              count += i + j;\n"
      + "            }\n" + "          }", 10),

  ELEVEN("      count = 0;\n" + "        for (int i = 0; i < 100; i++) {\n"
      + "            count += i;\n" + "         }", 11),

  TWELVE("        count = 0;\n" + "        count = 2.000001 * 20000000000;\n", 12),

  THIRTEEN("      count = 0;\n" + "      count = 2.000001 / 20000000000;\n", 13),

  FOURTEEN("      count = 0;\n" + "      count = 2.000001 * 20000000000 / 15.00000 + 7.1234;\n",
      14),

  FIFTEEN("       count += 17;\n", 15),

  DEFAULT("       // nothing ", -1);

  private String snippet;
  private Integer number;

  /**
   * Private constructor for Snippets
   * 
   * @param snippet
   *          a string representing the code of the snippet
   * @param number
   *          a number ID for the snippet
   */
  private Snippet(String snippet, int number)
  {
    this.snippet = snippet;
    this.number = number;
  }

  /**
   * Given the ID number, return the snippet string.
   * 
   * @param number
   *          the ID of the snippet
   * @return the string representation of the code snippet
   */
  public static String getSnippet(int number)
  {
    switch (number)
    {
      case 1:
        return ONE.snippet;
      case 2:
        return TWO.snippet;
      case 3:
        return THREE.snippet;
      case 4:
        return FOUR.snippet;
      case 5:
        return FIVE.snippet;
      case 6:
        return SIX.snippet;
      case 7:
        return SEVEN.snippet;
      case 8:
        return EIGHT.snippet;
      case 9:
        return NINE.snippet;
      case 10:
        return TEN.snippet;
      case 11:
        return ELEVEN.snippet;
      case 12:
        return TWELVE.snippet;
      case 13:
        return THIRTEEN.snippet;
      case 14:
        return FOURTEEN.snippet;
      case 15:
        return FIFTEEN.snippet;
      default:
        return DEFAULT.snippet;
    }
  }

  /**
   * Excludes the default (-1) snippet which holds no information.
   * 
   * @return the number of snips, excluding the default
   */
  public static int getNumberOfSnippets()
  {

    return Snippet.values().length - 1;
  }

  /**
   * Returns a random number (between 0 and the number of snippets) representing a code snippet.
   * 
   * @return a random number from 0 to the total snippet count
   */
  public static int getRandomSnippetNumber()
  {
    return (int) (Math.random() * (Snippet.getNumberOfSnippets() + 1));
  }
}
