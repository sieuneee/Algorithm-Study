#include <iostream>
#include <queue>

using namespace std;


int arr[21][21];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dice[7] = {0, 1, 2, 3, 4, 5, 6};
//  2
//4 1 3
//  5
//  6


int n, m, k;
int d; // 현재 이동 방향 (북 : 0, 동 : 1, 남 : 2, 서 : 3)

int x, y;

int move(){
    // 주사위 위치 변환
    y = y+dir[d][0];
    x = x+dir[d][1];
    if( y<0 || y>=n || x<0 || x>=m ) {
        d = (d+2)%4;
        y = y+dir[d][0]*2;
        x = x+dir[d][1]*2;
    }
    
    if(d==0){ //북
        int tmp = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = tmp;
    } else if(d==1){ // 동
        int tmp = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = tmp;
    } else if(d==2){ // 남
        int tmp = dice[6];
        dice[6] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    } else{ //서
        int tmp = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = tmp;
    }
    
    if(dice[6]>arr[y][x]){
        // 90도 시계 방향 회전
        d ++;
        if(d>=4) d-=4;
    } else if(dice[6]<arr[y][x]){
        // 90도 반시계 방향 회전
        d --;
        if(d<0) d+=4;
    }
    
    return arr[y][x];
}


int sol(){
    
    int moveScore = move();
    
    queue<pair<int, int>> q;
    int visit[21][21] = {0, };
    
    int cnt = 0;
    
    q.push({y, x});
    visit[y][x] = 1;
    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        cnt++;
        
        for(int i=0;i<4;i++){
            if(ny+dir[i][0] < 0 || ny+dir[i][0] >= n) continue;
            if(nx+dir[i][1] < 0 || nx+dir[i][1] >= m) continue;
            if(visit[ny+dir[i][0]][nx+dir[i][1]]==0 && arr[ny+dir[i][0]][nx+dir[i][1]]==moveScore){
                q.push({ny+dir[i][0], nx+dir[i][1]});
                visit[ny+dir[i][0]][nx+dir[i][1]] = 1;
            }
        }
    }
    
    
    return moveScore * cnt;
}



int main(){
    
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    x = 0; y = 0;
    d = 1;
    
    int res = 0;
    for(int i=0;i<k;i++){
        res += sol();
    }
    
    cout << res << endl;
    
    return 0;
}
