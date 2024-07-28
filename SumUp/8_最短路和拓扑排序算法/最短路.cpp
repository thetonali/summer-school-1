#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
//链式前向星存图 
int head[N],cnt;
struct edge{
	int v,w,nxt;
}e[M<<1];
void addedge(int u,int v,int w){
	e[++cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
} 
//记录有哪些节点被松弛 
struct node{
	int u,dis;
	friend bool operator <(const node &a,const node &b){
		return a.dis>b.dis;
	}
}tp;
priority_queue<node>q;

int dis[N];

int n,m,s;
void dij(){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push((node){s,0});
	while(!q.empty()){
		node now=q.top();q.pop();
		int u=now.u;
		if(now.dis!=dis[u])continue;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[u]+e[i].w<dis[v]){
				dis[v]=dis[u]+e[i].w;
				q.push((node){v,dis[v]});
			}
		}
	}
}
int u,v,w;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	dij();
	for(int i=1;i<=n;++i){
		printf("%d ",dis[i]);
	}
	return 0;
}

