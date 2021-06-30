#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <map>

using std::map;
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0) return 0;
        int longestLength = 0;
        vector<char> longestSubstring; 
        vector<char>::iterator finder;


        for (string::iterator it = s.begin(); it != s.end(); ++it) {

            finder = find(longestSubstring.begin(), longestSubstring.end(), *it);
            if(finder == longestSubstring.end()){
                longestSubstring.push_back(*it);
            } else {
                
                longestSubstring = {finder + 1, longestSubstring.end()};
                longestSubstring.push_back(*it);
            }
            
            if(longestSubstring.size() > longestLength){
                longestLength = longestSubstring.size();
            }

        }

        return longestLength;
    }
};


int main() {

    string test = "abcabcbb";
    Solution soln;

    int longest = soln.lengthOfLongestSubstring(test);
    cout << "Longest Substring: " << longest << endl;

    return 0;
}