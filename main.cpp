// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos

#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> mystack;
    map<int, int> mins;
    MinStack() {
    }
    
    void push(int x) {
        mystack.push(x);
        mins[x] = mins[x] + 1;
    }
    
    void pop() {
      mins[mystack.top()] = mins[mystack.top()] - 1;
      if (mins[mystack.top()] == 0) {
        mins.erase(mystack.top());
      }
      mystack.pop();
    }
    
    int top() {
      return mystack.top();
    }
    
    int getMin() {
      return mins.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {

  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  cout << "-2? " << minStack.getMin() << endl;
  minStack.push(-3);
  cout << "-3? " << minStack.getMin() << endl;
  minStack.pop();
  cout << "0? " << minStack.top() << endl;
  cout << "-2? " << minStack.getMin() << endl;

  cout << "Done!" << endl;

  return 0;
}
