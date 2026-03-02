#include <iostream>
using std::cin;
using std::cout;


// #1
// struct soo{
//     int pos;
//     int t;
//     struct soo *next;
// };

// void add(struct soo *end, int pos, int t){
//     struct soo *newNode = new soo();
//     newNode->pos = pos;
//     newNode->t = t;
//     newNode->next = nullptr;

//     end->next = newNode;
// }

// int main(){
//     int n = 0;
//     int k = 0;

//     bool visited[100001] = {false, };

//     struct soo *current = nullptr;
//     struct soo *end = nullptr;

//     cin >> n >> k;

//     struct soo *head = new soo();
//     head->pos = n;
//     head->t = 0;
//     head->next = nullptr;
//     current = head;
//     end = head;

//     while (true){
//         if(current->pos == k){
//             cout << current->t;
//             break;
//         }
//         else if(current->pos > k){
//             add(end, current->pos-1, current->t+1);
//             end = end->next;
//             visited[current->pos-1] = true;
//         }
//         else{
//             if(current->pos > 0 && !visited[current->pos-1]){
//                 add(end, current->pos-1, current->t+1);
//                 end = end->next;
//                 visited[current->pos-1] = true;
//             }
//             if(current->pos < 100000 && !visited[current->pos+1]){
//                 add(end, current->pos+1, current->t+1);
//                 end = end->next;
//                 visited[current->pos+1] = true;
//             }
//             if(current->pos < 50001 && !visited[current->pos*2]){
//                 add(end, current->pos*2, current->t+1);
//                 end = end->next;
//                 visited[current->pos*2] = true;
//             }
//         }
//         struct soo* old = current;
//         current=current->next;
//         delete old;
//     }
// }


// #2
#include <queue>

int main(){
    std::queue<int> q;

    int t[100001] = {0, };
    bool visited[100001] = {false, };

    int n, k;
    cin >> n >> k;
    q.push(n);

    while(q.front() != k){
        int pos = q.front();

        if(0 <= pos-1 && pos-1 <= 100000 && !visited[pos-1]){
            q.push(pos-1);
            t[pos-1] = t[pos]+1;
            visited[pos-1] = true;
        }
        if(0 <= pos+1 && pos+1 <= 100000 && !visited[pos+1]){
            q.push(pos+1);
            t[pos+1] = t[pos]+1;
            visited[pos+1] = true;
        }
        if(0 <= pos*2 && pos*2 <= 100000 && !visited[pos*2]){
            q.push(pos*2);
            t[pos*2] = t[pos]+1;
            visited[pos*2] = true;
        }

        q.pop();
    }
    cout << t[k];
}