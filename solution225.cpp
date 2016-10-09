/**
 * System design:  Implement Stack using Queues
 *
 *
 * cpselvis (cpselvis@gmail.com)
 * Oct 9th, 2016
 */
#include<iostream>
#include<queue>

using namespace std;

class Stack {
private:
  queue<int> que;
public:
  // Push element x onto stack.
  void push(int x) {
    que.push(x);
    for (int i = 0; i < que.size() - 1; i ++)
    {
      int tmp = que.front();
      que.pop();
      que.push(tmp);
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    que.pop();
  }

  // Get the top element.
  int top() {
    return que.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return que.empty();
  }
};

int main(int argc, char **argv)
{
  Stack st;
  st.push(1);
  st.push(2);
  cout << st.top() << endl;
  cout << st.top() << endl;
}
