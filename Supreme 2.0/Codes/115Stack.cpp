// Leetcode 1472 : Design Browser History

#include <iostream>
#include <stack>

using namespace std;

class BrowserHistory{
    stack<string> browserSt, fwdSt;
public:
    BrowserHistory(string homepage){
        browserSt.push(homepage);
    }

    void visit(string url){
        while (!fwdSt.empty()) {
            fwdSt.pop();
        }
        browserSt.push(url);
    }

    string back(int steps){
        while (steps--){
            if(browserSt.size() > 1){
                fwdSt.push(browserSt.top());
                browserSt.pop();
            }else{
                break;
            }
        }
        return browserSt.top();
    }

    string forward(int steps){
        while (steps--){
            if(!fwdSt.empty()){
                browserSt.push(fwdSt.top());
                fwdSt.pop();
            }else{
                break;
            }
        }
        return browserSt.top();
    }
};

int main()
{
    string homepage = "http://www.cpp.com";
    BrowserHistory *obj = new BrowserHistory(homepage);
    obj->visit("http://www.cplusplus.com");
    obj->visit("http://www.yt.com");
    obj->visit("http://www.inst.com");
    string param_2 = obj->back(3);
    cout<<"After steping back "<<param_2<<endl;
    string param_3 = obj->forward(2);
    cout<<"After steping forward "<<param_3<<endl;
    obj->visit("http://www.x.com");
    obj->visit("http://www.lndn.com");
    string param_4 = obj->forward(2);
    cout<<"After steping forward "<<param_4<<endl;

    return 0;
}


/*
// Linked list Solution : 

class Node {
public:
    string url;
    Node* prev;
    Node* next;
    
    Node(string url) {
        this->url = url;
        prev = nullptr;
        next = nullptr;
    }
};


class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current -> next = newNode;
        newNode -> prev = current;
        current = current -> next;
    }
    
    string back(int steps) {
        while(steps--){
            if(current -> prev) current = current -> prev;
            else break;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if(current -> next) current = current -> next;
            else break;
        }
        return current->url;
    }
};

*/