#include <QApplication>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QWheelEvent>
#include "entity/Box.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	MyGLWidget()
	{
		m_mesh = Box::create(1);
	}
protected:
	struct Vertex
	{
		float x, y, z;
	};

	struct Face
	{
		int v1, v2, v3, v4; // 顶点索引
	};

	std::vector<Vertex> vertices =
	{
		{-0.5, -0.5,  0.5},
		{ 0.5, -0.5,  0.5},
		{ 0.5,  0.5,  0.5},
		{-0.5,  0.5,  0.5},

		{-0.5, -0.5, -0.5},
		{ 0.5, -0.5, -0.5},
		{ 0.5,  0.5, -0.5},
		{-0.5,  0.5, -0.5}
	};

	std::vector<Face> faces =
	{
		{0,1,2,3}, // 前
		{4,5,6,7}, // 后
		{0,3,7,4}, // 左
		{1,2,6,5}, // 右
		{3,2,6,7}, // 上
		{0,1,5,4}  // 下
	};

	void initializeGL() override
	{
		initializeOpenGLFunctions();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		glEnable(GL_DEPTH_TEST);
	}

	void paintGL() override
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1, 1, -1, 1, -10, 10);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glTranslatef(0.0f, 0.0f, m_distance);

		glRotatef(m_angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(m_angleY, 0.0f, 1.0f, 0.0f);

		m_mesh.draw();
	}

	void mousePressEvent(QMouseEvent* event) override
	{
		m_lastPos = event->pos();
	}

	void mouseMoveEvent(QMouseEvent* event) override
	{
		int dx = event->x() - m_lastPos.x();
		int dy = event->y() - m_lastPos.y();

		if (event->buttons() & Qt::LeftButton)
		{
			m_angleX += dy;
			m_angleY += dx;
		}

		m_lastPos = event->pos();
		update(); // 触发重绘
	}

	void wheelEvent(QWheelEvent* event) override
	{
		if (event->angleDelta().y() > 0)
			m_distance += 0.2f;
		else
			m_distance -= 0.2f;

		update();
	}

private:
	float m_angleX = 0.0f;
	float m_angleY = 0.0f;
	float m_distance = -3.0f;

	QPoint m_lastPos;
	Mesh m_mesh;
};

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	MyGLWidget window;
	window.resize(800, 600);
	window.setWindowTitle("MiniCAD");

	window.show();

	return app.exec();
}