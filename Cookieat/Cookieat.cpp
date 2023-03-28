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


    while (1) {
        // Get random row number
        std::uniform_int<> real_dist(2, rowCount);
        auto random_row_number = real_dist(randomNumberGenerator);

        // Check recency sheet and generate acceptance based on it
        int recency_value = 0; // Set default value to zero
        try {
            recency_value = ws_recency.cell(random_row_number, 1).value().get<int>();
        }
        catch (const OpenXLSX::XLValueTypeError&) {
            // Cell does not contain a valid value, set to default value
        }

        std::uniform_int<> real_dist2(1, 100);

        if (recency_value < real_dist2(randomNumberGenerator)) {
            auto recipe_name = ws_recipes.cell(random_row_number, 1).value().get<std::string>();
            std::cout << "\033c";
            std::cout << "Do you want to eat this? (Y/N)" << std::endl << "  \xC4\x10 ";
            nowide::cout << recipe_name << std::endl;
            auto myChar = 'A';
            while (myChar != 'Y' && myChar != 'N') {
                myChar = _getch();
            }
            if (myChar == 'Y') {
                // Update recency
                ws_recency.cell(random_row_number, 1).value().set(105);

                // Open corresponding url
                auto url = ws_recipes.cell(random_row_number, 2).value().get<std::string>();
                ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
                break;
            }
            else {
                continue;
            }
        }


    }
    // Update recencies
    auto rng_recency = ws_recency.range(OpenXLSX::XLCellReference("A2"), OpenXLSX::XLCellReference(rowCount, 1));
    for (auto& cell : rng_recency) {
        try {
            cell.value().set(max(cell.value().get<int>() - 5, 0));
        }
        catch (const OpenXLSX::XLValueTypeError&) {
            // Cell does not contain a valid value, set to default value
            cell.value().set(0);
        }
    }

    // Save and close the document.
    doc.save();
    doc.close();

    // Return 0 to indicate successful execution of the program.
    return 0;
}