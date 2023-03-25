// Cookieat.cpp : Defines the entry point for the application.
//

#include "Cookieat.h"

int main()
{
	std::cout << "Hello CMake." << std::endl;
    OpenXLSX::XLDocument doc;
    doc.create("Spreadsheet.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");

    wks.cell("A1").value() = "Hello, OpenXLSX!";

    doc.save();

    return 0;
}
