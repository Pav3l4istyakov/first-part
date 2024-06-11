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

    std::cout << "������� ��� ��������: ";
    std::cin >> productName;
    file << "���: " << productName << std::endl;

    std::cout << "������� ��-��: ";
    std::cin >> quantity;
    file << "���-��: " << quantity << std::endl;

    std::cout << "������� ����: ";
    std::cin >> price;
    file << "����: " << price << std::endl;

    file.close();
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    std::string filename;

    do {
        std::cout << "�������� ���� ��� ������ ������:" << std::endl;
        std::cout << "1. ���������� � �������� " << std::endl;
        std::cout << "2. ���������� � �������� " << std::endl;
        std::cout << "3. ���������� � ��������" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << "������� ��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            filename = "���������� � ��������1.txt";
            break;
        case 2:
            filename = "���������� � ��������2.txt";
            break;
        case 3:
            filename = "���������� � ��������3.txt";
            break;
        case 0:
            std::cout << "�����" << std::endl;
            break;
        default:
            std::cout << "�������� �����.���������� ��� ���" << std::endl;
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