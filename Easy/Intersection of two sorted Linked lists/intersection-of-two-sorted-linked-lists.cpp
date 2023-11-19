//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node* newHead = new Node(-1);
        Node* head = newHead;
        Node* h1 = head1;
        Node* h2 = head2;
        unordered_map<int,int> mp;
        int sz =0;
        while(h1 != NULL){
            mp[h1->data]++;
            h1 = h1->next;
            sz++;
        }
        int cnt =0;
        while(h2 != NULL){
            if(mp.find(h2->data) != mp.end()){
                int tmp = h2->data;
                mp[tmp]--;
                if(mp[tmp] == 0)mp.erase(tmp);
                cnt++;
                Node* temp = new Node(tmp);
                newHead->next = temp;
                newHead = newHead->next;
                if(cnt == sz)break;
            }
            h2 = h2->next;
        }
    
        return head->next;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends