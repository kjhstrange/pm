#include <iostream>
#include <vector>

using namespace std;

int add(int len, int r, int c){
    int val = 0;
    if(r >= len / 2){
        val += len*len/2;
    }
    if(c >= len / 2){
        val += len*len/4;
    }
    return val;
}

int main(){
    int N, r, c;
    cin >> N >> r >> c;
    int ans = 0;

    int len = 1;
    for(int i=0;i<N;i++){
        len *= 2;
    }

    while(len > 1){
        ans += add(len, r, c);
        len /= 2;
        if(r>=len){r-=len;}
        if(c>=len){c-=len;}
    }

    cout << ans;
}