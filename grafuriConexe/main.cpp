#include<iostream>
using namespace std;


/*

Se da matricea unui graf neconex. Sa se numere cate componente conexe are graful.

//matricea de adiacenta a unui graf neconex

0 0 1 0 0 0 0 0 0 
0 0 1 0 0 0 0 0 0
1 1 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 0 0 0 1 0 1 1
0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 1 0


*/

struct Node{
    int val;
    Node* next;
};

void enqueue(Node **head, int val){
    if(*head == nullptr){
        *head=new Node();
        (*head)->val = val;
        (*head)->next = nullptr;
    }else{
        Node *iter=*head;
        while(iter->next != nullptr){
             iter = iter->next;
        }
        iter->next = new Node();
        iter = iter->next;
        iter->next = nullptr;
        iter->val = val;
    }
}

int dequeue(Node **head){
    if(*head == nullptr){
        return -1;
    }
    Node *temp = *head;
    *head=(*head)->next;
    int rezultat = temp->val;
    delete temp;
    return rezultat;
}

bool isEmpty(Node *head){
   return head==nullptr;
}


void BFS(int **graph,int n, int nodStart,bool *visited){
    Node *coada=nullptr;
    

    enqueue(&coada,nodStart);
    visited[nodStart]=true;

    while(!isEmpty(coada)){
       int currentNode=dequeue(&coada);
       cout<<currentNode<<" ";

       for(int i=0;i<n;i++){
          if(graph[currentNode][i] == 1 && !visited[i]){
             enqueue(&coada, i);
             visited[i]=true;
          }
       }
    }
    cout<<endl;
}

bool visitedAll(bool *visited, int n){
    for(int i=0;i<n;i++){
        if(!visited[i])//daca exista un nod nevizitat
           return false;
    }
    return true;
}

int main(){

    int n, nodStart;
    cin>>n;
    int **g = new int*[n];
    for(int i=0;i<n;i++){
        g[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    int conexe=0;

    while(!visitedAll(visited,n)){
         for(int i=0;i<n;i++){
            if(!visited[i]){
                nodStart=i;
                break;
            }
         }
         BFS(g,n,nodStart,visited);
         conexe+=1;
    }
    
   cout<<"Componente conexe:"<<conexe;

    for(int i=0;i<n;i++){
        delete[] g[i];
    }
    delete[] g;


    return 0;
}