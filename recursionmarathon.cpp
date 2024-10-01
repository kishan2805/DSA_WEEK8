#include<iostream>
#include<string>
#include<vector>
using namespace std;



int ans(vector<int>& nums,int s , int e){
    if(s>e){
        return 0;
    }
    int opt1=nums[s]+ans(nums,s+2,e);
    int opt2=0+ans(nums,s+1,e);

    int final=max(opt1,opt2);
    return final;
}
int rob(vector<int>& nums) {
    int start=0;
    int end=nums.size()-1;
    // single elemnt wala case miss hogaya tha 
    if(nums.size()==1){
        return nums[0];
    }
    int opt1=ans(nums,start,end-1);
    int opt2=ans(nums,1,end);
    return max(opt1,opt2);
    
}
int countder(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    int ans=(n-1)*(countder(n-1)+countder(n-2));
    return ans;
}
// painting fence 
int paint(int n,int k){
    if(n==1)
        return k;
    
    if(n==2)
        return k+ (k*(k-1));
    int ans=(k-1)*(paint(n-1,k)+paint(n-2,k));
    return ans;
}

int solvemaxi(vector<vector<char>>&matrix,int i, int j, int &row, int &col , int &maxi){
        // base 
    if(i>=row || j>=col){
        return 0;
    }
    int right=solvemaxi(matrix,i,j+1,row,col,maxi);
    int down=solvemaxi(matrix,i+1,j,row,col,maxi);
    int diag=solvemaxi(matrix,i+1,j+1,row,col,maxi);

    if(matrix[i][j]=='1'){
        int ans=1+min(right,min(down,diag));
        maxi=max(maxi,ans);
        return ans;
    }
    else
        return 0;
}
int maximalSquare(vector<vector<char>>& matrix) {
    int i =0;
    int j=0;
    int maxi=0;
    int row=matrix.size();
    int col=matrix[0].size();
    int ans=solvemaxi(matrix,i,j,row,col,maxi);
    return maxi*maxi;
}



int main(){
    // adjacent element sum
    // int arr[]={2,1,3,5,4,7,6,8};

    // house robber 2(leet 213)
    // vector<int>nums;
    // nums.push_back(2);
    // nums.push_back(5);
    // nums.push_back(8);
    // nums.push_back(1);
    // nums.push_back(6);
    // nums.push_back(4);
    // nums.push_back(3);
    // int ans=rob(nums);
    // cout<<ans;

    // count the dearrangement 
    // int n=4;
    // int ans=countder(n);
    // cout<<ans<<endl;

    // painting the fence
    // int m=3,k=3;
    // int ans =paint(m,k);
    // cout<<ans<<endl;

    // maximum size square
    

}