#include<iostream>
#include<fstream>
using namespace std;



/*

Se da matricea de adiacenta a unui graf neorientat cu N= nr de noduri. Sa se afiseze listele de adiacenta.

0 0 0 1 1
0 0 1 1 0
0 1 0 1 1
1 1 1 0 0
1 0 1 0 0


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

void printList(int index, Node *head){
    Node *iter=head;
    cout<<index<<": ";
    while(iter != nullptr){
        cout<<iter->val<<" ";
        iter=iter->next;
    }
    cout<<endl;
}

int main(){
   
    //CITIM MATRICEA

    int n=5;
   
        
        //alocam memorie pt graf
    
    int **g=new int*[n];
    for(int i=0;i<n;i++){
        g[i]=new int[n];
    }
    
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    
    Node **liste_adiacenta = new Node*[n];
    for(int i=0;i<n;i++){
        liste_adiacenta[i]=nullptr;
    }

    cout<<"liste de adiacenta:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] == 1){
               addLast(&(liste_adiacenta[i]),j);
            }
        }
    }

    
    //printare liste adiacenta

    for(int i=0;i<n;i++){
        printList(i,liste_adiacenta[i]);
    }

    

    for(int i = 0; i < n; i++) {
        delete[] g[i];
    }
    delete[] g;

    return  0;
}