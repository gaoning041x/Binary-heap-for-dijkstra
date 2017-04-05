#include "Vertex.h"
bool operator < (const Vertex & v1, const Vertex & v2)
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
bool operator >(const Vertex & v1, const Vertex & v2)
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