#include <iostream>
#include <deque>

using namespace std;

int num[51][51]; // 칸 번호
int arr[51][51]; // 구슬 정보

pair<int, int> idxNum[2501]; // 좌표별 번호


int n, m;

int dir[4][2] = {{0, -1},{1, 0}, {0, 1}, {-1, 0}};
int magicDir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int marbleNum = 0;

int result[4] = {0, 0, 0, 0};

void setting(){
    int x=n/2, y=n/2;
    int d = 0;
    
    int change = 1;
    int flag = false;
    int move = 0;
    int ny = y, nx = x;
    idxNum[0] = make_pair(n/2, n/2);
    
    for(int i=1;i<n*n;i++){
        if(move==change){
            d = (d+1)%4;
            if(flag) {
                change++;
                flag = false;
            }
            else flag = true;
            move = 0;
        }
        move++;
        ny += dir[d][0];
        nx += dir[d][1];
        
        num[ny][nx] = i;
        
        idxNum[i] = make_pair(ny, nx);
        
    }
}



void solve(int d, int s){
    int x = n/2, y = n/2;
    int cnt=0;
    int first = -1;

    for(int i=0;i<s;i++){
        y += magicDir[d][0];
        x += magicDir[d][1];
        if(y < 0 || y >= n || x < 0 || x >= n) break;
        if(arr[y][x]==0) break;
        if(first == -1) first = num[y][x];
        arr[y][x] = 0;
        cnt++;
    }
    
    if(cnt==0) return;
    
    deque<int> q;

    
    for(int i=1;i<=marbleNum;i++){
        int ny = idxNum[i].first;
        int nx = idxNum[i].second;
        if(arr[ny][nx]!=0) q.push_back(arr[ny][nx]);
    }
    
    marbleNum -= cnt;
    
    for(int i=1;i<=marbleNum;i++){
        int y = idxNum[i].first;
        int x = idxNum[i].second;
        arr[y][x] = q.front();
        q.pop_front();
    }
    for(int i=marbleNum+1;i<=marbleNum+cnt;i++){
        int y = idxNum[i].first;
        int x = idxNum[i].second;
        arr[y][x] = 0;
    }
    return;
    
}


bool bump(){
    int now = arr[idxNum[1].first][idxNum[1].second];
    int cnt = 0;
    deque<int> q;
    int del = 0;
    
    for(int i=1;i<=marbleNum;i++){
        int ny = idxNum[i].first;
        int nx = idxNum[i].second;

        if(now!=arr[ny][nx]){
            if(cnt>=4){
                del += cnt;
                for(int j=0;j<cnt;j++){
                    q.pop_back();
                }
                
                result[now]+=cnt;
                
            }
            cnt = 1;
            now = arr[ny][nx];
        } else {
            cnt++;
        }
        q.push_back(arr[ny][nx]);
    }
    
    
    if(cnt>=4) {
        del += cnt;
        for(int j=0;j<cnt;j++){
            q.pop_back();
        }
        result[now]+=cnt;
    }
    
    
    if(del==0) return true;
    
    marbleNum-=del;
    
    for(int i=1;i<=marbleNum;i++){
        int y = idxNum[i].first;
        int x = idxNum[i].second;
        arr[y][x] = q.front();
        q.pop_front();
    }
    for(int i=marbleNum+1;i<=marbleNum+del;i++){
        int y = idxNum[i].first;
        int x = idxNum[i].second;
        arr[y][x] = 0;
    }
    
    
   return false;

}

void change(){
    int newArr[50][50];
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            newArr[j][k] = 0;
        }
    }
    
    int newIdx = 1;
    
    int now = arr[idxNum[1].first][idxNum[1].second];
    int cnt = 0;
    for(int i=1;i<=marbleNum;i++){
        int ny = idxNum[i].first;
        int nx = idxNum[i].second;
        if(arr[ny][nx]!=now){
            if(newIdx>=n*n) break;
            newArr[idxNum[newIdx].first][idxNum[newIdx].second] = cnt;
            newIdx++;
            if(newIdx>=n*n) break;
            newArr[idxNum[newIdx].first][idxNum[newIdx].second] = now;
            newIdx++;
            now = arr[ny][nx];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    

    if(newIdx<n*n)
        newArr[idxNum[newIdx].first][idxNum[newIdx].second] = cnt;
    newIdx++;
    if(newIdx<n*n)
        newArr[idxNum[newIdx].first][idxNum[newIdx].second] = now;
    newIdx++;

    
    marbleNum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = newArr[i][j];
            if(arr[i][j]!=0) marbleNum++;
        }
    }

    return;
}



int main(){
    
    cin >> n >> m;
    setting();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]!=0) marbleNum++;
        }
    }
    
    for(int i=0;i<m;i++){
        int d, s;
        cin >> d >> s;
        
        solve(d-1, s); // 블리자드
        while(!bump()); // 구슬 폭발
        change(); // 구슬 변화
    }

    cout << result[1]*1 + result[2]*2 + result[3]*3 ;
    
    return 0;
}
