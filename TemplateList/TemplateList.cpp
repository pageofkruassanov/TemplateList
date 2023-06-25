#include "includes.h"

int main()
{
    string str = "Hello";
    string str2 = ", ";
    string str3 = "World";
    string str4 = "!";
    List<string> obj(str2);
    obj.Show();
    obj.AddToTail(str3);
    obj.Show();
    cout << endl << "----------------------------" << endl;
    obj.AddToTail(str4);
    obj.AddToHead(str);
    obj.Show();
    cout << endl << "-------------------------" << endl;
    obj.DeleteFromTail();
    obj.DeleteFromHead();
    obj.DeleteFromHead();
    obj.Show();
    cout << endl << "---------------------" << endl;
    obj.DeleteAll();
    obj.Show();
}