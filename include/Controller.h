#pragma once
#include "View.h"
#include "Document.h"
#include "GraphicPrimitive.h"

class Controller
{
public:
	Controller(Document* _doc, View* _view);
    void CreateNew();
    void Load(const std::string& filename);    
    void Save(const std::string& filename);
    void AddPrimitive(std::unique_ptr<GraphicPrimitive>&& primitive);
    void RemovePrimitive(size_t index);
    void displayDocument() {
        view->displayDocument(*doc);
    }
private:
    void updateView() {
        view->displayDocument(*doc);
    }
    Document* doc;
    View* view;
};
