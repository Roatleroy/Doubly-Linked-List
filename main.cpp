#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <stdlib.h> 
#include <vector>
#include <stdio.h>
using namespace std;

int keep = 0;

struct NODE {
    int value = 0;
    NODE* previous = NULL;
    NODE* next = NULL;

    void createInitalNode(NODE*& head, NODE*& tail, int value) {
        NODE* node = new NODE();
        node->value = value;
        node->previous = NULL;
        node->next = NULL;
        head = node;
        tail = node;
        keep++;
    }

    // Inserts new nodes at the beginning with the head pointer
    void InsertBeginning(int value, NODE*& head) {
        NODE* node = new NODE();
        node->value = value;
        node->next = head;
        node->previous = NULL;
        head->previous = node;
        head = node;
        keep++;
        //return head;
    }


    // Inserts new nodes at the end with the tail pointer
    void InsertAtEnd(int value, NODE*& tail) {
        NODE* node = new NODE();
        node->value = value;
        node->next = NULL;
        node->previous = tail;
        tail->next = node;
        tail = node;
        keep++;
        // return tail;
    }

    // Pops nodes at the beginning of the linked list
    void PopFront(NODE* head) {

        if (isEmpty(head)) {
            return;
            cout << "LIST IS EMPTY!!";
        }

        int values;
        NODE* node2;

        node2 = head;
        head = head->next;
        values = node2->value;
        delete node2;


        cout << values << " removed" << endl;
    }

    // Pops nodes at the end of the linked list
    void PopBack(NODE* tail) {

        if (isEmpty(tail)) {
            cout << "LIST IS EMPTY!!";
            return;
        }

        int values;
        NODE* node2;

        node2 = tail;
        tail = tail->previous;
        values = node2->value;

        delete node2;

        cout << values << " removed" << endl;
    }

    // Displays the linked list from the Head node to the Tail node
    void displayForwardValues(NODE* head) {
        NODE* traverse;
        int values = keep;

        if (isEmpty(head)) {
            cout << "LIST IS EMPTY!!";
            return;
        }

        traverse = head;

        while (values != 0) {
            cout << traverse->value;
            traverse = traverse->next;
            cout << " ";
            --values;
        }

    }

    // Displays the linked list from the Tail node to the Head node
    void displayBackwardsValues(NODE* tail) {
        NODE* traverse;
        int values = keep;

        if (isEmpty(tail)) {
            cout << "LIST IS EMPTY!!";
            return;
        }

        cin.ignore();

        traverse = tail;

        while (values != 0) {
            cout << traverse->value;
            traverse = traverse->previous;
            cout << " ";
            --values;
        }

    }

    //Checks if list only has one nodes
    bool isEmpty(NODE* backORfront) {
        if (backORfront->next == NULL && backORfront->previous == NULL) {
            return true;
        }
        else
            return false;

    }
};

int main() {

    int values = 0;

    NODE NODES;

    NODE* head = NULL;
    NODE* tail = NULL;

    NODES.createInitalNode(head, tail, values);

    int choice;

    int exit = 1;


    while (exit == 1) {

        cout << endl << endl << "1 = PushOntoFront() " <<
            endl << "2 = PushOntoBack()" <<
            endl << "3 = PopFront()" <<
            endl << "4 = PopBack()" <<
            endl << "5 = PrintForward()" <<
            endl << "6 = PrintBackward()" <<
            endl << "7 = Exit" << endl << endl;

        cout << "What is your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "What value do you want stored at the beginning?:" << endl;
            cin >> values;
            NODES.InsertBeginning(values, head);
            cin.ignore();
            break;
        case 2:
            cout << "What value do you want to be stored at the end?" << endl;
            cin >> values;
            NODES.InsertAtEnd(values, tail);
            break;
        case 3:
            NODES.PopFront(head);
            break;
        case 4:
            NODES.PopBack(tail);
            break;
        case 5:
            NODES.displayForwardValues(head);
            cin.ignore();
            break;
        case 6:
            NODES.displayBackwardsValues(tail);
            cin.ignore();
            break;
        case 7:
            exit = 0;
            break;

        }
        cin.ignore();
        //system("CLS");
    }


}