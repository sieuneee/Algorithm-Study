#include <iostream>

using namespace std;

int d[8][2] = {
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
    {1, 0}, {1, 1}, {0, 1}, {-1, 1}
};

int maxEat = 0;

void move(int pos[17], int arr[5][5], int dir[5][5]){
    for(int i=1;i<=16;i++){
        if(pos[i]==-1) continue;
        int y = pos[i]/4;
        int x = pos[i]%4;
        
        int direction = dir[y][x];
        int ny=y, nx=x;
        
        bool flag = false;
        for(int j=0;j<7;j++){
            ny = y+d[direction][0];
            nx = x+d[direction][1];
            if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || arr[ny][nx]==-1) {
                direction = (direction+1)%8;
            } else {
                flag = true;
                break;
            }
        }
        if(!flag) {
            continue;
        }
        
        int tmp;
        
        pos[i] = ny*4+nx;
        pos[arr[ny][nx]] = y*4+x;
        
        tmp = arr[y][x];
        arr[y][x] = arr[ny][nx];
        arr[ny][nx] = tmp;
        
        dir[y][x] = dir[ny][nx];
        dir[ny][nx] = direction;
        
    }
}

int sol(int y, int x, int direction, int pos[17], int arr[5][5], int dir[5][5], int cnt, int eat){
    if(cnt >= 16) {
        if(eat > maxEat) maxEat = eat;
        return maxEat;
    }
    
    int ny = y;
    int nx = x;
    
    move(pos, arr, dir);
    
    while(1){
        ny = ny + d[direction][0];
        nx = nx + d[direction][1];
        if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
            break;
        }
        if(arr[ny][nx]==0) continue;
        
        int newPos[17];
        int newArr[5][5];
        int newDir[5][5];
        
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                newArr[i][j] = arr[i][j];
                newDir[i][j] = dir[i][j];
            }
        }
        for(int i=0;i<=16;i++){
            newPos[i] = pos[i];
        }
        
        int newEat = eat + newArr[ny][nx];
        newPos[newArr[ny][nx]] = -1;
        newArr[ny][nx] = -1;
        newArr[y][x] = 0;
        sol(ny, nx, newDir[ny][nx], newPos, newArr, newDir, cnt+1, newEat);
    }

    if(eat > maxEat) maxEat = eat;
    return maxEat;
}



int main(){
    int arr[5][5];
    int dir[5][5];
    int pos[17];
    
    for(int i=0;i<=16;i++){
        pos[i] = -1;
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int d;
            cin >> arr[i][j] >> d;
            dir[i][j] = d-1;
            pos[arr[i][j]] = i*4+j;
        }
    }

    int eat = arr[0][0];
    pos[arr[0][0]] = -1;
    arr[0][0] = -1;
    sol(0, 0, dir[0][0], pos, arr, dir, 1, eat);
    
    
    cout << maxEat;
    
    return 0;
}
