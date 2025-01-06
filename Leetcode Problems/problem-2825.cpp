#include <iostream>
#include <string>
using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    int j;
    for (int i = 0; i < str2.length(); i++)
    {
        cout << str2[i] << endl;
        while(j < str1.length())
        {
            cout << str1[j] << endl;
            if (str2[i] != str1[j])
            {
                if (str1[j] != 'z')
                {
                    str1[j] = char(int(str1[j]) + 1);
                    if(str2[i] == str1[j]){
                        break;
                    }
                }
                else
                {
                    str1[j] = 'a';
                }
                
            }else{
                j++;
            }
        }
    }
    cout << str1 <<" " << str2 << endl;
    int isCheck = 0;
    for(int i=0; i<str2.length(); i++){
        for(int j=i; j<str1.length(); j++){
            if(str2[i] == str1[j]){
                isCheck++;
            }
        }
    }
    if(isCheck == str2.length()){
        return true;
    }else{
        return false;
    }
}

int main()
{
    string str1, str2;
    str1 = "aqe";
    str2 = "qe";
    cout << canMakeSubsequence(str1, str2) << endl;
    return 0;
}