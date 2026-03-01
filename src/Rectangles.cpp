
#include<memory>
#include <iostream>
#include "Rectangles.h"
#include "Line.h"
#include "Document.h"


void Rectangles::draw()const {
	Document doc;
	std::cout << "Draw rectangle point1 (" << left_up_angle.x << "," << left_up_angle.y << ")\n";	
	
	std::cout << "Draw rectangle point2 (" << left_up_angle.x << "," << right_Down_angle.y << ")\n";

	std::cout << "Draw rectangle point3 (" << right_Down_angle.x << "," << right_Down_angle.y << ")\n";

	std::cout << "Draw rectangle point4 (" << right_Down_angle.x << "," << left_up_angle.y << ")\n";
	Point startLine = { left_up_angle.x, left_up_angle.y };
	Point endLine = { left_up_angle.x, right_Down_angle.y };
	auto line = std::make_unique<Line>(startLine, endLine);
	doc.addPrimitive(std::move(line));

	Point startLine2 = { left_up_angle.x, right_Down_angle.y };
	Point endLine2 = { right_Down_angle.x, right_Down_angle.y };
	auto line2 = std::make_unique<Line>(startLine2, endLine2);
	doc.addPrimitive(std::move(line2));

	Point startLine3 = { right_Down_angle.x, right_Down_angle.y };
	Point endLine3 = { left_up_angle.x, right_Down_angle.y };
	auto line3 = std::make_unique<Line>(startLine3, endLine3);
	doc.addPrimitive(std::move(line3));

	Point startLine4 = { left_up_angle.x, right_Down_angle.y };
	Point endLine4 = { left_up_angle.x, left_up_angle.y };
	auto line4 = std::make_unique<Line>(startLine4, endLine4);
	doc.addPrimitive(std::move(line4));

	doc.drawAllPrimitives();
	doc.clearPrimitives();
}
