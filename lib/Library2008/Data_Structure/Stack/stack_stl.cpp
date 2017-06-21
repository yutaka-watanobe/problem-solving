#include<iostream>
//begin_of_source
#include<stack>

using namespace std;

main(){
    stack<int> st;
    st.push(1);
    st.push(7);
    st.push(3);
    cout << st.top() << endl; st.pop();
    cout << st.top() << endl; st.pop();
    st.push(5);
    cout << st.top() << endl; st.pop();
    cout << st.top() << endl; st.pop();
}
//end_of_source
