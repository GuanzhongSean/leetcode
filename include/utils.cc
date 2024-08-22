#include "utils.h"

namespace {

static char init = []() -> char {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << boolalpha;
  print("Loaded include/utils.");
  return '$';
}();

}  // namespace
