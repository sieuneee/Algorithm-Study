#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[51][51];

int dir[8][2] = {
    {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
    {0, 1}, {1, 1}, {1, 0}, {1, -1}
};

int main(){
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({n-1, 0});
    q.push({n-1, 1});
    q.push({n-2, 0});
    q.push({n-2, 1});
    
    
    for(int i=0;i<m;i++){
        int d, s;
        cin >> d >> s;
        d--;
        queue<pair<int, int>> water;
        
        int cloud[51][51];
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cloud[j][k] = 0;
            }
        }
        
        while(!q.empty()){
            int y = (q.front().first + dir[d][0]*s) % n;
            if(y<0) y+=n;
            int x = (q.front().second + dir[d][1]*s) % n;
            if(x<0) x+=n;
            q.pop();
            cloud[y][x] = 1;
            water.push({y, x});
            arr[y][x] ++;
        }
        
        while(!water.empty()){
            int y = water.front().first;
            int x = water.front().second;
            water.pop();
            
            int cnt = 0;
            for(int j=1;j<8;j+=2){
                if(y+dir[j][0] < 0 || y+dir[j][0] >= n) continue;
                if(x+dir[j][1] < 0 || x+dir[j][1] >= n) continue;
                if(arr[y+dir[j][0]][x+dir[j][1]]>0) cnt++;
            }
            arr[y][x] += cnt;
        }
        
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arr[j][k]>=2 && cloud[j][k]!=1){
                    q.push({j, k});
                    arr[j][k] -= 2;
                }
            }
        }
    }
    
    
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res += arr[i][j];
        }
    }
    
    cout << res ;
    
    return 0;
}
