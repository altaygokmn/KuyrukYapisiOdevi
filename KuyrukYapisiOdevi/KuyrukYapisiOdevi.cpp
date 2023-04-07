#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Stack {
private:
    int top;
    int size;
    char* values;

public:
    Stack(int size) {
        this->size = size;
        this->top = -1;
        this->values = new char[size];
    }

    void push(char data) {                                           
        if (StackDoluMu()) {
            cout << "Stack dolu" << endl;
        }
        else {
            this->top++;
            values[this->top] = data;
        }
    }





    bool StackDoluMu() {
        if (this->top == this->size - 1) {
            return true;
        }
        else {
            return false;
        }
    }
    void StackYazdir() {
        if (top == -1) {
            cout << "Stack bos!" << endl;
            return;
        }
        cout << endl << "Stack =  " << endl;
        for (int i = top; i >= 0; i--) {
            cout << values[i] << endl;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Yigin bos!" << endl;
            return '\0';
        }
        char data = values[top];
        top--;
        return data;
    }
};

class Queue {
private:
    int front;
    int rear;
    char* values;
    int size;

public:
    Queue(int size) {
        this->size = size;
        this->values = new char[size];
        front = -1;
        rear = -1;
    }
    bool QueueBosMu() {
        return rear == front;
    }
    bool QueueDoluMu() {
        return this->rear == size - 1;
    }
    void enQueue(char data) {
        if (QueueDoluMu())
        {
            cout << "Kuyruk Dolu" << endl;
        }
        else
        {
            rear++;
            values[rear] = data;
        }
    }
    void QueueYazdir() {
        if (QueueBosMu())
        {
            cout << "Kuyruk Boş";
        }
        else
        {
            cout << endl << "Queue =  " << endl;
            for (int i = 0; i <= rear; i++)
            {
                cout << values[i] << endl;
            }
        }
    }
    char deQueue() {
        if (QueueBosMu())
        {
            cout << "Kuyruk Boş" << endl;
            return '\0';
        }
        char data = values[front];
        front++;
        return data;
    }
};

int main() {
    string kelime;
    cout << "Bir kelime girin: ";
    cin >> kelime;

    int uzunluk = kelime.length();

    Stack stackOrnegi(uzunluk);
    Queue queueOrnegi(uzunluk);

    for (int i = 0; i < uzunluk; i++) {
        stackOrnegi.push(kelime[i]);
        queueOrnegi.enQueue(kelime[i]);
    }

    bool palindromMu = true;

    for (int i = 0; i < uzunluk; i++) {
        if (stackOrnegi.pop() != queueOrnegi.deQueue()) {
            palindromMu = false;
            break;
        }
    }
    stackOrnegi.StackYazdir();
    queueOrnegi.QueueYazdir();
    if (palindromMu) {
        cout << kelime << " kelimesi palindromdur." << endl;
    }
    else {
        cout << kelime << " kelimesi palindrom degildir." << endl;
    }

    return 0;
}