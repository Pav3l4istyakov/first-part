#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    std::string productName;
    int quantity;
    double price;

    std::cout << "Введите имя продукта: ";
    std::cin >> productName;
    file << "имя: " << productName << std::endl;

    std::cout << "Введите ко-во: ";
    std::cin >> quantity;
    file << "кол-во: " << quantity << std::endl;

    std::cout << "Введите цену: ";
    std::cin >> price;
    file << "цена: " << price << std::endl;

    file.close();
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    std::string filename;

    do {
        std::cout << "Выберите файл для записи данных:" << std::endl;
        std::cout << "1. информация о продукте " << std::endl;
        std::cout << "2. информация о продукте " << std::endl;
        std::cout << "3. информация о продукте" << std::endl;
        std::cout << "0. выход" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            filename = "информация о продукте1.txt";
            break;
        case 2:
            filename = "информация о продукте2.txt";
            break;
        case 3:
            filename = "информация о продукте3.txt";
            break;
        case 0:
            std::cout << "выход" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор.Попробуйте ещё раз" << std::endl;
            continue;
        }

        std::ifstream checkFile(filename);
        if (checkFile.good()) {
            char overwriteChoice;
            std::cout << "File already contains data. Do you want to overwrite it? (y/n): ";
            std::cin >> overwriteChoice;
            if (overwriteChoice == 'y' || overwriteChoice == 'Y') {
                std::ofstream clearFile(filename, std::ios::trunc);
                clearFile.close();
                writeToFile(filename);
            }
            else {
                writeToFile(filename);
            }
        }
        else {
            writeToFile(filename);
        }

    } while (choice != 0);

    return 0;
}