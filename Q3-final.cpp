#include<iostream>
#include<vector>
#include <sstream>
#include <iterator>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k>n){
        	return 0;
		}
		//create 2d array
        vector<vector<int>> after(2,vector<int>(k+1,0)); //2 as it has only either buy or sell
        vector<vector<int>> cur(2,vector<int>(k+1,0)); // 2 rows and k+1 columns
        
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    long profit;
                    if(buy == 1){
                        profit = max(-prices[i]+after[0][cap],after[1][cap]);
                    }else{
                        profit = max(prices[i]+after[1][cap-1],after[0][cap]);
                    }

                    cur[buy][cap] = profit;
                }
            }
            
            after= cur;
        }
        
        return cur[1][k];
    }


int main(){
    string input;
    cout<<"Enter price values: like(1 2 3 4..)"<<endl;
    getline( cin, input );
    istringstream is( input );
    vector<int> v( (istream_iterator<int>( is ) ),istream_iterator<int>() );
    int n;
    cout<<"Enter no of transactions allowed"<<endl;
    cin>>n;
    int ans = maxProfit(n,v);
    cout<<"Max price possible is "<<ans<<endl;
    return 0;
}
