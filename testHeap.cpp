#include <iostream>
#include "binaryHeap.h"
using namespace std;
int main ()
{
	BinaryHeap binaryheap(10);
	for (int i=9; i>=0; --i)
	{
		Vertex vertex(i, i);
		binaryheap.insert(vertex);
	}
	for(int i=0; i<10; ++i)
	{
		Vertex vertex(i, i-1);
		binaryheap.decreaseWithVertex(vertex);
	}
	for(int i=0; i<10; ++i)
	{
		Vertex minV =binaryheap.extractMin();
		cout<<"the minimum is vertex: "<<minV.vertex<<"with distance: "<<minV.distance<<"\n";
	}
	return 0;
}