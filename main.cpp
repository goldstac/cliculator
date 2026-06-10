#include <iostream>
#include <limits>
#include <cmath>

#ifdef _WIN32
    #include <windows.h>
#endif

// Function to clear the terminal screen based on the OS
void clearScreen() {
#ifdef _WIN32
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacter(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, screen.wAttributes, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
#else
    std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes for POSIX
#endif
}

// Function to safely get double inputs
double getNumber(const std::string& prompt) {
    double num;
    while (true) {
        std::cout << prompt;
        if (std::cin >> num) {
            return num;
        }
        std::cout << " Invalid input. Please enter a valid number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Function to draw the TUI Header
void drawHeader() {
    std::cout << "====================================\n";
    std::cout << "        C++ TUI CALCULATOR        \n";
    std::cout << "====================================\n";
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        clearScreen();
        drawHeader();
        
        std::cout << "  [1] Addition (+)\n";
        std::cout << "  [2] Subtraction (-)\n";
        std::cout << "  [3] Multiplication (*)\n";
        std::cout << "  [4] Division (/)\n";
        std::cout << "  [5] Exit\n";
        std::cout << "------------------------------------\n";
        std::cout << "Enter your choice (1-5): ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Invalid menu choice, redraw
        }

        if (choice == 5) {
            running = false;
            std::cout << "\nGoodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cout << "\n Invalid option. Press Enter to try again...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            continue;
        }

        std::cout << "\n";
        double num1 = getNumber("Enter first number: ");
        double num2 = getNumber("Enter second number: ");
        std::cout << "------------------------------------\n";

        switch (choice) {
            case 1:
                std::cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
                break;
            case 2:
                std::cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
                break;
            case 3:
                std::cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
                break;
            case 4:
                if (num2 == 0) {
                    std::cout << " Error: Division by zero is undefined.\n";
                } else {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
                }
                break;
        }

        std::cout << "------------------------------------\n";
        std::cout << "Press Enter to return to the menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get(); // Wait for user to read result
    }

    return 0;
}
