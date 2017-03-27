#include <iostream>
using namespace std;

/*交换函数，作用是交换数组中的两个元素的位置*/
void swap(int array[],int i,int j)
{
	int tmp=array[i];
	array[i]=array[j];
	array[j]=tmp;
}

/*冒泡排序*/
void BubbleSort(int array[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(array[j]<array[j-1])
				swap(array,j,j-1);
		}
	}
}

int main()
{
	int array[5]={3,1,2,5,4};
	BubbleSort(array,5);
	for(int i=0;i<5;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}