#include <iostream>
#include <vector>
#include "Vertex.h"
#ifndef BINARYHEAP
#define BINARYHEAP
class BinaryHeap
{
	
		
	private:
	 	int parent(int i); /* return the index of parent of i */
	 	
	 	int left(int i); /*index of left child of i*/
	 
	 	int right(int i); /*index of right child of i*/
	 	
	 	void swap(int i, int j); /*swap 2 elements in the heap, meanwhile modify the vertexIndex*/
	 	
 		void minHeapify (int i);/*i is the node to be heapified, subtree assumed to obey the property*/
 		
 		void decreaseWithIndex(int i, int nDistance);
 	

 	public:
 		vector<Vertex> heap;
		int* vertexIndex; /* this array is aimed to maintained the indices of vertice in the heap, to support key decreasing*/
 		BinaryHeap(int n); /*n is the number of vertices*/
 		
 		void deleteArray(); /* to free memory allocated for the array vertexIndex */
 		
 		bool empty(); 
 		
 		bool contains (Vertex targetVertex); /*test is the target vertex is contained in the heap*/
 		
 		Vertex min(); /*return the minimum, but not deleting the minimum*/
 		
 		Vertex extractMin();/*return and remove the minimum*/
 		
 		void decreaseWithVertex(Vertex targetVertex);
 		
 		void insert (Vertex vertexInsert); /*decreaseWithVertex function is used to ease the implementation*/
 		
};
#endif