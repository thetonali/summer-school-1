bool spfa(){
	queue<int> q; 
    for(int i=1; i<=n; i++){ //�����н�����
	    st[i] = true;
		q.push(i);	  
    }
	while(q.size()){ // ���в���
		int t = q.front(); //ȡ��ͷ 
		q.pop();
		st[t] = false; // ����������Ѿ����ڶ�����
		for(int i = h[t]; i!=-1; i=ne[i]){ // ���� t �������ٱ߽������· 
			int j = e[i];
			if(dis[j] > dis[t]+w[i]){
				dis[j] = dis[t] + w[i];
			    cnt[j] = cnt[t] + 1; // t�����ı���+1 
			    if(cnt[j] >= n) return true;// ���ڸ��� 
				if(!st[j]){  //��� j ���ڶ��У��� j ��� 
					q.push(j); 
					st[j] = true;  // ��� j �ڶ��� 
				} 	    	
			}	
		}	
	} 
	return false;// �����ڸ��� 
}

