#include "Utils.h"

namespace {

static const char _([]() -> char {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << boolalpha;
  print("Loaded include/Utils.");
  return '$';
}());

bool isPalindrome(string s, bool alnum_only) {
  if (s.empty()) return true;
  int l = 0, r = s.size() - 1;
  while (l < r) {
    while (alnum_only && l < r && !isalnum(s[l])) ++l;
    while (alnum_only && l < r && !isalnum(s[r])) --r;
    if (l < r && tolower(s[l]) != tolower(s[r])) return false;
  }
  return true;
}

}  // namespace
