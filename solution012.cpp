/**
 * Integer to Roman
 */
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string output = "";
    string roman_str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int roman_int[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i ++)
    {
      while (num >= roman_int[i])
      {
	num -= roman_int[i];
	output += roman_str[i];
      }
    }
    return output;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.intToRoman(1) << endl;
  cout << s.intToRoman(3125) << endl;
}
