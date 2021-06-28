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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> soln = {-1,-1};

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++){
                if(target - nums.at(i) == nums.at(j)){
                    soln = {i,j};
                }
            }
        }
        return soln;
    }
};


int main() {

    Solution mysoln;

    vector<int> nums = {1,3,5,7};
    int target = 8;
    vector<int> myvec = mysoln.twoSum(nums,target);

    cout << myvec[0] << " " << myvec[1] << endl;


    return 0;
}