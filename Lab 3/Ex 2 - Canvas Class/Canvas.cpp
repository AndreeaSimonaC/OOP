#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height) {
	n = width;
	m = height;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {

}
void Canvas::FillCircle(int x, int y, int ray, char ch) {

}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {

}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {

}
void Canvas::SetPoint(int x, int y, char ch) {
	if (x < 0 || x > n || y < 0 || y > m) {
		return;
	}
	a[y][x] = 'ch';

}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

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