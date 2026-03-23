#include "Box.h"

Mesh Box::create(float size)
{
	float s = size / 2.0f;

	Mesh mesh;

	mesh.vertices =
	{
		{-s,-s, s}, { s,-s, s}, { s, s, s}, {-s, s, s},
		{-s,-s,-s}, { s,-s,-s}, { s, s,-s}, {-s, s,-s}
	};

	mesh.faces =
	{
		{0,1,2,3},
		{4,5,6,7},
		{0,3,7,4},
		{1,2,6,5},
		{3,2,6,7},
		{0,1,5,4}
	};

	return mesh;
}