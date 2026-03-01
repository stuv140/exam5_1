#include<iostream>
#include "Controller.h"
//#include "GraphicPrimitive.h"
//#include "View.h"
//#include "Document.h"
//#include<iostream>

Controller::Controller(Document* _d, View* _v): doc(_d), view(_v)
{

}
void Controller::CreateNew()
{
	doc->clearPrimitives();
	doc->createNew();
	view->showMessage("Create New Document!");
	updateView();
	//std::cout << "Create New document" << std::endl;
}
void Controller::Load(const std::string& filename) {
	if (!doc->importFromFile(filename)) {
		std::cerr << "Error load in file:'" << filename << "'." << std::endl;
		return;
	}
}
void Controller::Save(const std::string& filename) {
	if (!doc->exportToFile(filename)) {
		std::cerr << "Error save in file '" << filename << "'." << std::endl;
		return;
	}
	std::cout << "The Document save in file: " << filename << "." << std::endl;
}
//void Controller::createPrimitive() {
//	auto line = new Line(10, 10, 100, 100); // Создаем линию от точки (10,10) до (100,100)
//	doc.addPrimitive(line);                 // Добавляем примитив в документ
//	std::cout << "Графический примитив создан." << std::endl;
//}
void Controller::AddPrimitive(std::unique_ptr<GraphicPrimitive>&& primitive) {
	doc->addPrimitive(std::move(primitive));
	view->showMessage("Add primitiv:");
	updateView();
}

void Controller::RemovePrimitive(size_t index) {	

	doc->removePrimitiveAt(index);
	std::string str{ "Delete Pimitiv[" + std::to_string(index)+"]" };
	view->showMessage(str);
	updateView();
}
