#pragma once
struct Point {
    int x, y;
};
class GraphicPrimitive {
public:
    virtual ~GraphicPrimitive() = default;
    virtual void draw() const = 0;  
};
