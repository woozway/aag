class MinStack {
  stack<int> a, b; // a中存原始，b中存栈底开头的每段最小值
public:

  void push(int x) {
      a.push(x);
      b.empty() ? b.push(x) : b.push(min(b.top(), x));
  }
  
  void pop() {
      a.pop(), b.pop();
  }
  
  int top() {
      return a.top();
  }
  
  int getMin() {
      return b.top();
  }
};