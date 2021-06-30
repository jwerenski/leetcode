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
using std::min;
using std::max;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> A; vector<int> B;

        int total_length = nums1.size() + nums2.size();
        int half = total_length / 2;

        if (nums1.size() < nums2.size()) {
            A = nums1;
            B = nums2;
        } else {
            A = nums2;
            B = nums1;
        }

        int l_idx = 0; 
        int r_idx = A.size() - 1;
        int mid_A; 
        int mid_B;
        int A_left; 
        int A_right;
        int B_left; 
        int B_right;

        while(true){

            mid_A = (l_idx + r_idx) / 2;
            mid_B = half - mid_A - 2;


            if(mid_A >= 0) A_left = A.at(mid_A); else A_left = INT_MIN;

            if(mid_A < A.size() - 1) A_right = A.at(mid_A + 1); else A_right = INT_MAX;

            if(mid_B >= 0) B_left = B.at(mid_B); else B_left = INT_MIN;

            if(mid_B < B.size() - 1) B_right = B.at(mid_B + 1); else B_right = INT_MAX;


            if (A_left <= B_right && B_left <= A_right) {

                if(total_length % 2) return  min(A_right, B_right);
                return (double) (max(A_left, B_left) + min(A_right, B_right)) / 2;

            } else if (A_left > B_right){
                r_idx = mid_A - 1;
            } else {
                l_idx = mid_A + 1;
            }
        }
    }
};

int main(){

    vector<int> rng1 = {1,3};
    vector<int> rng2 = {2,7};
    Solution soln;
    cout << soln.findMedianSortedArrays(rng1, rng2) << endl;
    return 0;
}