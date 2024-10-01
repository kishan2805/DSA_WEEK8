#include<iostream>
#include<string>
using namespace std;

void merge(int arr[],int s , int e ){
    int mid=(s+e)/2;
    int lenl=mid-s+1;
    int lenr=e-mid;

    int *left=new int[lenl];
    int *right=new int[lenr];
    //  copying the left part 
    int k =s;
    for (int i=0;i<lenl;i++){
        left[i]=arr[k];
        k++;
    }
    // copying the right part
    k=mid+1;
    for (int i=0;i<lenr;i++){
        right[i]=arr[k];
        k++;
    }
    // actual sorting 
    int a=0;   // start of left array 
    int b=0;  // start of left right array
    int st=s; //starting index of the main array 

    // for (int i=0;i<=e;i++){
    //     if(left[a]<=right[b]){
    //             arr[s++]=left[a];
    //             a++;
    //     }
    //     else{
    //         arr[s++]=right[b];
    //         b++;
    //     }
    // }

    while(a<lenl && b<lenr){
        if (left[a]<right[b]){
            arr[st]=left[a];
            a++;
            st++;
        }
        else{
            arr[st]=right[b];
            b++;
            st++;
        }
    }
    while(b<lenr){
        arr[st]=right[b];
        b++;
        st++;
    }
    while(a<lenl){
        arr[st]=left[a];
        a++;
        st++;
    }
    delete[] left;
    delete[] right;


}

void mergersort(int a[],int s , int e ){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    // recursive call on left part 
    mergersort(a,s,mid);
    // recurssive call on right part 
    mergersort(a,mid+1,e);
    // merge the sorted array 

    merge(a,s,e);
}
// climbing stairs 
int climb(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    // single step
    int ans1=climb(n-1);
    // double step 
    int ans2=climb(n-2);
    return ans1+ans2;
}
// substring of a string 
void sub(string s){
    int n =s.size();

    for (int i=0; i<pow(2,n);i++){

        int k=i;
        string out;
        int j=0;

        while(k){
            int bit=(k&1);
            if(bit){
                out.push_back(s[j++]);
            }
            else{
                j++;
            }
            k>>=1;
        }
        cout<<out<<endl;

    }
}

// quick sort 
void quick(int arr[],int start, int end ){
    if(start>=end){
        return;
    }
    int pivot =end;
    int i=start-1;
    int j=start;
    while(j<pivot){
        if(arr[j]<arr[pivot]){
            ++i;
            swap(arr[j],arr[i]);
        }
        ++j;
    }
    ++i;
    swap(arr[i],arr[pivot]);
    quick(arr,start,i-1);
    quick(arr,i+1,end); 
}


int main(){
    // int arr[]={2,4,1,5,6,8};
    // int s = 0;
    // int e =5;
    // merge sort 

    // mergersort(arr,s,e);
    // for (int i=0;i<=e;i++){
    //     cout<<arr[i]<<endl;
    // } 


    // climbing stairs 

    // int n =5;
    // int ans =climb(n);
    // cout<<ans;

    // printing substring 
    // string s="abc";
    // sub(s);

    int arr[]={2,4,3,1,6,5,8};
    int start=0;
    int end =6;
    quick(arr,start,end);

    for(int i =0; i<7;i++){
        cout<<arr[i]<<"  ";
    }

    


}