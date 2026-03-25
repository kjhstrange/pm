#include <iostream>
#include <vector>
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
    vector<int> val(n, 1);

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
                break;
            }
        }
    }

    // finding answer
    for(int i=n-1;i>=0;i--){
        if(graph[i] == -1)continue;

        int upper_bound = n;
        for(int j=graph[i];j<n;j++){
            if(j >= upper_bound)break;

            if(val[j] >= val[i]){
                val[i] = val[j] + 1;
            }
            if(upper_bound > graph[j]){
                upper_bound = graph[j];
            }
        }

        if(cnt < val[i]){
            cnt = val[i];
        }
    }   
    
    cout << cnt;
}