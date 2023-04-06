#include <iostream>

using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, k;
int arr[20][20][3]; // 상어 위치, 상어 향기 (종류, 남은시간)
int nDir[401][3]; // 상어의 현재 위치, 방향
int pDir[401][4][4]; // 상어 방향별 우선순위

int cnt = 0;

bool check(){
    if(cnt>1000) return true;
    
    for(int i=2;i<=m;i++){
        if(nDir[i][0] != -1 && nDir[i][1] != -1) return false;
    }
    return true;
}

void move(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j][2]==0){
                continue;
            } else if(arr[i][j][2]==1){
                arr[i][j][2] = 0;
                arr[i][j][1] = 0;
            } else if(arr[i][j][2]>1){
                if(arr[i][j][0]!=0){
                    arr[i][j][1] = arr[i][j][0];
                    continue;
                }
                arr[i][j][2] --;
            }
        }
    }
}


int main(){
    
    cin >> n >> m >> k;
   
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++){
            nDir[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c;
            cin >> c;
            if(c!=0){
                arr[i][j][0] = c;
                arr[i][j][1] = c;
                arr[i][j][2] = k;
                nDir[c][0] = i;
                nDir[c][1] = j;
            } else {
                arr[i][j][0] = 0;
                arr[i][j][1] = 0;
                arr[i][j][2] = 0;
            }
        }
    }
    
    for(int i=1;i<=m;i++){
        int d;
        cin >> d;
        nDir[i][2] = d-1;
    }
    
    for(int k=1;k<=m;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int d;
                cin >> d;
                pDir[k][i][j] = d-1;
            }
        }
    }
    
    while(1){
        if(check()) break;
        
        for(int i=1;i<=m;i++){
            if(nDir[i][0]==-1 && nDir[i][1]==-1) continue;
            int direction = nDir[i][2];
            int y = nDir[i][0];
            int x = nDir[i][1];
            int nx = x, ny = y;
            bool flag = false;
            int newDirection = -1;
            
            arr[y][x][0] = 0;
            
            for(int j=0;j<4;j++){
                int p = pDir[i][direction][j];
                if(y+dir[p][0] < 0 || y + dir[p][0] >= n) continue;
                else if(x+dir[p][1] < 0 || x + dir[p][1] >= n) continue;
                if(arr[y+dir[p][0]][x+dir[p][1]][1]==0) {
                    flag = true;
                    nx = x+dir[p][1]; ny = y+dir[p][0];
                    newDirection = p;
                    break;
                }
            }
            if(!flag){
                for(int j=0;j<4;j++){
                    int p = pDir[i][direction][j];
                    if(y+dir[p][0] < 0 || y + dir[p][0] >= n) continue;
                    else if(x+dir[p][1] < 0 || x + dir[p][1] >= n) continue;
                    if(arr[y+dir[p][0]][x+dir[p][1]][1]==i) {
                        nx = x+dir[p][1]; ny = y+dir[p][0];
                        newDirection = p;
                        break;
                    }
                }
            }
            
            if(arr[ny][nx][0]!=0) {
                nDir[i][0] = -1; nDir[i][1] = -1;
                continue;
            }
            
//            arr[y][x][0] = 0;
            arr[ny][nx][0] = i;
//            arr[ny][nx][1] = i;
            arr[ny][nx][2] = k;
            
            nDir[i][0] = ny; nDir[i][1] = nx;
            nDir[i][2] = newDirection;
            
            }
        move();
        cnt++;
    }
    
    
    if(cnt>1000) {
        cout << -1;
    } else{
        cout << cnt;
    }
    
    return 0;
}
