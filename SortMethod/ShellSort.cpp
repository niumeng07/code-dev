#include <iostream>
using namespace std;

/*交换函数，作用是交换数组中的两个元素的位置*/
void swap(int array[],int i,int j)
{
	int tmp=array[i];
	array[i]=array[j];
	array[j]=tmp;
}

/*希尔排序*/
void ShellSort(int array[],int n)
{
	for(int delta=n/2;delta>0;delta/=2)
	{
		for(int i=0;i<delta;i++)
		{
			for(int j=i+delta;j<n;j+=delta)
			{
				for(int k=j;k>0;k-=delta)
				{
					if(array[k]<array[k-1])
						swap(array,k,k-1);
				}
			}
		}
	}
}

int main()
{
	int array[8]={6,8,7,3,1,2,5,4};
	ShellSort(array,8);
	for(int i=0;i<8;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}