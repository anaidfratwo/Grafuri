#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

void push(Node **top, int val){
    Node *n=new Node();
    n->val=val;
    n->next=*top;
    *top=n;
}

int pop(Node **top){
    if(*top != nullptr){
        Node *temp=*top;
        int rezultat=(*top)->val;
        *top=(*top)->next;
        delete[] top;
        return rezultat;
    }
    return -1;
}

int peek(Node **top){
    if(top != nullptr){
        return (*top)->val;
    }
}

int isEmpty(Node *top){
    return top==nullptr;
}

void DFS(int **graph, int n,int start){
    Node *stack=nullptr;
    bool *visited=new bool[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    push(&stack,start);
    visited[start]=true;

    while(!isEmpty(stack)){
        int currentNode = pop(&stack);
        cout<<currentNode<<" ";
        for(int i=0;i<n;i++){
            if(graph[currentNode][i]==1 && !visited[i]){
                push(&stack, i);
                visited[i]=true;
            }
        }
    }
}

int main(){

    int n, nodStart;
    cin>>n;

    int **graph=new int*[n];
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    DFS(graph,n,nodStart);

    cout<<"Introduceti nodul de strat:"<<endl;

    cin>>nodStart;

    

    for(int i=0;i<n;i++){
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}