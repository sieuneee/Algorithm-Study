#include <iostream>
#include <algorithm>

using namespace std;

int n, m, x, y, k;
int arr[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0};

void move(int type){
    if (type==1){
        // 동
        int temp = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = temp;
    } else if (type==2) {
        // 서
        int temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    } else if (type==3) {
        // 북
        int temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[0];
        dice[0] = temp;
    } else {
        // 남
        int temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }
}

int main(){
    
    cin >> n >> m >> y >> x >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    int num;
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for(int i=0;i<k;i++){
        cin >> num;
        int nx = x+dir[num-1][1];
        int ny = y+dir[num-1][0];
        if((ny >= 0 && ny <= n-1) && (nx >= 0 && nx <= m-1)) {
            x = nx; y = ny;
            move(num);
            if(arr[ny][nx] == 0){
                arr[ny][nx] = dice[5];
            } else {
                dice[5] = arr[ny][nx];
                arr[ny][nx] = 0;
            }
            cout << dice[0] << endl;
        }
    }

    return 0;
}
