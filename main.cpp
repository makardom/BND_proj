#include <iostream>
#include <windows.h>
#include "BND.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    BND bnd;
    bool exit = false;
    while (!exit) {
        cout << "Choose your option:" << endl;
        cout << "1 - create BND" << endl;
        cout << "2 - Set parameters" << endl;
        cout << "3 - print BND" << endl;
        cout << "4 - add" << endl;
        cout << "5 - rename catalog" << endl;
        cout << "6 - Delete" << endl;
        cout << "7 - Reorganisation" << endl;
        cout << "8 - OutFreeSpace" << endl;
        cout << "9 - printCatalog" << endl;
        cout << "10 - OutSectionAlphabet" << endl;
        cout << "11 -DeleteSection" << endl;
        cout << "0 - Exit" << endl;

        int choice = 0;
        cin >> choice;

        switch (choice) {
            case 0: {
                cout << "Good bye!" << endl;
                exit = true;
                break;
            }
            case 1: {
                ::getchar();
                cout << "Enter BND's name:";
                string name;
                cin >> name;
                cout << "Enter the amount of catalog:";
                int catamount;
                cin >> catamount;
                cout << "Enter the amount of data:";
                int dataamount;
                cin >> dataamount;
                bnd.create(name, catamount, dataamount);
//                bnd.setName(name);
//                bnd.setCatamount(catamount);
//                bnd.setCatOffset(dataamount);
                cout << "BND has been created!" << endl;
                break;
            }
            case 2: {
                ::getchar();
                cout << "Choose parameters:" << endl;
                cout << "1 - CatOffset" << endl;
                cout << "2 - CatAmount" << endl;
                cout << "3 - setName" << endl;
                int propChoice;
                cin >> propChoice;

                switch (propChoice) {
                    case 1: {
                        ::getchar();
                        cout << "Enter CatOffset:";
                        short offset;
                        cin >> offset;
                        bnd.setCatOffset(offset);
                        break;

                    }
                    case 2: {
                        ::getchar();
                        cout << "Enter CatAmount:";
                        short amount;
                        cin >> amount;
                        bnd.setCatamount(amount);
                        break;
                    }
                    case 3: {
                        ::getchar();
                        cout << "Enter name:";
                        string newName;
                        cin >> newName;
                        bnd.setName(newName);
                        break;
                    }
                    default: {
                        cout << "Wrong choice" << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
                bnd.print();
                break;
            }
            case 4: {
                ::getchar();
                cout << "Enter name: ";
                string catname;
                //getline(cin, catname);
                cin>>catname;
                cout << "Enter length: ";
                int length;
                cin >> length;
                cin.ignore();
                try {
                    bnd.add(catname, length);
                }
                catch(Error er){
                    cerr<<er.str;
                    break;
                }
                cout << "Element has been added." << endl;
                break;
            }
            case 5: {
                ::getchar();
                cout << "Enter old name: ";
                string oldname, newname;
                getline(cin, oldname);
                cout << "Enter new name: ";
                getline(cin, newname);
                try {
                    bnd.renameCatalog(oldname, newname);
                }
                catch (Error er){
                    cerr<<er.str;
                    break;
                }
                cout << "Catalog has been renamed." << endl;
                break;
            }
            case 6: {
                bnd.Delete();
                cout << "Deleted." << endl;
                break;
            }
            case 7: {
                try {
                    bnd.reorganization();
                }
                catch (Error er){
                    cerr<<er.str;
                    break;
                }
                cout << "BND has been reorganized." << endl;
                break;
            }
            case 8:{
                bnd.OutFreeSpace();
                cout<<"BND out free space."<<endl;
                break;
            }
            case 9:{
                bnd.printCatalog();
                break;
            }
            case 10:{
                bnd.OutSectionAlphabet();
                break;
            }
            case 11:{
                ::getchar();
                cout << "Enter section name: ";
                string sectionName;
                getline(cin, sectionName);
                try {
                    bnd.DeleteSection(sectionName);
                }
                catch (Error er){
                    cerr<<er.str;
                    break;
                }
                break;
            }
            default:{
                cout << "Wrong choice" << endl;
                break;
            }
        }
    }
}