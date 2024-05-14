#include<iostream>
using namespace std;
#define MAX 100
#define initial 1
#define visited 2
int n;  /*number of nodes in graph */
int adj[MAX][MAX];   /* Adjancy matrix */
int state[MAX];   /*can be initial or visited*/
void DF_Traversal();
void DFS(int v);
void create_graph();
int stack[MAX];
int top=-1;
void push(int v);
int pop();
int isEmpty_stack();
int main()
{
   create_graph();
   DF_Traversal();
}  /*End of main*/

void DF_Traversal()
{
    int v;
    for(v=0; v<n; v++)
        state[v]=initial;
        cout<<"Enter the starting node for dfs:  ";
        cin>>v;
        DFS(v);
}  /* End of DF_Traversal()*/

void DFS(int v)
{
  int i;
  push(v);
  while(!isEmpty_stack())
  {
      v=pop();
      if(state[v]==initial)
      {
          cout<<v;
          state[v]=visited;
      }
      for(i=n-1; i>0; i--)
      {
        if(adj[v][i]==1&& state[i]==initial)
           push(i);
      }
   }
  }/*End of DFS*/
  
  
  void push(int v)
  {
     if(top==(MAX-1))
     {
       cout<<"stack overflow";
       return;
     }
     top=top+1;
     stack[top]=v;
  }  /* end of push()*/
  
  int pop()
  {
    int v;
    if(top==-1)
    {
      cout<<"Stack underflow";
      exit(1);
    }
    else
    {
       v=stack[top];
       top=top-1;
       return v;
    }
  }/*End of pop*/
   
   int isEmpty_stack()
   {
     if(top==-1)
     return 1;
     else
      return 0;
   }/*End of isEmpty_stack() */
            
void create_graph()
{
    int max_e,i,origin,destin;
cout<<"enter  number of nodes :"<<endl;
cin>>n;
max_e=n*(n-1);
for(i=0;i<max_e;i++)
{
cout<<"enter the origin and destination of graph"<<endl;
cin>>origin>>destin;
if((origin==-1)&&(destin==-1))
  break;
if(origin>=n|| destin>=n || origin<0 || destin<0)
{
    cout<<"Invalid edge";
    i--;
}
else
 adj[origin][destin]=1;
 }
} /* End of creat_graph()*/
/*svkm@svkm-VirtualBox:~$ cd Documents
svkm@svkm-VirtualBox:~$ cd SY_IT_54 
svkm@svkm-VirtualBox:~/DocumentX/SY_IT_54$ g++ dfs.cpp
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ ./a.out
enter number of nodes:
3 
enter the origin and destination of graph
0 
0
enter the origin and destination of graph
0 
1
enter the origin and destination of graph
0
2
enter the origin and destination of graph
1
1
enter the origin and destination of graph
1
2
enter the origin and destination of graph
2
0
Enter the starting node for dfs: 0
012
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$*/

