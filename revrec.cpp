#include<iostream>
#include<vector>
#include<string>

using namespace std;

void fact(int n,int ans){
    if(n<=1){
        cout<<ans;
        return;
    }
    ans=ans*n;
    (fact(n-1,ans));
}
int fib(int n){
    if(n==1){
        return 0 ;
    }
    if(n==2){
        return 1;
    }
    int ans=fib(n-1)+fib(n-2);
    return ans ;
}

void revcount(int n){
    if(n==1){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    revcount(n-1);
}
bool search(int arr[],int key, int i){
    if(i>=5){
        return false;
    }
    if(arr[i]==key)
        return true;
    int ans = search(arr,key,i+1);
    return ans;
}

void minnum(int arr[],int size,int i,int ans){
    if(i>=size){
        cout<<ans;
        return ;
    }
    if(ans>arr[i]){
        ans=arr[i];
    }
    minnum(arr,size,i+1,ans);
}
void printingdidgits(int n){
    if(n<=0){
        return ;
    }
    int rem=n%10;
    n=n/10;

    // for rev oreder
    // cout<<rem<<" " ;

    printingdidgits(n);

    // for real order 
    cout<<rem<<" " ;
}
bool checksort(int arr[],int size ,int i){
    if(i>=size-1){
        //  if we do it like i>=size 
        // then the compiller is auto nmatically assigning a value to the index out of bound index 
        // cout<<"true";
        return true ;
    }
    if(arr[i]>arr[i+1]){

        // cout<<arr[i+1];
        return false;
    }
    // cout<<i<<endl;
    return checksort(arr,size,i+1);

}
void binarysearch(int arr[], int size , int key , int s, int e){
    int mid =(s+e)/2;
    if(mid>=size ||mid<0){
        cout<<"not found ";
        return ;
    }
    if(arr[mid]==key){
        cout<<mid<<endl;
        return ;
    }
    if(arr[mid]<key){
        s=mid+1;
        binarysearch(arr,size,key,s,e);
    }
    else{
        e=mid;
        binarysearch(arr,size,key ,s,e);
    }
}

void subseq(string s, int i, string out ){
    if(i>=s.size()){
        cout<<out<<"  ";
        return ;
    }
    // excluded
    subseq(s,i+1,out);
    // included
    out.push_back(s[i]);
    subseq(s,i+1,out);
}

int solve(int n, int x, int y, int z){
    if(n<=0){
        return 0;
    }
    int opt1=1+solve(n-x,x,y,z);
    int opt2=1+solve(n-y,x,y,z);
    int opt3=1+solve(n-z,x,y,z);
    
    return max(opt1,max(opt2,opt3));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int ans =solve(n,x,y,z);
    return ans;

}

void merge(int a[], int s, int e){
    if(s>=e)
        return ;
    int mid =(s+e)/2;
    int ll=mid-s+1;
    int lr=e-mid;

    // coping the values in respective arrays;
    int * lefta=new int[ll];
    int * righta=new int[lr];
    int k=s;

    // copying 
    for(int i=0;i<ll;i++){
        lefta[i]=a[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<lr;i++){
        righta[i]=a[k];
        k++;
    }
    int m = 0;
    int n = 0;
    int st=0;

    while( m<ll &&n <lr){
        if(lefta[m]<righta[n]){
            a[st++]=lefta[m];
            m++;
        }
        else{
            a[st++]=righta[n];
            n++;
        }
    }
    while(n<lr){
        a[st]=righta[n];
        st++;
        n++;
    }

    while(m<ll){
        a[st]=lefta[m];
        st++;
        m++;
    }
    

    delete [] lefta;
    delete [] righta;


}

// merge sort 
void mergesort(int arr[], int s, int e){
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
// printing sub sequence of a string 

void subseq(string s){
    int n =s.length();
    for(int i=0;i<pow(2,n);i++){
        int k=i;
        string out ="";
        int j=0;
        while(k){
            int bit=(k&1);
            if(bit){
                out.push_back(s[j]);
                j++;
            }
            else{
                j++;
            }
            k>>=1;
        }
        cout<<out<<endl;
    }
}

// void permutation odf a string 
void permu(string s, int ind){
    if(ind>=s.length()){
        cout<<s<<endl;
        return ;
    }

    for(int j=ind;j<s.length();j++){
        swap(s[j],s[ind]);
        permu(s,ind+1);
        swap(s[j],s[ind]);
    }

}


int main(){
    // int n=4;
    // fact(n,1);
    // int ans=fib(n+1);
    // cout<<ans ;
    // revcount(n);

    // int arr[5]={1,2,3,4,5};
    // bool ans=search(arr,,0);
    // cout<<ans;

    // int arr[5]={5,3,7,10,9};
    // int ans=INT_MAX;
    // minnum(arr,5,0,ans);
    // int n=123;
    // printingdidgits(n);

    // int arr[5]={1,2,3,45,50222};
    // bool ans =checksort(arr,5,0);
    // cout<<ans;


    // int arr[5]={0,2,3,4,5};
    // int size=5;
    // int s=0;
    // int e=size-1;
    // int key=0;
    // binarysearch(arr,size,key,s,e);

    // string s="abc";
    // string out ="";
    // subseq(s,0,out);

    // int n=6,x=3,y=5,z=4;
    // int nas=maximizeTheCuts(n,x,y,z);
    // cout<<nas;

    // int arr[6]={1,4,2,5,3,6};
    // mergesort(arr,0,5);

    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }

    string s="abc";
    // subseq(s);

    permu(s,0);




}