#include <iostream>
using namespace std;
#define max 5
class CircularQueue {
	int cqueue[max];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        
    }

    void enqueuecq(int data) {
        if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
            cout << "Queue Overflow \n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            if (rear == max - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
        cqueue[rear] = data;
    }

    void dequeuecq() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Element deleted from queue is : " << cqueue[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            if (front == max - 1)
                front = 0;
            else
                front = front + 1;
        }
    }

    void displaycq() {
        int f = front, r = rear;
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are :\n";
        if (f <= r) {
            while (f <= r) {
                cout << cqueue[f] << " ";
                f++;
            }
        } else {
            while (f <= max - 1) {
                cout << cqueue[f] << " ";
                f++;
            }
            f = 0;
            while (f <= r) {
                cout << cqueue[f] << " ";
                f++;
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int ch, val;
    cout << "1)Insert Element\n";
    cout << "2)Delete the top element\n";
    cout << "3)Display the circular queue\n";
    cout << "4)Exit\n";
    do {
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Input any value for insertion: " << endl;
                cin >> val;
                cq.enqueuecq(val);
                break;
            case 2:
                cq.dequeuecq();
                break;
            case 3:
                cq.displaycq();
                break;
            case 4:
                cout << "Exit\n";
                break;
            default:
                cout << "Incorrect insertion!\n";
        }
    } while (ch != 4);
    return 0;
}