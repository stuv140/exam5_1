#include "Circle.h"
#include <iostream> 

void Circle::draw() const {
	std::cout << "Draw circle with centre (" << center_.x << "," << center_.y << ") radius = " << radius_<<std::endl;

}
