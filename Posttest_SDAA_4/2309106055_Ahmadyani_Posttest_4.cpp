#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int length(Node *head)
{
    int panjang = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        panjang++;
    }
    return panjang;
}

int linkedList2Array(Node *head, int *arr)
{
    int panjang = length(head);
    for (int i = 0; i < panjang; i++)
    {
        arr[i] = head->data;
        head = head->next;
    }
    return 0;
}

int array2LinkedList(Node *head, int *arr)
{
    int panjang = length(head);
    for (int i = 0; i < panjang; i++)
    {
        head->data = arr[i];
        head = head->next;
    }
    return 0;
}

int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct Stack
{
    int top;
    int arr[100];

    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top < 99)
        {
            top++;
            arr[top] = value;
        }
    }

    int pop()
    {
        if (top >= 0)
        {
            int temp = arr[top];
            top--;
            return temp;
        }
        return -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

struct Queue
{
    int front, rear;
    int arr[100];

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear < 99)
        {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = value;
        }
    }

    int dequeue()
    {
        if (front > rear || front == -1)
        {
            return -1;
        }
        int temp = arr[front];
        front++;
        return temp;
    }

    bool isEmpty()
    {
        return front > rear || front == -1;
    }
};

void menu()
{
    cout << "===== Menu =====" << endl;
    cout << "1. Tampilkan Linked List" << endl;
    cout << "2. Shell Sort Linked List" << endl;
    cout << "3. Operasi Stack" << endl;
    cout << "4. Operasi Queue" << endl;
    cout << "5. Keluar" << endl;
    cout << "================" << endl;
}

int main()
{
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node5 = new Node;

    node1->data = 2;
    node2->data = 1;
    node3->data = 4;
    node4->data = 3;
    node5->data = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    Node *HEAD = node1;
    int arr[length(HEAD)];
    linkedList2Array(HEAD, arr);

    Stack stack;
    Queue queue;

    int choice;

    do
    {
        menu();
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Linked List: ";
            display(HEAD);
            break;
        case 2:
            cout << "Sebelum disorting: ";
            display(HEAD);
            shellSort(arr, length(HEAD));
            array2LinkedList(HEAD, arr);
            cout << "Setelah disorting: ";
            display(HEAD);
            break;
        case 3:
            cout << "Stack Push: ";
            for (int i = 0; i < length(HEAD); i++)
            {
                stack.push(arr[i]);
                cout << arr[i] << " ";
            }
            cout << endl;

            cout << "Stack Pop: ";
            while (!stack.isEmpty())
            {
                cout << stack.pop() << " ";
            }
            cout << endl;
            break;
        case 4:
            cout << "Queue Enqueue: ";
            for (int i = 0; i < length(HEAD); i++)
            {
                queue.enqueue(arr[i]);
                cout << arr[i] << " ";
            }
            cout << endl;

            cout << "Queue Dequeue: ";
            while (!queue.isEmpty())
            {
                cout << queue.dequeue() << " ";
            }
            cout << endl;
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (choice != 5);

    return 0;
}
