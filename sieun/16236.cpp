#include <iostream>
#include <queue>

using namespace std;

int n;
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int s = 2;
int eat = 0;
int arr[21][21];
int x=0, y=0;

int bfs(){
    int visit[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = 0;
        }
    }
    
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(y,x), 0));

    int minDis = -1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    visit[y][x] = 1;
    for(int i=0;i<4;i++){
        if(y+dir[i][0] < 0 || y+dir[i][0] >= n || x+dir[i][1] < 0 ||  x+dir[i][1] >= n) continue;
        q.push(make_pair(make_pair(y+dir[i][0], x+dir[i][1]), 1));
    }
    
    while(!q.empty()){
        int ny = q.front().first.first;
        int nx = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        if(visit[ny][nx]) continue;
        
        visit[ny][nx] = 1;
        
        if(arr[ny][nx] < s && arr[ny][nx] > 0){
            if(minDis==-1){
                pq.push({ny, nx});
                minDis = dis;
            } else if(minDis==dis) {
                pq.push({ny, nx});
            }
            continue;
        } else if(arr[ny][nx] > s){
            continue;
        }
        
        dis ++;
        for(int i=0;i<4;i++){
            if(ny+dir[i][0] < 0 || ny+dir[i][0] >= n || nx+dir[i][1] < 0 ||  nx+dir[i][1] >= n) continue;
            q.push(make_pair(make_pair(ny+dir[i][0], nx+dir[i][1]), dis));
        }
    }
    
    if(!pq.empty()){
        y = pq.top().first;
        x = pq.top().second;
        arr[y][x] = 0;
        return minDis;
    }

    return 0;
}

int main(){
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==9) {
                y = i; x = j;
                arr[i][j] = 0;
            }
        }
    }


    int res = 0;
    while(1){
        int ret = bfs();
        if(ret > 0){
            eat ++;
            if(eat == s) {
                s ++;
                eat = 0;
            }
            res += ret;
        } else {
            break;
        }
    }
    
    cout << res ;
    
    return 0;
}
