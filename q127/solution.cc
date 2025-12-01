#include "Utils.h"

namespace q127 {

using namespace std;

namespace V1 {
class Solution {
   public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		unordered_map<string, vector<string>> dict;
		for (const string& s : wordList) dict[s] = {};
		if (dict.find(endWord) == dict.end()) return 0;
		for (const string& s : wordList) {
			for (size_t i = 0; i < s.size(); ++i) {
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c != s[i]) {
						string new_word = s;
						new_word[i] = c;
						if (dict.count(new_word)) dict[s].push_back(new_word);
					}
				}
			}
		}

		queue<string> q;
		q.push(beginWord);
		int depth = 0;
		while (!q.empty()) {
			depth++;
			size_t q_size = q.size();
			for (size_t i = 0; i < q_size; ++i) {
				const string& cur = q.front();
				for (const string& s : dict[cur]) {
					if (s == endWord) return depth + 1;
					q.push(s);
				}
				dict.erase(cur);
				q.pop();
			}
		}
		return 0;
	}
};
}  // namespace V1

inline namespace V2 {
class Solution {
   public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.find(endWord) == dict.end()) return 0;
		queue<string> q;
		q.push(beginWord);

		int steps = 1;

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				string curr = q.front();
				q.pop();
				if (curr == endWord) return steps;
				string original = curr;
				for (int j = 0; j < curr.size(); j++) {
					char originalChar = curr[j];
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == originalChar) continue;
						curr[j] = c;
						if (dict.find(curr) != dict.end()) {
							q.push(curr);
							dict.erase(curr);
						}
					}
					curr[j] = originalChar;
				}
			}
			steps++;
		}
		return 0;
	}
};
}  // namespace V2

}  // namespace q127
