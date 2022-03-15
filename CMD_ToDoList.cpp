// CMD_ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using std::cout;

void ShowList(std::vector<std::string>& List);
void AddToList(std::vector<std::string>& List);
void RemoveFromList(std::vector<std::string>& List);


int main()
{
    std::vector<std::string> List;

    int input;
    

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

}


void RemoveFromList(std::vector<std::string>& List){

    int selection;

    if (List.size() > 0) {
        cout << "Which item would you like to delete (type index number) \n";
        cout << ">> ";
        std::cin >> selection;
        cout << "\n";


        List.erase(List.begin() + (selection - 1)); 
        cout << "Item successfully Removed! Returning to menu...\n\n";

    }
    else {

        cout << "List is empty! Returning to menu... \n\n";
    }





}

void AddToList(std::vector<std::string>& List){
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

void ShowList(std::vector<std::string>& List){
    cout << "TO-DO List: \n";
    for (int i = 0; i < List.size(); i++){
        cout << "\t" << i + 1 << ". " << List[i] << "\n";
    }
    cout << "End of list.....\n\n";
}

