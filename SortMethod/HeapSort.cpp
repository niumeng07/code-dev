#include <iostream>
using namespace std;

/*���Ѷ���*/
class MaxHeap
{
private:
	int size; //���ѵ�Ԫ����Ŀ
    int * array;  //����������׵�ַָ��
public:
	MaxHeap(int array[],int n); //�����������ʼ��һ������ 
         void buildHeap();   //��������
	void siftDown(int index);  //����ɸѡ��
	void swap(int index1,int index2);  //����λ��Ϊindex1��index2��Ԫ��
	void removeMax();  //ɾ���Ѷ������ֵ--���������һ��Ԫ�ؽ���λ�ò����¹�������
	int leftChild(int index);  //�������ӵ�λ��
	int rightChild(int index);  //�����Һ��ӵ�λ��
};
/*����������*/

/*���ѳ�Ա����ʵ��*/
MaxHeap::MaxHeap(int array[],int n)
{
	this->array=array;
	size=n;
	buildHeap();
}

void MaxHeap::buildHeap()
{
	for(int i=size/2-1;i>=0;i--)
		siftDown(i);
}

void MaxHeap::siftDown(int index)
{
	int max_index=leftChild(index);
	while(max_index<size)
	{
		if(max_index<size-1&&array[rightChild(index)]>array[max_index])
			max_index++;
		if(array[index]>array[max_index])
			break;
		swap(index,max_index);
		index=max_index;
		max_index=leftChild(index);
	}
}

void MaxHeap::swap(int index1,int index2)
{
	int temp=array[index1];
	array[index1]=array[index2];
	array[index2]=temp;
}

void MaxHeap::removeMax()
{
	swap(0,size-1);
	size--;
	siftDown(0);
}

int MaxHeap::leftChild(int index)
{
	return index*2+1;
}

int MaxHeap::rightChild(int index)
{
	return index*2+2;
}
void heapSort(int array[],int n)
{
	MaxHeap max_heap=MaxHeap(array,n);

	/*ɾ���ѵ����ֵ���Ѷ�������ÿ�ν����ֵ����������һ��Ԫ�ؽ���λ��*/
	for(int i=0;i<7;i++)
		max_heap.removeMax();
}

int main()
{
	int array[8]={4,3,7,1,2,8,5,6};
	heapSort(array,8);
	for(int i=0;i<8;i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	return 0;
}
