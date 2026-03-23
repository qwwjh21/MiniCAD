#pragma once
#include <vector>

struct Vertex
{
	float x, y, z;
};

struct Face
{
	int v1, v2, v3, v4;
};

class Mesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<Face> faces;

	void draw() const;
};