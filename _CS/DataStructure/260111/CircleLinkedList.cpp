#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircleLinkedList
{
private:
    Node *head;

public:
    CircleLinkedList() : head(nullptr) {}

    void append(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void display()
    {
        if (head == nullptr)
            return;

        Node *temp = head;

        do
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        } while (temp != head);

        cout << "다시 처음으로" << endl;
    }

    ~CircleLinkedList()
    {
        if (head == nullptr)
            return;

        Node *cur = head;
        Node *nextNode = nullptr;

        do
        {
            nextNode = cur->next;
            delete cur;
            cur = nextNode;
        } while (cur != head);
    }
};

int main()
{
    CircleLinkedList circleList;

    for (int i = 1; i <= 10; i++)
    {
        circleList.append(i * 10);
    }

    cout << "환형 연결리스트 구성: " << endl;

    circleList.display();

    return 0;
}