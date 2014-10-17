#ifndef MLA_H
#define MLA_H
class MLA{
private:
public:
	MLA(int x1, int y1, int x2, int y2);
	~MLA();
	bool draw(int x, int y, int color);
	void getPos(int x1, int y1, int x2, int y2);
};
#endif