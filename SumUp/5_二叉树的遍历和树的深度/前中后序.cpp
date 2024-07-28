#include<bits/stdc++.h>
using namespace std;
int T[10]={0,1,2,3,4,5,6,7};
int n=7;
void qianxu(int p){//中-左-右 
    if(!T[p])return ; //没有以p为根的子树 
    printf("%d ",T[p]);//访问当前结点
    if(2*p<=n){
        qianxu(2*p);
    }//递归遍历左子树
    if(2*p+1<=n){
        qianxu(2*p+1);
    }//递归遍历右子树
}

void zhongxu(int p){//左-中-右 
	if(!T[p])return ; //没有以p为根的子树 
    if(2*p<=n){
        zhongxu(2*p);
    }//递归遍历左子树
    printf("%d ",T[p]);//访问当前结点
    if(2*p+1<=n){
        zhongxu(2*p+1);
    }//递归遍历右子树
}

void houxu(int p){//左-右-中 
	if(!T[p])return ; //没有以p为根的子树 
    if(2*p<=n){
        houxu(2*p);
    }//递归遍历左子树
    if(2*p+1<=n){
        houxu(2*p+1);
    }//递归遍历右子树
    printf("%d ",T[p]);//访问当前结点
}

int main(){
	printf("对于1 2 3 4 5 6 7这颗满二叉树：\n");
	printf("前序为：");
	qianxu(1);//传入整棵树的根节点 
	printf("\n");
	printf("中序为：");
	zhongxu(1);
	printf("\n");
	printf("后序为：");
	houxu(1);
	printf("\n");
	return 0;
}

