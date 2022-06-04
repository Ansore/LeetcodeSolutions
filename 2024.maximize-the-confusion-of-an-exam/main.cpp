#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int maxConsecutiveAnswers(string answerKey, int k) {
            int len = answerKey.length();
            if (len == 1) return len;
            int count = k;
            int result = 0;
            int r = 0;
            int l = 0;
            for (l = 0; l < len-1 && l <= r; l ++) {
                if (l > 0 && answerKey[l-1] == 'F') {
                    count ++;
                }
                /* r = l+result-1 < 0? 0:l+result-1; */
                while(r < len && (answerKey[r] == 'T' || count > 0)) {
                    if (answerKey[r] != 'T') {
                        count --;
                    }
                    r ++;
                }
                /* r --; */
                /* cout << l << "+" << r << endl; */
                if (r-l > result) {
                    result = r-l;
                }
            }
            r = 0;
            count = k;
            for (l = 0; l < len-1 && l <= r; l ++) {
                if (l > 0 && answerKey[l-1] == 'T') {
                    count ++;
                }
                /* r = l+result-1 < 0? 0:l+result-1; */
                while(r < len && (answerKey[r] == 'F' || count > 0)) {
                    if (answerKey[r] != 'F') {
                        count --;
                    }
                    r ++;
                }
                /* r --; */
                /* cout << l << "-" << r << endl; */
                if (r-l > result) {
                    result = r-l;
                }
            }
            return result;
        }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.maxConsecutiveAnswers("FFFTTFTTFT", 3);
    return 0;
}
