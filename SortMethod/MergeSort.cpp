#include <iostream>
using namespace std;

/*�鲢����--��������������ϲ���һ����������*/
void merge(int array[],int tempArray[],int left,int right,int middle)
{
	int index1=left;
	int index2=middle+1;
	for(int i=left;(index1<=middle)&&(index2<=right);i++)
	{
		if(array[index1]<array[index2])
			tempArray[i]=array[index1++];
		else
			tempArray[i]=array[index2++];
	}
	while(index1<=middle)
		tempArray[i++]=array[index1++];
	while(index2<=right)
		tempArray[i++]=array[index2++];
	for(i=left;i<=right;i++)
		array[i]=tempArray[i];  
}

/*��·�鲢����--array[]Ϊ�������飬tempArray[]Ϊ��ʱ���飬left��right�ֱ�����������*/
void mergeSort(int array[],int tempArray[],int left,int right)
{
	if(left<right)
	{
		int middle=(left+right)/2;
        mergeSort(array,tempArray,left,middle);
		mergeSort(array,tempArray,middle+1,right);
		merge(array,tempArray,left,right,middle);
	}
}

int main()
{
	int array[8]={6,8,7,3,1,2,5,4};
	int tempArray[8];
	mergeSort(array,tempArray,0,7);
	for(int i=0;i<8;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}