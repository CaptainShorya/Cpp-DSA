#include <iostream>
#include <string>
using namespace std;

//Binary String problem
void binString(int n, int lastplace, string ans){
    if( n == 0 ){
        cout << ans << endl;
        return;
    }

    if(lastplace != 1){
        binString(n-1, 0 , ans + '0');
        binString(n-1, 1 , ans + '1');
    }else{
        binString(n-1, 0 , ans + '0');
    }
}

void binString2(int n, string ans){
    if( n == 0 ){
        cout << ans << endl;
        return;
    }

    if(ans[ans.size()-1] != '1'){ //If we use == '0', we do not get all desired output as it will initially run the else loop always which is not correct.
        binString2(n-1, ans + '0');
        binString2(n-1, ans + '1');
    }else{
        binString2(n-1, ans + '0');
    }
}

int main(){
    string ans = "" ;
    binString(3,0,ans);
    binString2(3,ans);
    return 0;
}