#include "View.h"
#include<string>
#include<iostream>
//#include"Document.h"

void ConsoleView::showMessage(const std::string& msg)  {
    std::cout << msg << "\n";
}
void ConsoleView::displayDocument(const Document& doc)  {
    std::cout << "The document contains  " << doc.getPrimitivesCount() << " primitivs.\n";
    doc.drawAllPrimitives();

}
