#include <iostream>
using namespace std;

/*最大堆定义*/
class MaxHeap
{
private:
	int size; //最大堆的元素数目
    int * array;  //最大堆数组的首地址指针
public:
	MaxHeap(int array[],int n); //用已有数组初始化一个最大堆 
         void buildHeap();   //构建最大堆
	void siftDown(int index);  //向下筛选法
	void swap(int index1,int index2);  //交换位置为index1与index2的元素
	void removeMax();  //删除堆顶的最大值--与数组最后一个元素交换位置并重新构建最大堆
	int leftChild(int index);  //返回左孩子的位置
	int rightChild(int index);  //返回右孩子的位置
};
/*最大堆排序函数*/

/*最大堆成员函数实现*/
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

	/*删除堆的最大值（堆顶），即每次将最大值与数组的最后一个元素交换位置*/
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
