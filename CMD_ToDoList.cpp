// CMD_ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends here.
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
void finish(std::vector<std::string>& List);

int main()
{
    std::vector<std::string> List;
    std::string str;
    int input;

    std::ifstream loadFile("List.txt");
    if (!loadFile.fail()) {
        while (std::getline(loadFile, str))
        {
          
            if (str.size() > 0)
                List.push_back(str);
        }
    }

    loadFile.close();
    

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



    finish(List);


    std::system("cls");
    cout << " >> Program closed successfully...Goodbye \n";

        
    return 0;
}


void RemoveFromList(std::vector<std::string>& List){//remove item form list

    if (List.size() > 0){

        int selection;
        cout << "Which item would you like to delete (type index number) \n";
        cout << ">> ";
        std::cin >> selection;
        cout << "\n";

        if (selection <= 0 || selection > List.size()) {
            cout << "*ERROR* index out of scope, select an item index from within the list!\n\n";

        }
        else {

            List.erase(List.begin() + (selection - 1));
            
            cout << "Item successfully Removed! Returning to menu...\n\n";

        }

    }else {

        cout << "*ERROR* List is empty! (Add one item to create a list before trying to remove it) \n\n";
    }
}

void AddToList(std::vector<std::string>& List){// add item to list

    std::string newItem;
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    cout << "Please type a new item to add to your to-do list. \n";
    cout << ">> ";
    getline(std::cin, newItem);
    cout << "\n";
    List.push_back(newItem);

    cout << "Item successfully Added! Returning to menu...\n\n";

}

void ShowList(std::vector<std::string>& List){// show current to-do list

    if (List.size() > 0) {
        cout << "TO-DO List: \n";

        for (int i = 0; i < List.size(); i++) {
            cout << "\t" << i+1 << ". " << List[i] << "\n";
        }

        cout << "End of list.....\n\n";
    }else {
        cout << "*ERROR* List is empty! (Add one item to create a list before trying to view list) \n\n";
    }
}

void finish(std::vector<std::string>& List) {//save list into document (ready system for shutdown)
    std::ofstream backUpFile("List.txt", std::ios::out | std::ios::trunc);
    if (List.size() > 0) {
        for (int i = 0; i < List.size(); i++) {
            backUpFile << List[i] << "\n";
        }
        backUpFile.close();
    }
    else {
        backUpFile.close();
        std::remove("List.txt");
    }

}

