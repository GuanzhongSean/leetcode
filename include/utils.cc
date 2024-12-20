#include "utils.h"

namespace {

static const char _([]() -> char {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << boolalpha;
  print("Loaded include/utils.");
  return '$';
}());

}  // namespace
