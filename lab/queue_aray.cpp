#include <iostream>
using namespace std;

int front = -1, rear = -1;

void Insert(int queue[], int n) {
   int val;
   if (rear == n - 1)
      cout << "Queue Overflow" << endl;
   else {
      if (front == -1)
         front = 0;
      cout << "Insert the element in queue : " << endl;
      cin >> val;
      rear++;
      queue[rear] = val;
   }
}

void Delete(int queue[], int n) {
   if (front == -1 || front > rear) {
      cout << "Queue Underflow ";
      return;
   } else {
      cout << "Element deleted from queue is : " << queue[front] << endl;
      front++;
   }
}

void Display(int queue[], int front, int rear) {
   if (front == -1)
      cout << "Queue is empty" << endl;
   else {
      cout << "Queue elements are: ";
      for (int i = front; i <= rear; i++)
         cout << queue[i] << " ";
      cout << endl;
   }
}

int main() {
   int n;
   cin >> n;

   int queue[n + 1];
   for (int i = 0; i < n; i++) {
      Insert(queue, n);
   }

   Display(queue, front, rear);
   Delete(queue, n);
   Display(queue, front, rear);

   return 0;
}

