﻿// Cookieat.cpp : Defines the entry point for the application.
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

    while (1) {
        // Get random row number
        std::uniform_int<> real_dist(2, rowCount);
        auto random_row_number = real_dist(randomNumberGenerator);

        // Check recency sheet and generate acceptance based on it
        auto recency_value = ws_recency.cell(random_row_number, 1).value().get<int>();
        std::uniform_int<> real_dist2(1, 100);

        if (recency_value < real_dist2(randomNumberGenerator)) {
            auto pocs = ws_recipes.cell(random_row_number, 1).value().get<std::string>();
            nowide::cout << pocs << std::endl;
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

    // Close the document.
    doc.close();
    // Return 0 to indicate successful execution of the program.
    return 0;
}