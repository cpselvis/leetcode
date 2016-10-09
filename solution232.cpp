/**
 * Sysmte Design: Implement Queue using Stacks
 *
 * cpselvis(cpselvis@gmail.com) 
 * Oct 9th, 2016
 */
#include<iostream>
#include<stack>

using namespace std;

class Queue {
private:
  stack<int> st;
  stack<int> tmp;
public:
  // Push element x to the back of queue.
  void push(int x) {
    while (!st.empty())
    {
      tmp.push(st.top());
      st.pop();
    }
    st.push(x);
    while (!tmp.empty())
    {
      st.push(tmp.top());
      tmp.pop();
    }
  }

  // Removes the element from in front of queue.
  void pop(void) {
    st.pop();
  }

  // Get the front element.
  int peek(void) {
    return st.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return st.empty();
  }
};

int main(int argc, char **argv)
{
  Queue que;
  que.push(1);
  que.push(2);
  cout << que.peek() << endl;
  cout << que.peek() << endl;
}
