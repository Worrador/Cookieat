// Cookieat.cpp : Defines the entry point for the application.
//

#include "Cookieat.h"


int main() {
    OpenXLSX::XLDocument doc;
    doc.open("./Resources/Recipes.xlsx");
    auto ws = doc.workbook().worksheet("Recipes");

    auto rng = ws.range(OpenXLSX::XLCellReference("A2"), OpenXLSX::XLCellReference(ws.rowCount(), 2));

    for (auto& cell : rng) {
        nowide::cout << cell.value().get<std::string>() << '\n';
    }

    doc.close();
    return 0;
}