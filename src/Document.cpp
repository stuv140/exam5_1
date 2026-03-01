#include "Document.h"
//#include<memory>
#include<iostream>
#include<fstream>
#include"GraphicPrimitive.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangles.h"

void Document::createNew() {
	primitives.clear();
//	std::cout << "Create New Document" << std::endl;
}
bool Document::importFromFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error open file \"" << filePath << "\"" << std::endl;
        return false;
    }

    // Читаем каждую строку файла
    std::string type;
    while (inputFile >> type) {
        if (type == "LINE") {
            int x1, y1, x2, y2;
            inputFile >> x1 >> y1 >> x2 >> y2;
            auto line = std::make_unique<Line>(Point{ x1, y1 }, Point{ x2, y2 });
            primitives.push_back(std::move(line));
        }
        else if (type == "CIRCLE") {
            int cx, cy, radius;
            inputFile >> cx >> cy >> radius;
            auto circle = std::make_unique<Circle>(Point{ cx, cy }, radius);
            primitives.push_back(std::move(circle));
        }
        else if (type == "RECT") {
            int x1, y1, x2, y2;
            inputFile >> x1 >> y1 >> x2 >> y2;
            auto rect = std::make_unique<Rectangles>(Point{ x1,y1 }, Point{ x2,y2 });
            primitives.push_back(std::move(rect));
        }
        else {
            std::cerr << "no correct type primitives in file: " << type << std::endl;
            return false;
        }
    }
    inputFile.close();
    std::cout << "import file: " << filePath << std::endl;
    return true;
}
bool Document::exportToFile(const std::string& filePath) {

    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error write in file: " << filePath << std::endl;
        return false;
    }

    // Перебираем все примитивы и записываем их в файл
    for (const auto& primitive : primitives) {
        if (auto* line = dynamic_cast<Line*>(primitive.get())) {            
            // Запись линии
            outputFile << "LINE " << line->Get_Begin().x << " " << line->Get_Begin().y << " ";
            outputFile << line->Get_end().x << " " << line->Get_end().y << "\n";
        }
        else if (auto* circle = dynamic_cast<Circle*>(primitive.get())) {
            // Запись круга
           // std::cout << "запись круга в файл :";
            outputFile << "CIRCLE " << circle->GetCenter().x << " " << circle->GetCenter().y << " ";
            outputFile << circle->GetRadius() << "\n";
        } else if (auto* rect = dynamic_cast<Rectangles*>(primitive.get())) {
            // Запись прямоугольника
            outputFile << "RECT " << rect->GetLeftPoint().x << " " << rect->GetLeftPoint().y << " ";
            outputFile << rect->GetRightPoint().x << " " << rect->GetRightPoint().y << "\n";
        }
        else {
            std::cerr << "no correct type primitives in export: " << std::endl;
            return false;
        }
    }

    outputFile.close();
    std::cout << "Save file: " << filePath << std::endl;
    return true;

}

void Document::addPrimitive(std::unique_ptr<GraphicPrimitive>&& primitive)
{
	primitives.push_back(std::move(primitive));
}
void Document::drawAllPrimitives() const
{
	for (auto& p : primitives) {
		p->draw(); // Полиморфный вызов метода draw()
	}
}

void Document::clearPrimitives()
{
	primitives.clear();
}

void Document::removePrimitiveAt(size_t index) {
	if (index >= primitives.size()) {
		throw std::out_of_range("Индекс за пределами доступных примитивов.");
	}
	primitives.erase(primitives.begin() + index);

}
