#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int> a, tuple<int, int> b){
    return get<0>(a) < get<0>(b);
}

int main(){
    int n;
    int cnt = 0;
    cin >> n;

    vector<tuple<int, int>> meets(n);
    vector<int> graph(n);
    stack<int> table;

    // input
    for(int i=0;i<n;i++){
        int start, end;
        cin >> start >> end;
        meets[i] = {start, end};
    }

    // sort
    sort(meets.begin(), meets.end(), cmp);

    // draw graph
    for(int i=0;i<n;i++){
        graph[i] = -1;
        for(int j=i+1;j<n;j++){
            if(get<1>(meets[i]) <= get<0>(meets[j])){
                graph[i] = j;
            }
        }
    }

    
}