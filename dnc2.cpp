#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printper(string &str, int index){
    if(index>=str.length()){
        cout<<str<<endl;
        return;
    }

    for(int j= index;j<str.length();j++){
        swap(str[j],str[index]);
        // recurssion
        printper(str,index+1);
        // backtracking (to nullify the changes)
        swap(str[j],str[index]);

    }
}

// making a function to check whether the nex cordinate to visit is safe or not
    // check out of bound 
    // pos alredy visited
    // not open to go (0)
bool issafevisit(vector<vector<bool> > visited,int nx,int ny, int maze[][4], int row, int col){
    // door not open
    if((maze[nx][ny]==1)&&(visited[nx][ny]!=true)&&(nx>=0&&nx<row)&&ny>=0 && ny<col){
        return true;
    }
    return false;

}

// rat in a maze 
void ratinamaze(int maze[][4] ,int row,int col, int sx , int sy, string out,vector<vector<bool> >& visited ){
    if(sx==row-1 && sy==col-1){
        cout<<out<<endl;
        return ;
    }
    // right 
    int nx=sx;
    int ny=sy+1;
    if(issafevisit(visited,nx,ny,maze,row,col)){
        // marking the path 
        visited[nx][ny]=true;
        // recurssion
        ratinamaze(maze,row,col,nx,ny,out+'R',visited);
        // backtracking 
        visited[nx][ny]=false;

    }
    // left
    nx=sx;
    ny=sy-1;
    if(issafevisit(visited,nx,ny,maze,row,col)){
        visited[nx][ny]=true;
        ratinamaze(maze,row,col,nx,ny,out+'L',visited);
        visited[nx][ny]=false;

    }
    // down
    nx=sx+1;
    ny=sy;
    if(issafevisit(visited,nx,ny,maze,row,col)){
        visited[nx][ny]=true;
        ratinamaze(maze,row,col,nx,ny,out+'D',visited);
        visited[nx][ny]=false;
    }
    
    // up
    nx=sx-1;
    ny=sy;
    if(issafevisit(visited,nx,ny,maze,row,col)){
        visited[nx][ny]=true;
        ratinamaze(maze,row,col,nx,ny,out+'U',visited);
        visited[nx][ny]=false;
    }
 
}

int main(){

    // string s="abc";
    // printper(s,0);
    // int maze[][4]={
    //     {1,0,0,0},
    //     {1,1,0,0},
    //     {1,1,1,0},
    //     {1,1,1,1}
    // };
    // int row=4;
    // int col=4;
    // vector<vector<bool> > visited(row,vector<bool>(col,false));
    // string out="";
    // if(maze[0][0]==0){
    //     cout<<"nope ";
    // }
    // else{
    //     visited[0][0]=true;
    //     ratinamaze(maze,row, col,0,0,out,visited);
    // }


    // 1.allocating memory in the heap (int )

    // method 1 using new 
    // int *ptr1=new int(78);
    // cout<<*ptr1<<endl;   

    // // method 2 without using new 

    // void *pttr=malloc(4);  //malloc(x) allocate x bytes of memmory in the haep but as it doesnt know the type of data 
    // stored in it therefore it returns the address using a void pointer ;

    // int *ptr2=(int *)pttr;
    // OR
    // int*ptr2=(int *)malloc(4);
    // *ptr2=908;
    // cout<<*ptr2<<endl;

    // delete ptr1;
    // free(ptr2)

    // // 2.allocating the 1D array in heap
    // int *arr1=new int[5];
    
    // int*arr2=(int *)malloc(20);
    
    // for(int i=0;i<5;i++){
    //     arr1[i]=i+3;
    //     arr2[i]=i+5;
    // }
    // for(int i =0;i<5;i++){
    //     cout<<arr1[i]<<"  "<<arr2[i]<<endl;
    // }
    // delete[] arr1;
    // free(arr2);

    // 3. allocationg 2D array 
    int norow=5,nocol=4;
    int **arr1=new int*[norow];
    for(int i=0;i<norow;i++){
        arr1[i]=new int[nocol];
    }

    int **arr2=(int**)malloc(sizeof(int*)*norow);
    for(int i=0;i<norow;i++){
        arr2[i]=(int *)malloc(sizeof(int)*nocol);
    }
    int k=3;
    for(int i=0;i<norow;i++){
        for(int j=0;j<nocol;j++){
            arr1[i][j]=k+3;
            arr2[i][j]=k+2;

        }
    }
    for(int i=0;i<norow;i++){
        for(int j=0;j<nocol;j++){
            cout<<arr1[i][j]<<endl;
            cout<<arr2[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<norow;i++){
        delete [] arr1[i];
        free(arr2[i]);
    }
    delete []arr1;
    free(arr2);






}