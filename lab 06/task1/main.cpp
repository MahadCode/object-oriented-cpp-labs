#include<iostream>
#include<string.h>
#include"Menu.h"
#include"item.h"
#include"Order.h"
#include"Table.h"
#include"Restaurant.h"
using namespace std;

int main() {
    int itemCount;
    cout << "How many Items you want to add to Menu:" << endl;
    cin >> itemCount;

    item* itemArr = new item [itemCount];

    for (int i = 0; i < itemCount; i++) {
        cin >> itemArr[i];
    }

    cout << "Adding all items to Menu: " << endl;

    Menu menu;
    for (int i = 0; i < itemCount; i++) {
        menu.addItem(itemArr[i]);
    }

    menu.displayMenu();

    Table* table = new Table[3];
    cout << "Order No 1" << endl;
    Order order;
    int tn;
    cout << "Enter you table number" << endl;
    cin >> tn;
    cout << "Make a Order" << endl;
    table[0].setTableNum(tn);
    order.setTableNumber(tn);
    while(true) {
        int choice;
        cout << "Select an item(-1 to end order)" << endl;
        cin >> choice;
        if (choice < 0) {
            break;
        }
        order += itemArr[choice - 1];
        cout << choice << "item has added to your ordered" << endl;
    }

    order.displayOrder();

    cout << "Order No 2" << endl;
    Order order1;
    int tn1;
    cout << "Enter you table number" << endl;
    cin >> tn1;
    cout << "Make a Order" << endl;
    table[1].setTableNum(tn1);
    order1.setTableNumber(tn1);
    while (true) {
        int choice;
        cout << "Select an item(-1 to end order)" << endl;
        cin >> choice;
        if (choice < 0) {
            break;
        }
        order1 += itemArr[choice - 1];
        cout << choice << "item has added to your ordered" << endl;
    }

    order1.displayOrder();

    cout << "Order No 3" << endl;
    Order order2;
    int tn2;
    cout << "Enter you table number" << endl;
    cin >> tn2;
    cout << "Make a Order" << endl;
    table[2].setTableNum(tn2);
    order2.setTableNumber(tn2);
    while (true) {
        int choice;
        cout << "Select an item(-1 to end order)" << endl;
        cin >> choice;
        if (choice < 0) {
            break;
        }
        order2 += itemArr[choice - 1];
        cout << choice << " item has added to your ordered" << endl;
    }

    order2.displayOrder();



    
    table[0].placeOrder(order);
    table[1].placeOrder(order1);
    table[2].placeOrder(order2);

    Restaurant rest;
    for (int i = 0; i < itemCount; i++) {
        rest.addMenuItems(itemArr[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        rest.addTable(table[i]);
    }
    
    rest.displayRestaurantInfo();
    delete[] itemArr;
    delete[] table;
}