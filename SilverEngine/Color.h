#ifndef COLOR_H
#define COLOR_H

class RGBAColor
{
public:
	RGBAColor();
	RGBAColor( float red, float green, float blue, float alpha );
	virtual ~RGBAColor();

	float r, g, b, a;
private:

};

#endif // !COLOR_H
