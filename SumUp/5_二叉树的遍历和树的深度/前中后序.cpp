#include<bits/stdc++.h>
using namespace std;
int T[10]={0,1,2,3,4,5,6,7};
int n=7;
void qianxu(int p){//��-��-�� 
    if(!T[p])return ; //û����pΪ�������� 
    printf("%d ",T[p]);//���ʵ�ǰ���
    if(2*p<=n){
        qianxu(2*p);
    }//�ݹ����������
    if(2*p+1<=n){
        qianxu(2*p+1);
    }//�ݹ����������
}

void zhongxu(int p){//��-��-�� 
	if(!T[p])return ; //û����pΪ�������� 
    if(2*p<=n){
        zhongxu(2*p);
    }//�ݹ����������
    printf("%d ",T[p]);//���ʵ�ǰ���
    if(2*p+1<=n){
        zhongxu(2*p+1);
    }//�ݹ����������
}

void houxu(int p){//��-��-�� 
	if(!T[p])return ; //û����pΪ�������� 
    if(2*p<=n){
        houxu(2*p);
    }//�ݹ����������
    if(2*p+1<=n){
        houxu(2*p+1);
    }//�ݹ����������
    printf("%d ",T[p]);//���ʵ�ǰ���
}

int main(){
	printf("����1 2 3 4 5 6 7�������������\n");
	printf("ǰ��Ϊ��");
	qianxu(1);//�����������ĸ��ڵ� 
	printf("\n");
	printf("����Ϊ��");
	zhongxu(1);
	printf("\n");
	printf("����Ϊ��");
	houxu(1);
	printf("\n");
	return 0;
}

