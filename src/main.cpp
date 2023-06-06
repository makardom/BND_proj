#include <iostream>
#include <windows.h>
#include "serializer/BinSerializer.hpp"
size_t getFileLength(const std::string& name){
    // Открываем файл для чтения в бинарном режиме
    ifstream file(name, ios::binary);

    // Определяем начальную позицию чтения
    streampos begin = file.tellg();

    // Перемещаем указатель чтения на конец файла
    file.seekg(0, ios::end);

    // Определяем конечную позицию чтения
    streampos end = file.tellg();
    // Определяем размер файла
    size_t size = end - begin;
    return size;
}
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
        cout << "12 -Save to file" << endl;
        cout << "13 -Delete file" << endl;
        cout << "14 -Get from file" << endl;
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
                cout << "Enter the amount of catalog:";
                unsigned short catamount;
                cin >> catamount;
                cout << "Enter the amount of data:";
                unsigned short dataamount;
                cin >> dataamount;
                bnd.create(catamount, dataamount);
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
                int propChoice;
                cin >> propChoice;

                switch (propChoice) {
                    case 1: {
                        ::getchar();
                        cout << "Enter CatOffset:";
                        unsigned short offset;
                        cin >> offset;
                        bnd.setCatOffset(offset);
                        break;

                    }
                    case 2: {
                        ::getchar();
                        cout << "Enter CatAmount:";
                        unsigned short amount;
                        cin >> amount;
                        bnd.setCatamount(amount);
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
                unsigned int length;
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
            case 12: {
                BinSerializer binSerializer("BND.bin");
                binSerializer.create("BND.bin");
                binSerializer.save(bnd);
                binSerializer.close();
                std::cout<<"file size = "<<getFileLength("BND.bin")<<endl;
                break;
            }
            case 13:{
                const char* filename = "BND.bin";
                if (remove(filename) != 0) {
                    perror("Ошибка удаления файла");
                } else {
                    printf("Файл %s удален\n", filename);
                }
                break;
            }
            case 14:{
                BinSerializer binSerializer("BND.bin");
                binSerializer.load(bnd);
                binSerializer.close();

                break;
            }
            case 15:{
                BinSerializer binSerializer("BND.bin");
                Catalog catalog1;
                binSerializer.load(catalog1,22,2);
                for(CatalogUnit catalogUnit: catalog1.getRecords()){
                    catalogUnit.print();
                    std::cout<<endl;
                }
                std::cout<<"file size = "<<getFileLength("BND.bin");
                binSerializer.close();
                break;
            }
            default:{
                cout << "Wrong choice" << endl;
                break;
            }
        }
    }
}