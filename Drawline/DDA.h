
#ifndef DDA_H
#define DDA_H
class DDA{
private:

public:
	DDA(int x1, int y1, int x2, int y2);
	~DDA();
	bool draw(int x, int y, int color);
	void getPos(int x1, int y1, int x2, int y2);
};
#endif