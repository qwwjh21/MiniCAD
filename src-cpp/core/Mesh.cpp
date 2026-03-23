#include "Mesh.h"
#include <QOpenGLFunctions>

void Mesh::draw() const
{
	glBegin(GL_QUADS);

	for (size_t i = 0; i < faces.size(); ++i)
	{
		const Face& f = faces[i];

		glColor3f((i & 1), (i & 2) >> 1, (i & 4) >> 2);

		const Vertex& v1 = vertices[f.v1];
		const Vertex& v2 = vertices[f.v2];
		const Vertex& v3 = vertices[f.v3];
		const Vertex& v4 = vertices[f.v4];

		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
		glVertex3f(v4.x, v4.y, v4.z);
	}

	glEnd();
}