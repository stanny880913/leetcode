#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
  queue<int> q;

public:
  MyStack()
  {
  }

  void push(int x)
  {
    q.push(x);
    for (int i = 0; i < q.size(); i++)
    {
      q.push(q.front());
      q.pop();
    }
  }

  int pop()
  {
    int temp = q.front();
    q.pop();
    return temp;
  }

  int top()
  {
    return q.front();
  }

  bool empty()
  {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
  int x = 1;
  MyStack *mystack = new MyStack();
  mystack->push(1);
  mystack->push(1);
  mystack->top();
  mystack->pop();
  mystack->empty();
  return 0;
}