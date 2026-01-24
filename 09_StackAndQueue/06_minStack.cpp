#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack <pair<int,int>> st;
    
public:
        MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        if(st.empty()) {
            
            st.push( {value, value} );
            return;
        }
        
        int mini = min(getMin(), value);
        
        st.push({value, mini});
    }
    
    // Method to pop a value from stack
    void pop() {
        st.pop(); 
    }
    
    // Method to get the top of stack
    int top() {
        return st.top().first;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        return st.top().second;
    }
};



class MinStackk {
    private:
    stack<int>st;
    int mini = INT_MAX;

    public:
    MinStackk(){

    }

    void push(int x){
        if(st.empty()){
            st.push(x);
            mini = x;
        }
        else{
            if(x >= mini) st.push(x);
            else{
                st.push(2 * x - mini);
                mini = x;
            }
        }

    }

    int pop(){
        if(st.empty()){
            return -1;
        }

        int x = st.top();
        st.pop();

        if(x < mini){
            int n = mini;
            mini = 2 * mini - x;
            return n;
        }
        return x;
    }

    int top(){
        if(st.empty()) return -1;

        int x = st.top();
        if(mini < x) return x;
        return mini;
    }

    int getMini(){
        return st.empty()? -1 : mini;
    }
};

int main() {
    MinStack s;
    MinStackk ss;
    
    ss.push(-2);
    ss.push(0);
    ss.push(-3);
    cout << ss.getMini() << " ";
    cout << ss.pop() << " ";
    cout << ss.top() << " ";
    cout << ss.pop() << " ";
    cout << ss.getMini();
    
    return 0;
}