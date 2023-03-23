#include <iostream>

using namespace std;

char arr[10][10];
int xlen, ylen;
int ox, oy;

int sol(int rx, int ry, int bx, int by, int cnt, int type){
    int nrx, nry, nbx, nby;
    nrx = rx; nry = ry;
    nbx = bx; nby = by;
    
    if(cnt==11) return -1;
    bool chk = false;
    
    if(type==0){
        // up
        for(int i=ry;i>0;i--){
            if(arr[i][rx]=='O') chk = true;
            if(arr[i-1][rx]=='#') { nry = i; break; }
        }
        for(int i=by;i>0;i--){
            if(arr[i][bx]=='O') return -1;
            if(arr[i-1][bx]=='#') { nby = i; break; }
        }
        if(nrx == nbx && nry == nby){
            if(ry < by) nby++;
            else nry++;
        }
    } else if(type==1){
        // right
        for(int i=rx;i<xlen-1;i++){
            if(arr[ry][i]=='O') chk = true;
            if(arr[ry][i+1]=='#') { nrx = i; break; }
        }
        for(int i=bx;i<xlen-1;i++){
            if(arr[by][i]=='O') return -1;
            if(arr[by][i+1]=='#') { nbx = i; break; }
        }
        if(nrx == nbx && nry == nby){
            if(rx < bx) nrx--;
            else nbx--;
        }
    } else if(type==2){
        // down
        for(int i=ry;i<ylen-1;i++){
            if(arr[i][rx]=='O') chk = true;
            if(arr[i+1][rx]=='#') { nry = i; break; }
        }
        for(int i=by;i<ylen-1;i++){
            if(arr[i][bx]=='O') return -1;
            if(arr[i+1][bx]=='#') { nby = i; break; }
        }
        if(nrx == nbx && nry == nby){
            if(ry < by) nry--;
            else nby--;
        }
    } else {
        //left
        for(int i=rx;i>0;i--){
            if(arr[ry][i]=='O') chk = true;
            if(arr[ry][i-1]=='#') { nrx = i; break; }
        }
        for(int i=bx;i>0;i--){
            if(arr[by][i]=='O') return -1;
            if(arr[by][i-1]=='#') { nbx = i; break; }
        }
        if(nrx == nbx && nry == nby){
            if(rx < bx) nbx++;
            else nrx++;
        }
    }
    if(chk==true) return cnt;
    
    int ret = -1;
    
    for(int i=0;i<4;i++){
        if(i==type || i+2 == type || i-2 == type) continue;
        int sol_ret = sol(nrx, nry, nbx, nby, cnt+1, i);
        if((ret == -1 && sol_ret != -1) || (ret != -1 && sol_ret != -1 && ret > sol_ret)) {
            ret = sol_ret;
        }
    }
    
    return ret;
}


int main() {
    int rx=0, ry=0;
    int bx=0, by=0;
    
    cin >> ylen >> xlen;
    
    for(int i=0;i<ylen;i++){
        for(int j=0;j<xlen;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='R'){
                rx = j; ry = i;
            }
            if(arr[i][j]=='B'){
                bx = j; by = i;
            }
        }
    }
    
    int ret = -1;
    for(int i=0;i<4;i++){
        int sol_ret = sol(rx, ry, bx, by, 1, i);
        if((ret == -1 && sol_ret != -1) || (ret != -1 && sol_ret != -1 && ret > sol_ret)) {
            ret = sol_ret;
        }
    }
        
    cout << ret;
    return 0;
}
