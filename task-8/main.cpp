#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structs
struct Item { // By giving a name to a structure, you can treat it as a data type - so you can create variables with this struct anywhere in the program
    string itemName = "itemNamePlaceholder";
    int itemId = 0;
    int itemQuantity = 0;
};

//Vectors
vector<Item> inventory; // Vector is a resizeable array that can grow/shrink as needed. <Item> represents the type of value this vector stores - items.

int setInventorySize(int inventorySize = 0, Item emptyItem)
{
    // User specifies the inventory size
    std::cout << "Specify the inventory size: ";
    cin >> inventorySize;

    if (isdigit(inventorySize) && inventorySize >= 0 && inventorySize <= 16)
    {
        for (int i = 0; i < inventorySize; i++) // Loop for each inventory slot
        {
            inventory.push_back(emptyItem); // Adds an empty item to each slot in the inventory vector
        }
    }
    while (cin.fail())
    {
        cerr << "\n\033[41m[ERROR]\033[0m Invalid input! Please enter a number between 1-16: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> inventorySize;
    }

    cout << "\nInventory created with " << inventorySize << " slot(s).\n\n";
}

string invalidInputCheck(string commandInput1) // Takes 1 command input
{
    if ((cin.fail()))
    {
        cerr << "\n[ERROR] Invalid input! Please try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> commandInput1;
    }

    return commandInput1;
}

string invalidInputCheck(string commandInput1, string commandInput2) // Takes 2 command inputs
{
    if ((cin.fail()))
    {
        cerr << "\n[ERROR] Invalid input! Please try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> commandInput1;
        cin >> commandInput2;
    }

    return commandInput1, commandInput2;
}

string invalidInputCheck(string commandInput1, string commandInput2, string commandInput3) // Takes 3 command inputs
{
    if ((cin.fail()))
    {
        cerr << "\n[ERROR] Invalid input! Please try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> commandInput1;
        cin >> commandInput2;
        cin >> commandInput3;
    }

    return commandInput1, commandInput2, commandInput3;
}

//Functions
string helpCommand(string commandInput1)
{
    invalidInputCheck(commandInput1);

    if (commandInput1 == "help")
    {
        cout << "\nAVAILABLE COMMANDS" << endl;
        cout << "------------------\n\n";

        cout << "\033[35mview <inventory slot index>\033[0m outputs the full details of the inventory slot index" << endl;
        cout << "\033[35mshow_all\033[0m shows all slots in the inventory and information about each" << endl;
        cout << "\033[35mset <index> <item id>\033[0m sets inventory slot \033[35m<index>\033[0m to the item index \033[35m<item id>\033[0m" << endl;
        cout << "\033[35mitems\033[0m shows all items you can possibly set a slot to, along with their IDs" << endl;
        cout << "\033[35mexit\033[0m exits the program" << endl;
        cout << "\033[35mrestart\033[0m restarts the session and goes back to the first step" << endl;
        cout << "\033[35mhelp\033[0m shows list of available commands" << endl;
        cout << "\033[35mclear\033[0m clears the inventory\n\n";
    }

    return commandInput1;
}

string viewCommand(string commandInput1, string commandInput2, int inventorySlotIndex, int inventorySize)
{
    invalidInputCheck(commandInput1, commandInput2);

    if (commandInput1 == "view")
    {
        if (stoi(commandInput2) == true) // Converts the second portion of the command input to an integer
        {
            cout << "commandInput2 conversion to integer SUCCESS";
            cout << commandInput2;

            for (inventorySlotIndex = 0; inventorySlotIndex < inventorySize; inventorySlotIndex++)
            {
                inventory.at(inventorySlotIndex);
            }
        }
        else if (stoi(commandInput2) == false)
        {
            cerr << "[ERROR] Invalid input! Please enter your command in this format: \033[35mview <inventory slot index>\033[0m\n\n";
        }
    }

    return commandInput1, commandInput2;
}


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
    cout << "CHALLENGE 8" << endl;
    cout << "-----------" << endl;

    // Build inventory system using a suitable dynamic data structure (vector)
    // Collection of all possible inventory items. Make it so the user can set inventory slots to one of these values
    // Each index in this collection should represent data associated with a particular item, e.g. its name
    // User should be able to interact with the inventory via space-delimited commands
    // The user should be able to:
    // - Specify the inventory size (1-16 slots)
    // - Type space de-limited commands to interact with the inventory. Should not initially prmpt the user for an action
    // Code should be easily extensible and configurable, such that it can easily be used in a text-bsaed game
    // Invalid input should be dealt with throughout the solution

    // Inventory variable declarations
    int inventorySlotIndex = 0;

    // Command variable declarations
    string commandInput1 = "";
    string commandInput2 = "";
    string commandInput3 = "";

    bool bAllowCommands = true;

    

    cout << "Type \"\033[35mhelp\033[0m\" for a list of commands.\n\n";

    while (bAllowCommands == true)
    {
        cin >> commandInput1;
        cin >> commandInput2;
        cin >> commandInput3;
        helpCommand(commandInput1);
        viewCommand(commandInput1, commandInput2, inventorySlotIndex, inventorySize);
    }

    /*std::string command;
    int index = 0;
    int itemId = 0;*/

    //std::string name;
    //std::cin >> name;

    //std::cout << "hello " << name << std::endl;

    //exit(1);

    //abc def ghi
    // - std::cin >> str1; -> "abc"
    // - std::cin >> str2; -> "def"
    // - std::cin >> str3; -> "ghi"

    /*std::cin >> command;

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

    return 0;*/
}