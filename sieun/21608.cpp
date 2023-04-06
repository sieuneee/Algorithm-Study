#include <iostream>

using namespace std;

int n;
int arr[21][21]; // 자리 배열
int num[21][21]; // 빈자리 수

int like[401][5]; // 좋아하는 학생
int idx[401]; // 앉는 순서

int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1,0}};
int score[5] = {0, 1, 10, 100, 1000};

int findFriend(int x, int y, int index){
    int cnt = 0;
    for(int i=0;i<4;i++){
        int ny = y+dir[i][0];
        int nx = x+dir[i][1];
        if(nx < 0 || nx >= n) continue;
        if(ny < 0 || ny >= n) continue;
        for(int k=1;k<5;k++){
            if(arr[ny][nx]==like[index][k]) {
                cnt++;
            }
        }
    }
    return cnt;
}


int sol(int stu){

    int maxCnt = -1;
    int minX=-1, minY=-1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=-1) continue;
            int friendNum = findFriend(j, i, stu);
            if(maxCnt < friendNum) {
                maxCnt = friendNum;
                minY = i; minX = j;
            } else if(maxCnt==friendNum){
                if(num[i][j]>num[minY][minX]){
                    minY = i; minX = j;
                }
            }
        }
    }
    
    return minY*n+minX;
}



int main(){
    cin >> n;
    
    //입력
    for(int i=0;i<n*n;i++){
        for(int j=0;j<5;j++){
            int a;
            cin >> a;
            like[i][j] = a-1;
        }
        idx[like[i][0]] = i;
    }
    
    //초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = -1;
        }
    }
    
    // 빈칸 계산
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int k=0;k<4;k++){
                if(i+dir[k][0] < 0 || i+dir[k][0] >= n) continue;
                if(j+dir[k][1] < 0 || j+dir[k][1] >= n) continue;
                if(arr[i+dir[k][0]][j+dir[k][1]] == -1){
                    cnt++;
                }
            }
            num[i][j] = cnt;
        }
    }
    
    for(int i=0;i<n*n;i++){
        // 위치 선정
        int index = sol(i);
        int y = index/n;
        int x = index%n;
        
        // 위치 업데이트
        arr[y][x] = like[i][0];
        
        // 빈간 업데이트
        for(int k=0;k<4;k++){
            if(y+dir[k][0] < 0 || y+dir[k][0] >= n) continue;
            if(x+dir[k][1] < 0 || x+dir[k][1] >= n) continue;
            num[y+dir[k][0]][x+dir[k][1]]--;
        }
    }

    // 결과 계산
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt = findFriend(j, i, idx[arr[i][j]]);
            res += score[cnt];
        }
    }
    
    cout << res;
    
    return 0;
}
