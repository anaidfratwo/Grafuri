#include<iostream>
using namespace std;

/*
BFS:
1. vizitam nodul sursa
2. vizitam vecinii

*/

struct Node{
    int val;
    Node *next;
};

//functie care pune in coada nodurile care urmeaza sa fei vizitate

void enqueue(Node **head, int val){
    if(*head==nullptr){
        *head=new Node();
        (*head)->val=val;
    }else{
        Node *iter=*head;
        while(iter->next != nullptr){
            iter=iter->next;
        }
        iter->next=new Node();
        iter->next->val=val;
        iter->next->next=nullptr;
    }
}

//functia care scoate un element din coada

int dequeue(Node **head){
    int rez= (*head)->val;
    Node *temp = *head;
    *head = (*head)->next;
    delete temp;
    return rez;
}


int peek(Node *head){
    return (head)->val;
}

bool isEmpty(Node *head){
    return head==nullptr;
}

void printQueue(Node **head){
    Node *iter=*head;
    while(iter != nullptr){
        cout<<iter->val<<" ";
        iter=iter->next;
    }
}

//BFS param: graph - matricea de adiacenta, n - nr de noduri, start - nodul de start

void BFS(int **graph, int n, int start){
     Node *queue=nullptr;
     bool *visited=new bool[n];

     for(int i=0;i<n;i++){
        visited[i]=false;
     }

     enqueue(&queue,start);
     visited[start]=true;
     
     while(!isEmpty(queue)){
        int currentNode=dequeue(&queue);
        cout<<currentNode<<" ";

         for(int i=0;i<n;i++){
           if(graph[currentNode][i] == 1 && !visited[i]){
              enqueue(&queue,i);
              visited[i]=true;
           }
        }
     }
    delete[] visited;
    
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

    cout<<"introduceti nodul de start:";
    cin>>nodStart;

    BFS(graph,n,nodStart);

    for(int i=0;i<n;i++){
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}