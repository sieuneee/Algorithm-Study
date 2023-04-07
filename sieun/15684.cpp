#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[21][21];

int score = 0;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};



void move1(){
    // 중력
    int newArr[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            newArr[i][j] = -2;
        }
    }
    for(int j=0;j<n;j++){
        int idx = n-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i][j]==-2){
                continue;
            } else if(arr[i][j]==-1){
                newArr[i][j] = arr[i][j];
                idx = i-1;
            } else {
                newArr[idx][j] = arr[i][j];
                idx--;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = newArr[i][j];
        }
    }
    
}
void move2(){
    // 회전
    int newArr[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            newArr[j][i] = arr[i][n-1-j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = newArr[i][j];
        }
    }
}

bool sol(){
    queue<pair<int, int>> q;
    
    int visit[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = -1;
        }
    }
    
    
    int maxCnt = 0;
    int maxNum = 0;
    int maxRb = 0;
    int mx=0, my=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]<=0) continue;
            if(visit[i][j]==arr[i][j]) continue;
            
            int num = arr[i][j];
            int c = 1;
            int rb = 0;
            q.push({i, j});
            visit[i][j] = arr[i][j];
            while(!q.empty()){
                int qy = q.front().first;
                int qx = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    if(qy+dir[i][0]<0 || qy+dir[i][0] >= n) continue;
                    if(qx+dir[i][1]<0 || qx+dir[i][1] >= n) continue;
                    if(arr[qy+dir[i][0]][qx+dir[i][1]]==num || arr[qy+dir[i][0]][qx+dir[i][1]]==0){
                        if(visit[qy+dir[i][0]][qx+dir[i][1]]==num) continue;
                        if(arr[qy+dir[i][0]][qx+dir[i][1]]==0) rb++;
                        c++;
                        q.push({qy+dir[i][0], qx+dir[i][1]});
                        visit[qy+dir[i][0]][qx+dir[i][1]]=num;
                    }
                }
            }
            
            bool chk = false;
            if(c>maxCnt){
                chk = true;
            } else if(c==maxCnt){
                if(rb > maxRb){
                    chk = true;
                } else if (rb == maxRb) {
                    if(my < i) {
                        chk = true;
                    } else if(my==i){
                        if(mx <= j) {
                            chk = true;
                        }
                    }
                }
            }
            if(chk){
                maxCnt = c;
                maxRb = rb;
                maxNum = arr[i][j];
                my = i; mx=j;
            }
        }
    }
    if(maxCnt<2) return false;
    
    
    score += maxCnt*maxCnt;
    
    
    // 빈칸으로 변경
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = -1;
        }
    }
    
    queue<pair<int, int>> qu;
    qu.push({my, mx});
    visit[my][mx] = maxNum;
    
    while(!qu.empty()){
        int qy = qu.front().first;
        int qx = qu.front().second;
        qu.pop();

        for(int i=0;i<4;i++){
            if(qy+dir[i][0]<0 || qy+dir[i][0] >= n) continue;
            if(qx+dir[i][1]<0 || qx+dir[i][1] >= n) continue;
            if(arr[qy+dir[i][0]][qx+dir[i][1]]==maxNum || arr[qy+dir[i][0]][qx+dir[i][1]]==0){
                if(visit[qy+dir[i][0]][qx+dir[i][1]]==maxNum) continue;
                qu.push({qy+dir[i][0], qx+dir[i][1]});
                visit[qy+dir[i][0]][qx+dir[i][1]]=maxNum;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==maxNum) arr[i][j] = -2;
        }
    }
    
    return true;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    while(1){
        if(!sol()) break;
        move1();
        move2();
        move1();
    };
    cout << score;
    
    return 0;
}
