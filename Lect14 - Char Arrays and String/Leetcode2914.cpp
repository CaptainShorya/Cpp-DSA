#include <iostream>
using namespace std;

int minChanges(string s) {
        int stringChanged = 0;
        for (int j = 0; j < s.length()-1; j = j + 2) { // j=0
            if (s[j] == s[j + 1]) {
                continue;
            }else {
                //s[j+1] = s[j];
                stringChanged++;
            }
        }
        return stringChanged;
    }

int main(){
    string s = "1010";
    cout << minChanges(s) << endl;
    return 0;
}