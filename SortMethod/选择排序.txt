#include <iostream>
using namespace std;

/*交换函数，作用是交换数组中的两个元素的位置*/
void swap(int array[],int i,int j)
{
	int tmp=array[i];
	array[i]=array[j];
	array[j]=tmp;
}

/*选择排序*/
void SelectionSort(int array[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int smallest=i;
		for(int j=i+1;j<n;j++)
		{
			if(array[smallest]>array[j])
				smallest=j;
		}
		swap(array,i,smallest);
	}
}

int main()
{
	int array[5]={3,1,2,5,4};
	SelectionSort(array,5);
	for(int i=0;i<5;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}