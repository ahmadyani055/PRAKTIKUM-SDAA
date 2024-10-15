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

// Shell Sort (descending)
int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

// Quick Sort (ascending)
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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

void menu()
{
    cout << "===== Menu =====" << endl;
    cout << "1. Tampilkan Linked List" << endl;
    cout << "2. Shell Sort (Descending)" << endl;
    cout << "3. Quick Sort (Ascending)" << endl;
    cout << "4. Keluar" << endl;
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
            cout << "Sebelum disorting (Descending): ";
            display(HEAD);
            shellSort(arr, length(HEAD));
            array2LinkedList(HEAD, arr);
            cout << "Setelah disorting (Descending): ";
            display(HEAD);
            break;
        case 3:
            cout << "Sebelum disorting (Ascending): ";
            display(HEAD);
            quickSort(arr, 0, length(HEAD) - 1);
            array2LinkedList(HEAD, arr);
            cout << "Setelah disorting (Ascending): ";
            display(HEAD);
            break;
        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (choice != 4);

    return 0;
}
