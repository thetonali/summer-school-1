void topo(){
	for(int i=1;i<=n;++i){
		if(d[i]==0)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		printf("%d ",x);
		for(int i=1;a[x][i]!=0;++i){
			d[a[x][i]]--;
			if(d[a[x][i]]==0)q.push(a[x][i]);
		}
	}
}
