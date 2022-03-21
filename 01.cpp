#include <iostream>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1000;
int ans,mp[N][N];
int a[N];//1亮，0灭 
int k,idx,sum;
int vis[N],e[N],f;
set<int>s;
int ne[N],h[N],w[N];
// a b c d e f g
// 1 2 3 4 5 6 7
void add(int x,int y) {//建图连边

    w[idx] = 1;
    e[idx] = y;
    ne[idx] = h[x];
   // printf("%d %d %d %d ",w[idx],e[idx],ne[idx],idx);
   // printf("%d %d ",ne[idx],idx);
	h[x] = idx++;
//	cout << x << " " << h[1] << endl;
	
//	ne[idx] = y;
//	h[x] = idx++;
}
queue<int>q;
int judge(){
    while(!q.empty()) q.pop();
	memset(vis,0,sizeof vis);
	for(int i = 1;i < 8; ++i) if(a[i]) q.push(i);
	int s = q.size();
	if(s == 0) return 0;
	if(s == 1) return 1;
	sum = 0; f = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i = h[x]; i != -1; i = ne[i]){
			int j = e[i];
			if(a[j] && !vis[j]){
				vis[x] = 1;
				sum++;
				f = 0;
			}
		}
		if(f == 1) return 0;
	}
    //cout << " " << s << " " << sum;
	if(s <= sum + 1) return 1;
	else return 0;
}
/*void print(int k){
	cout << k << " ";
	for(int i = h[k]; i != -1; i = ne[i])
	cout << e[i] << " ";
	cout << endl; 
}*/
void dfs(int x){//现在第几个灯
//cout<<x<<endl;
	if(x>=8){
		for(int i=1;i<=7;i++){
			cout<<' '<<a[i];
		}
		//cout << " " << k++;
		if(judge()) ans++;
    	cout << /*" " << ans <<*/ endl;
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
//    for(int i = 1;i < 8; ++i)
  //  print(i);

}
/*#include<iostream>
using namespace std;

const int N = 1010;
int n, m;
int dp[N][N], v[N], w[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        int v, w;
        cin >> v >> w;
        for(int j = 0; j <= m; j ++ ){
            dp[i][j] = dp[i - 1][j];
            if(j >= v)
                dp[i][j] = max(dp[i][j], dp[i][j - v] + w);
        }
            for(int i = 1 ; i<=n ;i++){
    for(int j = 0 ; j<=m ;j++)
    {
        cout << dp[i][j] << " ";
    }
    cout << endl;
}
    }
 
    cout << dp[n][m] << endl;
}*/ 
/*
  
/*
4 5
1 2
2 4
3 4
4 5
*/
