class MinStack {
public:
    stack<int> st;
    stack<int> sorted;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        sort(val,1);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        sort(val,0);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return sorted.top();
    }

    void sort(int val, int action){
        if(action==0){
            stack<int> temp;
            if(sorted.top()==val){
                sorted.pop();
            }else{
                while(!sorted.empty()){
                    if(sorted.top()!=val){
                        temp.push(sorted.top());
                        sorted.pop();
                    }else if(sorted.top()==val){
                        sorted.pop();
                        break;
                    }
                }
                while(!temp.empty()){
                    sorted.push(temp.top());
                    temp.pop();
                }
            }
            
        }else{
            if(sorted.empty()){
                sorted.push(val);
            }else{
                stack<int> temp;
                if(val<=sorted.top()){
                    sorted.push(val);
                }else{
                    while(!sorted.empty() && val>sorted.top()){
                        int tempVal = sorted.top();
                        temp.push(tempVal);
                        sorted.pop();
                    }
                    sorted.push(val);
                    while(!temp.empty()){
                        sorted.push(temp.top());
                        temp.pop();
                    }
                }
            }
        }
    }
};
