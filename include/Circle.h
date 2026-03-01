#pragma once


#include "GraphicPrimitive.h"

class Circle: public GraphicPrimitive
{
private:
    Point center_;
    int radius_;

public:
    Circle(Point center, int radius) : center_(center), radius_(radius) {}
    
    void draw() const override;
    Point GetCenter()const { return center_; }
    int GetRadius()const { return radius_; }
    virtual ~Circle() {};
};
