#define BOOST_TEST_MODULE EditTest
#include <boost/test/included/unit_test.hpp>
#include<memory>
#include"Document.h"
#include"Line.h"
BOOST_AUTO_TEST_SUITE(DocumentTest)

    BOOST_AUTO_TEST_CASE(TestAddAndRemovePrimitve) {
        Document doc; 
      //  Point startLine = { 10, 10 };
      //  Point endLine = { 100, 100 };
        auto line = std::make_unique<Line>(); 

        // Проверка добавления примитивов
        doc.addPrimitive(std::move(line));
        BOOST_CHECK_EQUAL(doc.getPrimitivesCount(), 1); // Проверяем количество элементов

        // Удаление элемента по индексу
        doc.removePrimitiveAt(0);
        BOOST_CHECK_EQUAL(doc.getPrimitivesCount(), 0); // Элементов больше нет
    }
BOOST_AUTO_TEST_SUITE_END()
