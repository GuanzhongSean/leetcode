#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution { // read one by one
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> words0{};
        for (string word : words) words0[word]++;
        int k = words[0].size();
        int len = k * words.size();
        vector<int> result{};
        if (len > s.size()) return result;
        for (int i = 0; i <= s.size() - len; i++) {
            unordered_map<string, int> words_{words0};
            string substring = s.substr(i, len);
            for (int j = 0; j < len; j += k) {
                string cur_word = substring.substr(j, k);
                if (words_[cur_word] > 0) {
                    words_[cur_word] -= 1;
                } else {
                    break;
                }
                if (j == len - k) result.push_back(i);
            }
        }
        return result;
    }
};

class Solution2 { // sliding window
public:
    vector<int> findSubstring1(string s, vector<string>& words) {
        int m = s.size(), n = words.size(), len = words[0].size();
        vector<int> ans;
        unordered_map<string,int> dic;
        for (string word: words) dic[word]++;
        for (int i = 0; i < len; i++) {
            unordered_map<string,int> temp;
            int lb = i, ub = i + len, count = 0;;
            bool flag = true;
            while (ub <= m) {
                if (flag) {
                    temp[s.substr(ub - len,len)]++;
                    count++;
                } else {
                    temp[s.substr(lb - len,len)]--;
                    count--;
                }
                string subStr = s.substr(ub - len, len);
                if (temp[subStr] > dic[subStr]) {
                    lb += len;
                    flag = false;
                } else {
                    ub += len;
                    flag = true;
                    if(count == n) ans.push_back(lb);
                }
            }
        }
        return ans;
    }
};

class Solution3 { // matcher from leetcode solution
public:
	struct matcher {
		struct info { int mtindex, count; };
		unordered_map<string_view, info>dict;
		int different_word_count;

		vector<int>slot;
		int maching_slot_count;

		matcher(const vector<string>& words) {
			int mtind = 0;
			for (auto& word : words) {
				auto find = dict.find(word);
				if (find != dict.end()) {
					++find->second.count;
				}
				else { dict[word] = { mtind++,1 }; }
			}
			different_word_count = mtind;
			slot = vector<int>(different_word_count, 0);
			maching_slot_count = 0;
		}

		void reset() {
			for (auto& i : slot) { i = 0; }
			maching_slot_count = 0;
		}
		bool match() {
			return maching_slot_count == different_word_count;
		}
		void push(string_view sv) {
			auto find = dict.find(sv);
			if (find == dict.end())return;
			if (++slot[find->second.mtindex] == find->second.count) {
				++maching_slot_count;
			}
		}
		void pop(string_view sv) {
			auto find = dict.find(sv);
			if (find == dict.end())return;
			if (--slot[find->second.mtindex] == find->second.count - 1) {
				--maching_slot_count;
			}
		}
	};
	vector<int> findSubstring(string s, const vector<string>& words) {
		int word_count = words.size();
		int word_len = words[0].size();

		matcher matcher(words);

		const char* str = s.c_str();
		int len = s.size();
		vector<int> ret;

		for (int off = 0; off < word_len; off++) {
			const char* beg = str + off, * end = str + len;
			if (beg + word_len * word_count <= end) {
				matcher.reset();
				for (int i = 0; i < word_count; i++) {
					string_view sv(beg + i * word_len, word_len);
					matcher.push(sv);
				}
				if (matcher.match()) {
					ret.push_back(beg - str);
				}
				const char* pos = beg + word_len * word_count;
				while (pos + word_len <= end) {
					string_view del(beg, word_len);
					string_view add(pos, word_len);
					beg += word_len;
					pos += word_len;
					matcher.pop(del);
					matcher.push(add);
					if (matcher.match()) {
						ret.push_back(beg - str);
					}
				}
			}
		}
		return ret;
	}
};

int main() {
    Solution s;
    vector<string> words{"a","a"};
    auto result = s.findSubstring("a", words);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}
