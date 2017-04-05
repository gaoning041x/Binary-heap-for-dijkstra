#include "Vertex.h"
const extern int INFINITY;
Vertex::Vertex(int v, int dist)
{
	vertex=v;
	distance=dist;
}
bool operator < (const Vertex & v1, const Vertex & v2)
{
	if(v1.distance==INFINITY && v2.distance >=0)
	{
		return false;
	}
	else if (v1.distance==INFINITY && v2.distance==INFINITY)
	{
		return v1.vertex<v2.vertex;
	}
	else if (v1.distance>=0 && v2.distance==INFINITY)
	{
		return true;
	}
	else
	{
		if(v1.distance<v2.distance)
		{
			return true;
		}
		else if (v1.distance> v2.distance)
		{
			return false;
		}
		else
		{
			return v1.vertex<v2.vertex;
		}
	}
}
bool operator >(const Vertex & v1, const Vertex & v2)
{
	if(v1.distance==INFINITY && v2.distance >=0)
	{
		return true;
	}
	else if (v1.distance==INFINITY && v2.distance==INFINITY)
	{
		return v1.vertex>v2.vertex;
	}
	else if (v1.distance>=0 && v2.distance==INFINITY)
	{
		return false;
	}
	else
	{
		if(v1.distance>v2.distance)
		{
			return true;
		}
		else if (v1.distance< v2.distance)
		{
			return false;
		}
		else
		{
			return v1.vertex>v2.vertex;
		}
	}
}