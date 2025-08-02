#include <iostream>
#include "Sushi.h"
#include "SushiMenu.h"
using namespace std;

int getMenuChoice(int choice);
void menuChoice(SushiMenu& menu, int choice, int num, string name, string description, double price, int piece, bool raw, bool spicy);

int main() {
    SushiMenu menu;
    int num;
    string name;
    string description;
    double price;
    int piece;
    bool raw;
    bool spicy;

    int choice;

    do {
		choice = getMenuChoice(choice);
        cin.ignore();
        menuChoice(menu, choice, num, name, description, price, piece, raw, spicy);

    }while(choice != 5);


    return 0;
}

int getMenuChoice(int choice){
    cout << "****************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                        🍣 WELCOME TO THE                           **\n";
		cout << "**                          SUSHI RESTAURANT                          **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** Please make a choice from the following options:                   **\n";
		cout << "** 1)  ➕ Add a new Sushi to the menu                                 **\n";
		cout << "** 2)  📝 Modify an existed Sushi                                     **\n";
		cout << "** 3)  ❌ Delete a Sushi from the menu                                **\n";
		cout << "** 4)  📋 Show All Sushi on the menu.                                 **\n";
        cout << "** 5)  🚪 Exit                                                        **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
        cin>>choice;

        return choice;
}



void menuChoice(SushiMenu& menu, int choice, int num, string name, string description, double price, int piece, bool raw, bool spicy){
    switch(choice){
        case 1:
        {
            char rawAns, spicyAns;
            cout<<"Enter Sushi/Roll name: ";
            getline(cin, name);
            cout<<"Enter Sushi/Roll description: ";
            getline(cin, description);
            cout<<"Enter Sushi/Roll price: ";
            cin>>price;
            cout<<"How many pieces: ";
            cin>>piece;
            cout<<"Does it contain raw fish (Y/N): ";
            cin>>rawAns;
            if(rawAns == 'Y'){
                raw = true;
            } 
            if(rawAns == 'N'){
                raw = false;
            }
            cout<<"Is it spicy (Y/N): ";
            cin>>spicyAns;
            if(spicyAns == 'Y'){
                spicy = true;
            } 
            if(spicyAns == 'N'){
                spicy = false;
            }
            Sushi sushi(name, description, price, piece, raw, spicy);
            menu.addSushi(sushi);
            cout<<"Sushi/Roll successfully added!\n\n";
            
        } break;
        case 2:{
        string category, newValue;
        bool modify = true;
        cout<<menu;
        cout<<"\nEnter the ID of the sushi/roll you want to modify: ";
        cin>>num;
        cin.ignore();
        do{
        cout<<"\nPlease enter the category you want to modify\n"
            <<"(ex.: name, description, price, pieces, raw, spicy): ";
            getline(cin, category);
        if(category == "name" || category == "description" || category == "price" || category == "pieces"){
            cout<<"Please enter the new "<<category<<" for your sushi/roll: ";
            getline(cin, newValue);
            modify = true;
        } else if(category == "raw" || category == "spicy"){
            cout<<"Is you sushi/roll "<<category<<"? (Y/N): ";
            getline(cin, newValue);
            modify = true;
        }else{
            cout<<"Error! Can't find this category. Try again.\n";
            modify = false;
        }
        }while(modify == false);
        if(menu.modifySushi(num, category, newValue)){
            cout<<"\nSushi updated Successfully!\n";
        }else{
            cout<<"\nCannot update Sushi.\n";
        }
        } break;
        case 3:{
            cout<<menu<<"\n";
            cout<<"Which Sushi/Roll would you like to remove (enter sushi ID, or -1 to cancel): ";
            cin>>num;
            if(menu.removeSushi(num)){
                cout<<"Sushi/Roll successfully removed. \n";
            } else{
                cout<<"Error! Sushi not found.\n";
            }
        } break;
        case 4:{
            cout<<menu<<"\n";
        } break;
        case 5: cout<<"Exiting ... Bye!\n"; break;
    }
}