#include <iostream>
#include <vector>
#include <limits>

const int INFINITY = std::numeric_limits<int>::max(); /*approximation for positive infinity*/
/* this is intended for implememtation of priority queue supproting a log(n) time of operations including 
extract min, decrease key for Dijkstra algorithm*/
/* this priority queue is build specifically for implementation of Dijkstra algorithm*/
/*for even fatser implementation, a fibonacci heap is an option*/
using namespace std;

class Vertex
{
	public:
		int vertex;
		int distance;
		Vertex(int nVertex, int nDistance)
		{
			vertex=nVertex;
			distance=nDistance;
		}
};

class BinaryHeap
{
	vector<Vertex> heap;
	int* vertexIndex; /* this array is aimed to maintained the indices of vertice in the heap, to support key decreasing*/
	private:
	 	int parent(int i) /* return the index of parent of i */
	 	{
	 		return i/2;
	 	}
	 	int left(int i) /*index of left child of i*/
	 	{
	 		return 2*i;
	 	}
	 	int right(int i) /*index of right child of i*/
	 	{
	 		return 2*i+1;
	 	}
	 	void swap(int i, int j) /*swap 2 elements in the heap, meanwhile modify the vertexIndex*/
	 	{
	 		/*modify vertexIndex first*/
	 		vertexIndex[heap[i].vertex]=j;
	 		vertexIndex[heap[j].vertex]=i;
	 		/*swap the elemnts*/
	 		Vertex temp=heap[i];
	 		heap[i]=heap[j];
	 		heap[j]=temp;
	 	}
 		void minHeapify (int i)/*i is the node to be heapified, subtree assumed to obey the property*/
 		{
 			int l=left(i);
 			int r=right(i);
 			int smallest=i;
 			if(l<heap.size() && heap[l].distance<heap[smallest].distance)
 			{
 				smallest=l;
 			}
 			if(r<heap.size() && heap[r].distance<heap[smallest].distance)
 			{
 				smallest=r;
 			}
 			if(smallest!=i)
 			{
 				swap(i, smallest);
 				minHeapify(smallest);
 			}
 		}
 		void decreaseWithIndex(int i, int nDistance)
 		{
 			if(nDistance < heap[i].distance)
 			{
 				heap[i].distance=nDistance;
 				while(i>0  && heap[parent(i)].distance > heap[i].distance) /*maintain the heap property*/
 				{
 					swap(i, parent(i));
 					i=parent(i);
 				}
 			}
 		}

 	public:
 		BinaryHeap(int n) /*n is the number of vertices*/
 		{
 			vertexIndex = new int[n];
 			for(int i =0; i<n; ++i)
 			{
 				vertexIndex[i]=-1; /*all indices are set to be -1*/
 			}
 		}
 		void deleteArray() /* to free memory allocated for the array vertexIndex */
 		{
 			delete[] vertexIndex;
 		}
 		bool empty() 
 		{
 			return heap.size()==0;
 		}
 		bool contains (Vertex targetVertex) /*test is the target vertex is contained in the heap*/
 		{
 			return vertexIndex[targetVertex.vertex]!=-1;/* when it is -1, then it is not contained in the heap*/
 		}
 		Vertex min() /*return the minimum, but not deleting the minimum*/
 		{
 			return heap[0];
 		}
 		Vertex extractMin()/*return and remove the minimum*/
 		{
 			Vertex min=heap[0];
 			swap(0, heap.size()-1); /*swap the first and the last element in the heap*/
 			vertexIndex[heap[heap.size()-1].vertex]=-1;/*the minimum is removed form the heap, then its index is -1 to avoid potential conflicts*/
 			heap.pop_back(); /*minimum is now poped out of the heap */
 			minHeapify(0); /*to ensure the heap property*/
 			return min;
 		}
 		void decreaseWithVertex(Vertex targetVertex)
 		{
 			decreaseWithIndex(vertexIndex[targetVertex.vertex], targetVertex.distance);
 		}
 		void insert (Vertex vertexInsert) /*decreaseWithVertex function is used to ease the implementation*/
 		{
 			Vertex infinityVertex(vertexInsert.vertex, INFINITY);
 			heap.push_back(infinityVertex);
 			vertexIndex[vertexInsert.vertex]=heap.size()-1;
 			decreaseWithVertex(vertexInsert);
 		}
};

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