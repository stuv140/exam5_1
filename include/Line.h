#pragma once
#include"GraphicPrimitive.h"

class Line: public GraphicPrimitive
{
private:
	Point begin;
	Point end;
public:
	void draw()const override;
	Line(Point one, Point two):begin(one),end(two){}
    Line() : begin({}), end({}) {} 
	Point Get_Begin() const  { return begin; }
	Point Get_end()const  { return end; }
   virtual ~Line() override =default;

};
