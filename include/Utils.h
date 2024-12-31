#ifndef _MY_UTILS_
#define _MY_UTILS_ 1

#include <cxxabi.h>

#include <cstddef>
#include <type_traits>
#include <vector>

#include "Graph.h"
#include "ListNode.h"
#include "Node.h"
#include "TreeNode.h"

struct NodeHash {
  size_t operator()(const pair<int, int> &pair) const {
    return hash<int>()(pair.first) ^ (hash<int>()(pair.second) << 1);
  }
  size_t operator()(const pair<double, double> &pair) const {
    return hash<double>()(pair.first) ^ (hash<double>()(pair.second) << 1);
  }
};

template <typename T>
void print_human_readable_typename() {
  const char *mangledName = typeid(T).name();
  int status;
  char *demangledName = abi::__cxa_demangle(mangledName, nullptr, nullptr, &status);
  if (status == 0) {
    std::cout << "Type: " << demangledName << std::endl;
  } else {
    std::cout << "Type (mangled): " << mangledName << std::endl;
  }
  free(demangledName);
}

template <typename T, typename = void>
struct is_streamable : std::false_type {};

template <typename T>
struct is_streamable<T, std::void_t<decltype(std::declval<std::ostream &>() << std::declval<T>())>>
    : std::true_type {};

template <typename T>
constexpr bool is_streamable_v = is_streamable<T>::value;

template <typename T>
struct is_string : std::false_type {};

template <>
struct is_string<std::string> : std::true_type {};

template <>
struct is_string<const std::string> : std::true_type {};

template <>
struct is_string<const std::string(&)> : std::true_type {};

template <>
struct is_string<char *> : std::true_type {};

template <>
struct is_string<const char *> : std::true_type {};

template <std::size_t N>
struct is_string<const char[N]> : std::true_type {};

template <std::size_t N>
struct is_string<const char (&)[N]> : std::true_type {};

template <typename T, std::size_t N>
struct is_string<T[N]> : std::is_same<T, char> {};

template <typename T>
constexpr bool is_string_v = is_string<T>::value;

template <typename T>
constexpr bool is_builtin_streamable_v = is_string_v<T> || is_fundamental_v<T>;

template <size_t N>
struct Factorial {
  static constexpr size_t value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0U> {
  static constexpr size_t value = 1;
};

template <typename T, typename... Args>
void print(const T &first, const Args &...args) {
  if constexpr (sizeof...(args) > 0) {
    string delimiter = is_builtin_streamable_v<T> ? " " : "\n";
    cout << first << delimiter;
    print(args...);
  } else {
    cout << first;
    if (is_builtin_streamable_v<T>) cout << endl;
  }
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  string delimiter = is_fundamental_v<T> ? " " : "\n";
  os << "[" << delimiter;
  for (T i : v) os << i << delimiter;
  return os << "]";
}

template <typename T>
inline void print(const vector<T> &v) {
  cout << v << endl;
}

bool isPalindrome(const string &s, bool alnum_only = true);

#endif
