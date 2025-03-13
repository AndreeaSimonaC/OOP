#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height) {
	n = width;
	m = height;
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	//x y centru
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//dx distanta pe oriz pana la centru si oy pe verticala
			int dx = i - x;
			int dy = j - y;
			//th pitagora, calculam distanta de la centru la pct (i,j)
			double distance = sqrt(dx * dx + dy * dy);
			if (abs(distance - ray) < 0.5) {
				a[j][i] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int dx = i - x;
			int dy = j - y;
			double distance = sqrt(dx * dx + dy * dy);
			//daca distanta <= raza : populeaza matricea cu 'ch'
			if (distance <= ray) {
				a[j][i] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; ++i) {
		a[top][i] = ch;
		a[bottom][i] = ch;
	}
	for (int j = top; j <= bottom; ++j) {
		a[j][left] = ch;
		a[j][right] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; ++i) {
		for (int j = left; j <= right; ++j) {
			a[i][j] = ch;
		}
	}
}
void Canvas::SetPoint(int x, int y, char ch) {
	if (x < 0 || x > n || y < 0 || y > m) {
		return;
	}
	a[y][x] = 'ch';

}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}
void Canvas::Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 0) {
				cout << a[i][j] << " ";
			}
			else cout << 'X' << " ";
		}
		cout << '\n';
	}
}
void Canvas::Clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
}