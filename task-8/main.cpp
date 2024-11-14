#include <iostream>

//struct Item { ... }
//Item allItems[] = { ... }

//heap-allocated array:
//Item* inventory = new Item[size];

//vector:
//std::vector<Item> inventory;
// for (int i =0 ; ....
//    items.push_back(emptyItem)

int main(int argc, char* argv[])
{
    std::string command;
    int index = 0;
    int itemId = 0;

    //std::string name;
    //std::cin >> name;

    //std::cout << "hello " << name << std::endl;

    //exit(1);

    //abc def ghi
    // - std::cin >> str1; -> "abc"
    // - std::cin >> str2; -> "def"
    // - std::cin >> str3; -> "ghi"

    std::cin >> command;

    std::cout << "command: " << command << std::endl;

    if (command == "set")
    {
        std::cin >> index;
        std::cin >> itemId;

        std::cout << "index: " << index << std::endl;
        std::cout << "itemId: " << itemId << std::endl;
    }
    else if (command == "view")
    {
        std::cin >> index;
        std::cout << "index: " << index << std::endl;
    }

    return 0;
}