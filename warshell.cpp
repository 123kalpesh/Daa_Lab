#include<iostream>
using namespace std;


#define infi 99999
#define max 100
int n;
int adj[max][max];
int D[max][max];
int pre[max][max];

void createg();
void warshall();
void find_path(int s,int d);
void display(int mat[max][max],int n);

int main(){
	int s,d;
	createg();
	warshall();
	while(1){
	cout<<"Enter the source(-1) to exit: ";
	cin>>s;
	if(s==-1)
	break;
	cout<<"Enter destinaton vertex: ";
	cin>>d;
	if(s<0 || s>n-1||d<0 ||d>n-1){
	cout<<"Enter a valid vertex\n";
	continue;}
	cout<<"Shortest path is :";
	find_path(s,d);
	cout<<"Length of path is "<<D[s][d];
	return 0;
	}
	}
void createg(){
	int i,max_edges,o,d,wt;
	
	cout<<"Enter the number of vertices: ";
	cin>>n;
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++){
	cout<<"Enter the edge (-1 -1 to quit) "<<i<<":";
	cin>>o>>d;
	
	
	if((o==-1)&&(d==-1))
	break;
	cout<<"Enter the weight for this edge :";
	cin>>wt;
	
	if(o>=n||d>=n|o<0||d<0){
	cout<<"Invalid edge\n";
	i--;}
	else{
	adj[o][d]=wt;
	}
	}
	}
	
void warshall(){
	int i,j,k;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
	if(adj[i][j]==0){
	D[i][j]=infi;
	pre[i][j]=-1;
	
	}
	else{
	D[i][j]=adj[i][j];
	pre[i][j]=i;
	}}
	
	for(k=0;k<n;k++){
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(D[i][k]+D[k][j] <D[i][j]){
	D[i][j]=D[i][k]+D[k][j];
	pre[i][j]=pre[k][j];
	}
	}
	cout<<"Shortest path matrix is :\n";
	display(D,n);
	cout<<"Predecessor matrix is :\n";
	display(pre,n);
	
	
	}
	
void find_path(int s,int d){
	int i;
	int path[max];
	
	int count ;
	if(D[s][d]==infi){
	cout<<"No path";
	return;
	
	}
	count=-1;
	do{
	path[++count]=d;
	d=pre[s][d];
	}
	while(d!=s);
	path[++count]=s;
	for(i=count ;i>=0;i--)
	cout<<path[i];
	cout<<"\n";
	}
	
void display(int mat[max][max],int n){
	int i,j;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++)
	cout<<mat[i][j]<<" ";
	
	cout<<"\n";
	}
}
/*
svkm@svkm-VirtualBox:~$ cd Documents
svkm@svkm-VirtualBox:~/Documents$ cd SY_IT_54
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ g++ warshell.cpp 
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ ./a.out
Enter the number of vertices: 4
Enter the edge (-1-1 to quit) 1:0 1 
Enter the weight for this edge :2
Enter the edge (-1-1 to quit) 2:1 0
Enter the weight for this edge :3
Enter the edge (-1-1 to quit) 3:1 2
Enter the weight for this edge :4
Enter the edge (-1-1 to quit) 4:2 1
Enter the weight for this edge:6
Enter the edge (-1-1 to quit) 5:3 2
Enter the weight for this edge :4
Enter the edge (-1-1 to quit) 6:2 3
Enter the weight for this edge :2
Enter the edge (-1-1 to quit) 7:0 3
Enter the weight for this edge :9 
Enter the edge (-1-1 to quit) 8:3 0
Enter the weight for this edge :14
Enter the edge (-1-1 to quit) 9:1 3
Enter the weight for this edge :7
Enter the edge (-1-1 to quit) 10:-1 -1
Shortest path matrix is:
5 2 6 8
3 5 4 6
9 6 6 2
13 10 4 6
Predecessor matrix is:
1 0 1 2
1 0 1 2
1 2 3 2
1 2 3 2
Enter the source(-1) to exit: 3
Enter destinaton vertex: 0
Shortest path is : 3210
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ 
*/
