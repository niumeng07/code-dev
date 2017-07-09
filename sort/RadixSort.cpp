#include <iostream>
using namespace std;

/*����ؼ���λ�������ֵ*/
int KeySize(int array[],int size)
{
	int key_size=1;

	for(int i=0;i<size;i++)
	{
		int temp=1;
		int n=10;
		while(array[i]/n>0)
		{
			temp++;
			n*=10;
		}
        key_size=(temp>key_size)?temp:key_size;
	}
	return key_size;
}

/*��������*/
void RadixSort(int array[],int size)
{
	int bucket[10][10]={0};//�������Ͱ
	int order[10]={0};//����ÿ������Ͱ֮�е�Ԫ�ظ���
	int key_size=KeySize(array,size);//����ؼ���λ�������ֵ
	
	for(int n=1;key_size>0;n*=10,key_size--)
	{
		/*���������Ԫ�ذ��չؼ�ֵ�Ĵ�С���η������Ͱ֮��*/
		for(int i=0;i<size;i++)
		{
			int lsd=(array[i]/n)%10;
			bucket[lsd][order[lsd]]=array[i];
			order[lsd]++;
		}

		/*������Ͱ�е�Ԫ�����´�������*/
		int k=0, i = 0;
		for(i=0;i<10;i++)
		{
			if(order[i]!=0)
			{
				for(int j=0;j<order[i];j++)
				{
					array[k]=bucket[i][j];
					k++;
				}
				order[i]=0;
			}
		}
	}
}

int main()
{
	int array[10]={73,22,93,43,55,14,28,65,39,81};
	int size=sizeof(array)/sizeof(int);
	RadixSort(array,size);
	for(int i=0;i<size;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}
