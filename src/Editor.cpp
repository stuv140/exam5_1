// Editor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>

#include"GraphicPrimitive.h"
#include "View.h"
#include"Document.h"
#include"Controller.h"
#include"Line.h"
#include"Circle.h"
#include"Rectangles.h"

int main()
{
    Document doc;
    ConsoleView consoleView;
    Controller controller(&doc, &consoleView);
    Point startLine = {10, 10};
    Point endLine= { 100, 100 };
  //  auto line = std::make_unique<Line>(startLine, endLine);
    Point c = { 50,50 };
   // auto circle = std::make_unique<Circle>(c, 30);
    Point left_r = { 120,50 };
    Point right_r = { 150,0 };
   // auto rect = std::make_unique<Rectangles>(left_r, right_r);
  //  doc.addPrimitive(std::move(line));
  //  doc.addPrimitive(std::move(circle));
  //  doc.addPrimitive(std::move(rect));
  //  doc.drawAllPrimitives();
  //  doc.exportToFile("Primitiv.txt");
  //  doc.createNew();
  //  doc.importFromFile("Primitiv.txt");
  //  doc.drawAllPrimitives();
    
    controller.AddPrimitive(std::make_unique<Line>(startLine, endLine));
    controller.AddPrimitive(std::make_unique<Circle>(c, 30));
    controller.AddPrimitive(std::make_unique<Rectangles>(left_r, right_r));
    controller.displayDocument();
    controller.Save("primitives.txt");
    controller.RemovePrimitive(2);
    controller.CreateNew();
    controller.Load("primitives.txt");
    controller.displayDocument();
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
