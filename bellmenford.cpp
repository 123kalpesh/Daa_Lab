#include<iostream>
using namespace std;
#define MAX 100
#define infinity 999
#define NIL -1
#define TRUE 1
#define FALSE 0


int n; //number of vertices
int adj[MAX][MAX];
int pred[MAX];
int pathLength[MAX];
int isPresent_in_queue[MAX];
int front,rear;
int queue[MAX];
void initialize_queue();
void insert_queue(int u);
int delete_queue();
int isEmpty_queue();
void create_graph();
void findPath(int s, int v);
int BellmanFord(int s);

int main(){
  int flag , s , v;
  create_graph();
  cout<<"Enter the source vertex: ";
  cin>>s;
  flag = BellmanFord(s);
  if(flag == -1){
    cout<<"Error : Negative cycle in graph\n";
  }
  while(1){
    cout<<"Enter the destination vertex(-1 to quit) :";
    cin>>v;
    if(v == -1)
       break;
    if(v<0 || v>=n)\
       cout<<"This vertex does not exist\n";
    else if(v == s)
       cout<<"Source and destination vertices are same\n";
    else if(pathLength[v] == infinity)
        cout<<"There is no path from source to destination vertex\n";
    else
        findPath(s,v);
  }
}

void create_graph() {
    int i, max_edges, origin, destin, wt;
    cout << "Enter the number of vertices: ";
    cin >> n;

    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        cout << "Enter edge " << i << " (enter -1 -1 to finish): ";
        cin >> origin >> destin;

        if (origin == -1 && destin == -1)
            break;

        cout << "Enter weight of this edge: ";
        cin >> wt;

        if (origin > n || destin > n || origin < 0 || destin < 0) {
            cout << "Invalid edge! Please enter again." << endl;
            i--;
        } else
            adj[origin][destin] = wt;
    }
}

void findPath(int s, int v){
   int i,u;
   int path[MAX]; //stores the shortest path
   int shortDist = 0; //length of shortest path
   int count = 0; // number of vertices in the shortest path
   // store the full path in the array path
   while(v != s){
    count++;
    path[count] = v;
    u = pred[v];\
    shortDist = shortDist + adj[u][v];
    v = u;
   }
   count++;
   path[count] = s;
   cout<<"Shortest path is :";
   for(int i = count; i>= 1 ; i--)
       cout<<path[i]<<" ";
   cout<<"\nShortest distance is :"<<shortDist<<endl;
}

int BellmanFord(int s){
    int k=0,i,current;
    for(i=0;i<n;i++){
        pred[i] = NIL;
        pathLength[i] = infinity;
        isPresent_in_queue[i] = FALSE;
    }
    initialize_queue();
    pathLength[s] = 0; //make path length of source vertex 0
    insert_queue(s); // insert the source vertex in queue
    isPresent_in_queue[s] = TRUE;

    while(!isEmpty_queue()){
        current = delete_queue();
        isPresent_in_queue[current] = FALSE;
        if(s == current)
            k++;
        if(k>n)
            return -1; //negative cycle reachable from source vertex

        for(int i=0; i<n ; i++){
            if(adj[current][i] != 0)
            if(pathLength[i] > pathLength[current] + adj[current][i]){
                pathLength[i] = pathLength[current] + adj[current][i];
                pred[i] = current;
                if(!isPresent_in_queue[i]){
                    insert_queue(i);
                    isPresent_in_queue[i] = TRUE;
                }
            }
        }
    }
    return 1;
}

void initialize_queue(){
   int i;
   for(i=0; i<MAX ; i++)
      queue[i] = 0;
   rear = -1;
   front =-1;
}

int isEmpty_queue(){
   if(front == -1 || front > rear)
       return 1;
   else
       return 0;
}

void insert_queue(int added_item){
     if(rear == MAX-1){
        cout<<"Queue Overflow\n";
        exit(1);
     }
     else{
        if(front == -1) //if queue is initially empty
            front = 0;
        rear = rear + 1;
        queue[rear] = added_item;
     }
}

int delete_queue(){
    int d;
    if(front == -1 || front > rear){
        cout<<"Queue is Underflow\n";
        exit(1);
    }
    else{
        d = queue[front];
        front = front + 1;
    }
    return d;
}
/*svkn@svkm-VirtualBox: $ cd Documents
svkn@svkm-VirtualBox:~$ cd SY_IT_54
svkn@svkm-VirtualBox:~/Documents/SY_IT_54$ g++ bellmenford.cpp
svkn@svkm-VirtualBox:~/Documents/SY_IT_54$ ./a.out
Enter the number of vertices: 5 
Enter edge 1 (enter 1-1 to finish): 1 0
Enter weight of this edge: 6
Enter edge 2 (enter 1-1 to finish): 1 2
Enter weight of this edge: 5
Enter edge 3 (enter 1-1 to finish): 2 3 
Enter weight of this edge: 4
Enter edge 4 (enter 1-1 to finish): 6 4
Enter weight of this edge: 7
Enter edge 5 (enter 1-1 to finish): 2 4
Enter weight of this edge: -3
Enter edge 6 (enter 1-1 to finish): -1 -1 
Enter the source vertex: 1
Enter the destination vertex(-1 to quit): 4
Shortest path is 1 2 4
Shortest distance is :2
Enter the destination vertex(-1 to quit): 3
Shortest path is 1 2 3 Shortest distance is :1
Enter the destination vertex(-1 to quit) */
