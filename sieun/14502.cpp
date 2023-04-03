#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int maxValue = 0;
queue<pair<int, int>> q;

int check(int arr[8][8]){
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int k=0;k<4;k++){
            if(y+dir[k][0] >= n || y+dir[k][0] < 0 || x+dir[k][1] >= m || x+dir[k][1] <0 ) continue;
            if(arr[y+dir[k][0]][x+dir[k][1]] == 0) {
                arr[y+dir[k][0]][x+dir[k][1]] = 2;
                q.push({y+dir[k][0], x+dir[k][1]});
            }
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) cnt++;
        }
    }
    return cnt;
}


void sol(int arr[8][8], int cnt, int y, int x){
    if(cnt==3) {
        int newArr[8][8];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newArr[i][j] = arr[i][j];
                if(arr[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int ret = check(newArr);
        if(ret > maxValue) maxValue = ret;
        return ;
    }
    
    for(int i=y;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==y && j<x) continue;
            if(arr[i][j]==0){
                int newArr[8][8];
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        newArr[i][j] = arr[i][j];
                    }
                }
                newArr[i][j] = 1;
                sol(newArr, cnt+1, i, j);
            }
        }
    }
}

int main(){
    int arr[8][8];

    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    
    stack<pair<int, int>> st;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                int newArr[8][8];
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        newArr[i][j] = arr[i][j];
                    }
                }
                newArr[i][j] = 1;
                sol(newArr, 1, i, j);
            }
        }
    }
    
    cout << maxValue ;
    
    return 0;
}
