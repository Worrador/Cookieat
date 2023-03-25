// Cookieat.cpp : Defines the entry point for the application.
//

#include "Cookieat.h"


int main() {
    // Create an XLDocument object and open an existing Excel file named "Recipes.xlsx" located in the "./Resources" directory.
    OpenXLSX::XLDocument doc;
    doc.open("./Resources/Recipes.xlsx");

    // Access the worksheet named "Recipes" in the workbook.
    auto ws_recipes = doc.workbook().worksheet("Recipes");
    auto ws_recency = doc.workbook().worksheet("Recency");

    auto rowCount = ws_recipes.rowCount();

    // Define a range from the upper left corner to the cell in the lower right corner.
    auto rng = ws_recipes.range(OpenXLSX::XLCellReference("A2"), OpenXLSX::XLCellReference(rowCount, 1));

    // Iterate through each cell in the range and output its value as a string using the 'get<std::string>()' method of the XLCellValue class.
    for (auto& cell : rng) {
        nowide::cout << cell.value().get<std::string>() << '\n';
    }

    // Close the document.
    doc.close();

    while (1) {
        // Get random row number
        std::uniform_int<> real_dist(1, rowCount);
        auto random_number = real_dist(randomNumberGenerator);

        // Check recency sheet and generate acceptance based on it
        auto& recency_value = ws_recency.cell(1, random_number).value();
        std::uniform_int<> real_dist2(1, 100);

        if (recency_value < real_dist2(randomNumberGenerator)) {
            nowide::cout << ws_recipes.cell(1, random_number).value().get<std::string>() << '\n';

            std::cout << "Do you want to eat this? (Y/N)" << std::endl;
            auto myChar = 'A';
            while (myChar != 'Y' && myChar != 'N') {
                myChar = _getch();
            }
            if (myChar == 'Y') {
                break;
            }
            else {
                continue;
            }
        }


    }


    // Return 0 to indicate successful execution of the program.
    return 0;
}