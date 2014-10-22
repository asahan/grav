#ifndef CSHAPE_H
#define CSHAPE_H

class CShape
{
public:
	unsigned int shape;
public:
	CShape();
	~CShape();
	
	virtual void Render()=0;

};

#endif // CSHAPE_H
