#include <iostream>
using namespace std;

/*计算关键字位数的最大值*/
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

/*基数排序*/
void RadixSort(int array[],int size)
{
	int bucket[10][10]={0};//定义基数桶
	int order[10]={0};//保存每个基数桶之中的元素个数
	int key_size=KeySize(array,size);//计算关键字位数的最大值
	
	for(int n=1;key_size>0;n*=10,key_size--)
	{
		/*将待排序的元素按照关键值的大小依次放入基数桶之中*/
		for(int i=0;i<size;i++)
		{
			int lsd=(array[i]/n)%10;
			bucket[lsd][order[lsd]]=array[i];
			order[lsd]++;
		}

		/*将基数桶中的元素重新串接起来*/
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
