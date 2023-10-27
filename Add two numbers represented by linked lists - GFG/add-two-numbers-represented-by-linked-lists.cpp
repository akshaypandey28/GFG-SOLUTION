//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        vector<int> a,b,ans;
        Node* temp=first;
        while(temp!=NULL){
            a.push_back(temp->data);
            temp=temp->next;
        }
        temp=second;
        while(temp!=NULL){
            b.push_back(temp->data);
            temp=temp->next;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        int rem=0;
        while(i<a.size() && j<b.size()){
            int add=a[i]+b[j]+rem;
            ans.push_back(add%10);
            rem=add/10;
            i++,j++;
        }
        if(i==a.size() && j==b.size() && rem!=0){
            ans.push_back(rem);
            i++;
            j++;
        }
        while(i<a.size()){
            int add=a[i]+rem;
            ans.push_back(add%10);
            rem=add/10;
            i++;
            if(i==a.size() && rem!=0){
            ans.push_back(rem);
            }
        }
        
        
        while(j<b.size()){
            int add=b[j]+rem;
            ans.push_back(add%10);
            rem=add/10;
            j++;
            if(j==b.size() && rem!=0){
            ans.push_back(rem);
            }
        }
        
        reverse(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        return NULL;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends