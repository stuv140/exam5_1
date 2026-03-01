#pragma once
#include<string>
#include<vector>
#include<memory>
#include"GraphicPrimitive.h"
//#include "Line.h"
//#include "Circle.h"
//#include "Rectangles.h"
class Document {
public:
    void createNew();
    bool importFromFile(const std::string& filePath);
    bool exportToFile(const std::string& filePath);
    void addPrimitive(std::unique_ptr<GraphicPrimitive>&& primitive);
    void drawAllPrimitives() const;
    void clearPrimitives();
    size_t getPrimitivesCount() const {
        return primitives.size();
    }
    void removePrimitiveAt(size_t index);
   
private:
    std::vector<std::unique_ptr<GraphicPrimitive>> primitives;
};
