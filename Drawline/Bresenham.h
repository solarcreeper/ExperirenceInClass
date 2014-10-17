#ifndef BRESENHAM_H
#define BRESENHAM_H
class Bresenham{
private:
public:
	Bresenham(int x1, int y1, int x2, int y2);
	~Bresenham();
	bool draw(int x, int y, int color);
	void getPos(int x1, int y1, int x2, int y2);

};
#endif