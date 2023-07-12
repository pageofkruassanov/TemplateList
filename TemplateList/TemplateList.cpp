#include "includes.h"
using namespace std;

int main()
{
    string str = "Hello";
    string str2 = ", ";
    string str3 = "World";
    string str4 = "!";
    MyList::List<string> obj(str2);
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
    cout << endl << "---------------------" << endl;
    obj.AddToTail(str);
    obj.AddToTail(str2);
    obj.AddToTail(str3);
    obj.AddToTail(str4);
    obj.InsertNode(5, str4);
    obj.InsertNode(1, str4);
    obj.InsertNode(2, str2);
    obj.Show();
    cout << endl << "---------------------" << endl;
    obj.RemoveNode(2);
    obj.RemoveNode(1);
    obj.Show();
    cout << endl << "-------------------" << endl;
    obj.ChangeNode(str4, str2);
    obj.Show();
    cout << endl << "---------------------" << endl;
    obj.ReverseList();
    obj.Show();
    cout << endl << "---------------------" << endl;
    obj.RemoveNode(1);
    obj.RemoveNode(1);
    obj.RemoveNode(1);
    obj.ReverseList();
    obj.Show();
    cout << endl << "--------------------" << endl;
    obj.AddToTail(str3);
    obj.AddToTail(str4);
    obj.Show();
}