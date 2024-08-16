#include<iostream>
#include<fstream>
using namespace std;


/*
Se dau listele de adiacenta a unui graf neorientat cu n noduri.
Sa se genereze matricea de adaicenta.
Fiecare lista de adiacenta se citeste pana la -1.

N=5

0: 3,4
1: 2,3 
2: 1,3,4
3: 0,1,2
4: 0,2
*/

struct Node{
   int val;
   Node *next;
};

void addLast(Node **head, int val){
    if(*head==nullptr){
        Node* n=new Node();
        n->val=val;
        n->next=nullptr;
        *head=n;
    }else{
       Node *iter = *head;
       while(iter->next != nullptr){
           iter = iter->next;
       }
       Node *n=new Node();
       n->next=nullptr;
       n->val=val;
       iter->next=n;
    }
}


int main(){


    int n;
    cin>>n;

    int **g = new int*[n];
    for(int i=0;i<n;i++){
        g[i]=new int[n];
    }
    

    //initializam matricea cu 0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }

    Node **liste_adiacenta = new Node*[n];
    for(int i=0;i<n;i++){
        liste_adiacenta[i]=nullptr;
    }

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(x != -1){
            g[i][x]=1;
            cin>>x;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}