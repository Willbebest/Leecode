class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());
        int low = 0;
        int high = s.size() -1;
        while(low < high) {
            swap(s[low++], s[high--]);
        }
    }
};