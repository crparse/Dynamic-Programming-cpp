//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
   long long p(int arr[], int paint, int n ){
    int num=1, paint_count=0;
    for(int i=0; i<n; i++){
        if(paint_count+arr[i]<=paint){
            paint_count+=arr[i];
        }    
        else{
            num++;
            paint_count=arr[i];
        }
    }
    
    return num;
       
  }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        int low=0;
        long long high=0;
        for(int i=0; i<n; i++){
            high+=arr[i];
            low=max(low,arr[i]);
        }
        while(low<=high){
            long long mid=(low+high)/2;
            int p_count=p(arr,mid,n);
            if(p_count>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }    
        }
    
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends