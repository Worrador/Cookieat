// Cookieat.cpp : Defines the entry point for the application.
//

#include "Cookieat.h"


int main() {
    // Create an XLDocument object and open an existing Excel file named "Recipes.xlsx" located in the "./Resources" directory.
    OpenXLSX::XLDocument doc;
    doc.open("./Resources/Recipes.xlsx");

    // Access the worksheet named "Recipes" in the workbook.
    auto ws = doc.workbook().worksheet("Recipes");

    // Define a range from the upper left corner to the cell in the lower right corner.
    // The range starts from cell A2 (row 2, column 1) and extends to the second column of the last row.
    // As we have the useful data in this range only.
    auto rng = ws.range(OpenXLSX::XLCellReference("A2"), OpenXLSX::XLCellReference(ws.rowCount(), 2));

    // Iterate through each cell in the range and output its value as a string using the 'get<std::string>()' method of the XLCellValue class.
    for (auto& cell : rng) {
        nowide::cout << cell.value().get<std::string>() << '\n';
    }

    // Close the document.
    doc.close();

    // Return 0 to indicate successful execution of the program.
    return 0;
}