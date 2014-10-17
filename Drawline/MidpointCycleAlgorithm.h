#ifndef MCA_H
#define MCA_H
class MCA{
private:

public:
	MCA(int x, int y, int r);
	~MCA();
	bool draw(int x, int y, int color);
	bool drawFourPiont(int x, int y, int color);
	void getPos(int x, int y, int r);
};
#endif