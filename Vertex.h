#include <iostream>
#ifndef VERTEX
#define VERTEX
const int INFINITY = -1;/*approximation for positive infinity*/
using namespace std;
class Vertex
{
	public:
		int vertex;
		int distance;
		Vertex(int v, int dist);
};
bool operator <(const Vertex & v1, const Vertex & v2);
bool operator >(const Vertex & v1, const Vertex & v2);
#endif