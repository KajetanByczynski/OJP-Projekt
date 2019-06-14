#include "Fraktal.h"

using namespace std;

struct Point {
	GLfloat x, y;
	Point(GLfloat x = 0, GLfloat y = 0) : x(x), y(y) {}
	Point midpoint(Point p) { return Point((x + p.x) / 2.0, (y + p.y) / 2.0); }
};

void Viewer::draw() {
	const float nbSteps = 20.0;

	static Point vertices[] = { Point(200, 500), Point(500, 0), Point(0, 0) };
	static Point p = vertices[0];
	glBegin(GL_POINTS);
	for (int k = 0; k < 100000; k++) {
		p = p.midpoint(vertices[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	glEnd();
}

void Viewer::init() {
	restoreStateFromFile();
	help();
}