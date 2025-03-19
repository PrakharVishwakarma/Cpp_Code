#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st; // Stack of integers

    cout << "Initially, stack.empty(): " << st.empty() << endl;

    st.push(10); // Pushing elements
    st.push(20);
    st.push(30);

    std::cout << "After adding elements, stack.empty(): " << st.empty() << endl;

    cout << "Stack size: " << st.size() << endl; // Output: 3
    cout << "Top element: " << st.top() << endl; // Output: 30

    st.pop();                                              // Removing top element (30)
    cout << "Top element after pop: " << st.top() << endl; // Output: 20

    st.emplace(45);
    cout << "Stack size: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;

    cout << "stack st = ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    std::stack<int> foo, bar;
    foo.push(10);
    foo.push(20); 
    foo.push(30);

    bar.push(111);
    bar.push(222);

    foo.swap(bar);

    cout <<endl<< "size of foo: " << foo.size() << '\n'<<"Stack foo : ";
    while (!foo.empty()){
        cout << foo.top() << " ";
        foo.pop();
    }
    cout <<endl<< "size of bar: " << bar.size() << '\n'<<"Stack bar : ";
    while (!bar.empty()){
        cout << bar.top() << " ";
        bar.pop();
    }
    

    return 0;
}
