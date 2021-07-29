// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    
struct Node
{
int data;
Node *left;
Node *right;


Node(int x)
{
data = x;
left = right = NULL;
}
};

// To compare two points
struct compare {

bool operator()(Node* l, Node* r)

{
return (l->data > r->data);
}
};

void preOrder(vector<string> &res, Node *root, string s)
{
if (!root)
return;

if ( !root->left && !root->right)
res.push_back(s);
preOrder(res, root->left , s + "0");
preOrder(res, root->right , s + "1");
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
priority_queue<Node*,vector<Node*>,compare> pq;

for (int i = 0; i < f.size(); i++)
{
Node *temp = new Node(f[i]);
pq.push(temp);
}

vector<string> res;
for (int i = 1; i < N; i++)
{
Node *x = pq.top();
// cout << x << endl;
pq.pop();
Node *y = pq.top();
// cout << y << endl;
pq.pop();

Node *temp = new Node(x->data + y->data);
temp->left = x;
temp->right = y;
pq.push(temp);
}

preOrder(res, pq.top() , "");
return res;
}
		    
		    
            
                
		    // Code here
		
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends