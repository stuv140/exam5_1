#pragma once
#include"GraphicPrimitive.h"
class Rectangles : public GraphicPrimitive
{
public:
	Rectangles(Point left_up, Point right_Down): left_up_angle(left_up), right_Down_angle(right_Down) {}
	void draw()const override;
	Point GetLeftPoint()const { return left_up_angle; }
	Point GetRightPoint() const { return right_Down_angle; }
    virtual ~Rectangles() {};
private:
	Point left_up_angle;
	Point right_Down_angle;
};
