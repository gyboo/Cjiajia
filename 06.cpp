#include <iostream>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1000;
int ans,mp[N][N];
int a[N];//1亮，0灭 
int k,idx,bian;
int vis[N],e[N],f;
int ne[N],h[N],w[N];
// a b c d e f g
// 1 2 3 4 5 6 7
void add(int x,int y) {//建图连边
    w[idx] = 1;
    e[idx] = y;
    ne[idx] = h[x];
	h[x] = idx++;
}
queue<int>q;
int judge(){
    while(!q.empty()) q.pop();
	memset(vis,0,sizeof vis);
	for(int i = 1;i < 8; ++i) if(a[i]) q.push(i);
	int dian = q.size();
	if(dian == 0) return 0;
	if(dian == 1) return 1;
	bian = 0; 
	while(!q.empty()){
		f = 1; //判断是否有与其相连的边 
		int x = q.front(); q.pop();
		for(int i = h[x]; i != -1; i = ne[i]){
			int j = e[i];
			if(a[j]){
				f = 0;
				if(!vis[j]){
				vis[x] = 1;
				bian++;
			    }
			}
		}
		if(f == 1) return 0;
	}
	if(dian <= bian + 1) return 1;
	else return 0;
}
void dfs(int x){//现在第几个灯
	if(x>=8){	
		if(judge()) ans++;
		return;
	} 
	dfs(x+1);
	a[x]=1;//开
	dfs(x+1);
	a[x]=0; 
}
int main(){
	memset(h,-1,sizeof h);
	add(1,2),add(1,6);
	add(2,1),add(2,3),add(2,7);
	add(3,4),add(3,7),add(3,2);
	add(4,3),add(4,5);
	add(5,4),add(5,6),add(5,7);
	add(6,1),add(6,5),add(6,7);
	add(7,2),add(7,3),add(7,5),add(7,6);
	dfs(1);
	cout << ans << endl;
}
//    for(int i = 1;i < 8; ++i)
  //  print(i);

/*void print(int k){
	cout << k << " ";
	for(int i = h[k]; i != -1; i = ne[i])
	cout << e[i] << " ";
	cout << endl; 
}*/
