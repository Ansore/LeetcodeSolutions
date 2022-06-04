#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string addBinary(string a, string b) {
			int Alen = a.length() - 1;
			int Blen = b.length() - 1;
			// 是否需要进位
			bool flag = false;
			string result = "";
			while(Alen >= 0 || Blen >= 0 || flag == true) {
				if(Alen >= 0 && Blen >= 0) {
					if(a[Alen] == '1' && b[Blen] == '1') {
						if(flag) {
							result = '1' + result;
						} else {
							result = '0' + result;
							flag = true;
						}
					} else {
						if(a[Alen] == '0' && b[Blen] == '0') {
							if(flag) {
								result = '1' + result;
								flag = false;
							} else {
								result = '0' + result;
							}
						} else {
							if(flag) {
								result = '0' + result;
							} else {
								result = '1' + result;
							}
						}
					}
				} else {
					if(Alen >= 0) {
						if(a[Alen] == '1') {
							if(flag) {
								result = '0' + result;
							} else {
								result = '1' + result;
							}
						} else {
							if(flag) {
								result = '1' + result;
								flag = false;
							} else {
								result = '0' + result;
							}
						}
					} else {
						if(Blen >= 0) {
							if(b[Blen] == '1') {
								if(flag) {
									result = '0' + result;
								} else {
									result = '1' + result;
								}
							} else {
								if(flag) {
									result = '1' + result;
									flag = false;
								} else {
									result = '0' + result;
								}
							}
						} else {
							if(flag) {
								result = '1' + result;
								flag = false;
							}
						}
					}
				}
				Alen --;
				Blen --;
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.addBinary("11", "1") << endl;
	return 0;
}
