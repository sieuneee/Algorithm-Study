#include<iostream>
#include<queue>

using namespace std;

int n, k, l;
int arr[100][100];


int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int nowTime = 0;
int nowDir = 1;
int nowX = 0;
int nowY = 0;

queue<pair<int, int>> q;

bool sol(int t){
    bool flag = true;
    int loop = t-nowTime;
    for(int i=0;i<loop;i++){
        nowTime++;
        nowY += direction[nowDir][0];
        nowX += direction[nowDir][1];
        q.push({nowY, nowX});
        
        if(nowX >= n || nowX < 0 || nowY >= n || nowY < 0) {
            flag = false; break;
        } else if (arr[nowY][nowX]==-1) {
            flag = false; break;
        }
        
        if (arr[nowY][nowX] == 0) {
            int delY = q.front().first;
            int delX = q.front().second;
            q.pop();
            arr[delY][delX] = 0;
        }
        
        arr[nowY][nowX] = -1;
    }
    
    
    return flag;
}

int main(){
    
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = -1;
    q.push({0, 0});
    
    for(int i=0;i<k;i++){
        int x, y;
        cin >> y >> x;
        arr[y-1][x-1] = 1;
    }
    
    cin >> l;
    for(int i=0;i<l;i++){
        int t;
        char dir;
        cin >> t >> dir;
        if(!sol(t)) {
            cout << nowTime;
            return 0;
        }
        if(dir=='L'){
            nowDir --;
            if(nowDir < 0) nowDir = 3;
        } else {
            nowDir ++;
            if(nowDir > 3) nowDir = 0;
        }
    }
    sol(10000);
    
    cout << nowTime ;
    return 0;
}
