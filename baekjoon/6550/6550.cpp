#include <iostream>

using namespace std;

int main(){
    do {
        string s, t;
        bool sub = true;
        int init = 0;
        cin >> s >> t;

        for(int i=0;i<s.length();i++){
            bool sub_sub = false;
            for(int j=init;j<t.length();j++){
                if(s[i] == t[j]){
                    init = j + 1;
                    sub_sub = true;
                    break;
                }
            }

            if(!sub_sub){
                sub = false;
            }
        }

        if(sub) cout << "Yes";
        else cout << "No";
    }while(cin.rdbuf());
}