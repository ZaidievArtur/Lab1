#include "Program.h"

void Program::readFile() {
    std::wifstream file(fileName);

    if (!file.is_open()) {
        printf("Error opening file");
        exit(1);
    }

    std::wstring firstName, secondName, middleName;

    while (file >> secondName >> firstName >> middleName) {
        list.add(Human(secondName, firstName, middleName));
    }

    file.close();

    if (list.getLength() == 0) {
        printf("File is empty.");
        exit(2);
    }
}

void Program::print() {
    int length = 0;
    Human * data = list.get(&length);

    for (int index = 0; index < length; index++) {
        Human node = data[index];
        std::wcout << index + 1 << ". " << node.secondName << ' ' << node.firstName << ' ' << node.middleName
                   << '\n';
    }
}

void Program::filter() {
    int length = 0;
    Human *data = list.get(&length);

    std::wstring fSecondName, fFirstName, fMiddleName;
    std::cout << "Enter the filter for second name:\n";
    getline(std::wcin, fSecondName);
    std::cout << "Enter the filter for first name:\n";
    getline(std::wcin, fFirstName);
    std::cout << "Enter the filter for patronymic name:\n";
    getline(std::wcin, fMiddleName);

    int counter = 0;

    std::cout << "Match list:\n";

    for (int index = 0; index < length; index++) {
        Human node = data[index];
        if (node.secondName.find(fSecondName) == 0
            && node.firstName.find(fFirstName) == 0
            && node.middleName.find(fMiddleName) == 0) {
            std::wcout << ++counter << ". " << node.secondName << ' '
                       << node.firstName << ' ' << node.middleName << '\n';
        }
    }

    if (counter == 0) std::cout << "No matches.\n";
}

void Program::run() {
    std::cout << "Enter filename:\n";
    std::cin >> fileName;
    readFile();

    std::cout << "Would you like to print list? [y/n]\n";
    char input = '\0';
    std::cin >> input;

    if (input == 'y') print();

    std::cout << "Would you like to filter list? [y/n]\n";
    (std::cin >> input).get();

    if (input == 'y') filter();
}