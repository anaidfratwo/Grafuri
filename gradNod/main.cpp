#include<iostream>
#include<fstream>
using namespace std;



int main(){

    /*

    conversieLM
    conversieML
    gradNod
    
Se da matricea de adiacenta a unui graf neorientat.
Sa se determine gradul fiecarui nod.

0 0 0 0 1
0 0 0 1 0
0 1 0 1 1
1 1 0 0 0
1 0 1 0 0

Graf neorientat: Conexiunile nu au direcție, astfel că atât intrările, cât și ieșirile sunt echivalente și se numără liniile din matricea de adiacență.
Graf orientat: Conexiunile au direcție. Pentru gradul intern se numără coloanele (intrările), iar pentru gradul extern se numără liniile (ieșirile) din matricea de adiacență.




*/

    int n=5;
    int **g=new int*[n];
    for(int i=0;i<n;i++){
        g[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    int *v=new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if(g[i][j] == 1){
            //     v[j]+=1;
            // }
            v[j]+=g[i][j];
        }
    }

    cout<<endl;
    cout<<"ex 1:"<<endl;
    for(int i=0;i<n;i++){
        //cout<<v[i]<<" ";
        cout<<i<<"->"<<v[i]<<endl;
    }
    
    cout<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

    /*
    ex: Se da matricea de adiacenta a unui graf cu n noduri si o secventa de k noduri. Sa se determine daca cele k
    noduri formeaza un lant.
    */

    cout<<endl;
    cout<<"ex 2:"<<endl;

    int k;
    cin>>k;
    bool esteLant=true;

    int *w=new int[k]();

    //citim nodurile despre care vrem sa stim daca sunt lant
    /*
       k = 4;
       w = [0 4 2 1];
    */
    for(int i=0;i<k;i++){
        cin>>w[i];
    }
    
    for(int i=0;i<k-1;i++){
        if(g[w[i]][w[i+1]] == 0){
            esteLant=false;
        }
    }
    cout<<endl;
    
if(esteLant){
    cout<<"DA"<<endl;
}else{
    cout<<"NU"<<endl;
}

    return 0;
}