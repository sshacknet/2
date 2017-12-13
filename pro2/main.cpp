#include <QtCore/QCoreApplication>
#include <thread>
#include "AVLTree.hpp"
#include <iostream>
#include <fstream>
#include "CharString.h"
#include <codecvt>
extern const std::locale empty_locale = std::locale::empty();
typedef std::codecvt_utf8<wchar_t> converter_type; 
extern const converter_type* converter = new converter_type;
extern const std::locale utf8_locale = std::locale(empty_locale, converter);



using namespace std;
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //return a.exec();
    AVLTree<String> tree;

    std::wifstream dic_fin("dictionary/dictionary.dic");
    dic_fin.imbue(utf8_locale);
    int total = 0;
    if (dic_fin)
    {
        wstring temp;
        while (getline(dic_fin, temp))
        {
            total++;
            if (total % 1000 == 0)
            {
                cout << "\r Loading Dictionary... [" << total << "] words";
            }
            String tmp(temp);

            tree.insert(tmp);
        }
    }
    else
    {
        cout << "error";
        throw Error("fail to load dictionary");
    }
    
    cout << tree.height();
    system("pause");
    return 0;
}
