#include <iostream>
using namespace std;

/*���������������ǽ��������е�����Ԫ�ص�λ��*/
void swap(int array[],int i,int j)
{
	int tmp=array[i];
	array[i]=array[j];
	array[j]=tmp;
}

/*��������*/
void InsertSort(int array[],int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(array[j]>array[j-1])
				swap(array,j,j-1);
			else
			    break;
		}
	}
}

int main()
{
	int array[5]={3,1,2,5,4};
	InsertSort(array,5);
	for(int i=0;i<5;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}