/**
 * @file Regular Expression Matching
 * cpselvis(cpselvis@gmail.com)
 * 2016.7.31
 */
#include<cstdio>


class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    if (s == NULL || p == NULL)
      return false;

    if (*p == '\0')
      return *s == '\0';

    if (*(p + 1) == '*')
    {
      while ((*s != '\0' &&  *p == '.') || *s == *p)
      {
	if (isMatch(s, p + 2))
	  return true;
	s ++;
      }
      return isMatch(s, p + 2);
    }
    else if ((*s != '\0' && *p == '.') || *s == *p)
    {
      return isMatch(s + 1, p + 1);
    }

    return false;
  }
};

int main(int argc, char **argv)
{
  Solution s;

  printf("%d\n", s.isMatch("aa", "a"));
  printf("%d\n", s.isMatch("aa", "aa"));
  printf("%d\n", s.isMatch("aaa", "aa"));
  printf("%d\n", s.isMatch("aa", "a*"));
  printf("%d\n", s.isMatch("aa", ".*"));
  printf("%d\n", s.isMatch("ab", ".*"));
  printf("%d\n", s.isMatch("aab", "c*a*b"));
}
