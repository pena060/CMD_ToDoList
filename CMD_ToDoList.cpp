// CMD_ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>

using std::cout;

void ShowList(std::vector<std::string>& List);
void AddToList(std::vector<std::string>& List);
void RemoveFromList(std::vector<std::string>& List);


int main()
{
    std::vector<std::string> List;
    std::string str;
    int input;

    std::ifstream persistentList("List.txt");
    if (!persistentList.fail()) {
        while (std::getline(persistentList, str))
        {
          
            if (str.size() > 0)
                List.push_back(str);
        }
    }

    persistentList.close();
    

    cout << "Welcome to your to-do list!\nv0.9b\n\n";

    cout << "What would you like to do? \n";
    cout << "\t" << "1. View List \n";
    cout << "\t" << "2. Add item to list \n";
    cout << "\t" << "3. Remove item from list \n";
    cout << "\t" << "4. Exit \n";
    cout << ">> ";
    std::cin >> input;
    cout << "\n";

    while (input != 4){

        switch (input) {
        case 1:
            ShowList(List);
            break;
        case 2:
            AddToList(List);
            break;
        case 3:
            RemoveFromList(List);
            break;
        default:
            break;
        }

        cout << "Make new menu selection \n";
        cout << ">> ";
        std::cin >> input;
        cout << "\n";
    } 


    std::system("cls");
    cout << " >> Program closed successfully...Goodbye \n";

        
    return 0;
}


void RemoveFromList(std::vector<std::string>& List){
    std::fstream File("List.txt", std::ios::out | std::ios::trunc);

    if (!File.fail()){

        int selection;
        cout << "Which item would you like to delete (type index number) \n";
        cout << ">> ";
        std::cin >> selection;
        cout << "\n";


        if (selection < 0 || selection >= List.size()) {
            cout << "*ERROR* index out of scope, select an item index from within the list!\n\n";

        }
        else {

            List.erase(List.begin() + selection);

            if (List.size() > 0){
                for (int i = 0; i < List.size(); i++) {
                    File << List[i] << "\n";
                }
                File.close();
            }else{
                File.close();
                std::remove("List.txt");
            }
            
            cout << "Item successfully Removed! Returning to menu...\n\n";

        }

    }else {

        cout << "*ERROR* List is empty! (Add one item to create a list before trying to remove it) \n\n";
    }
}

void AddToList(std::vector<std::string>& List){
    std::ofstream oFile;
    oFile.open("List.txt", std::ios::app);

    std::string newItem;
    std::cin.clear();
    std::cin.ignore(10000, '\n');


    cout << "Please type a new item to add to your to-do list. \n";
    cout << ">> ";
    getline(std::cin, newItem);
    cout << "\n";
    List.push_back(newItem);

    oFile << newItem << "\n";

    oFile.close();

    cout << "Item successfully Added! Returning to menu...\n\n";

}

void ShowList(std::vector<std::string>& List){
    std::ifstream inFile;
    inFile.open("List.txt");

    if (inFile.is_open()) {
        cout << "TO-DO List: \n";

        cout << inFile.rdbuf() << "\n";

        inFile.close();
        cout << "End of list.....\n\n";
    }
    else {
        cout << "*ERROR* List is empty! (Add one item to create a list before trying to view list) \n\n";
    }
}

