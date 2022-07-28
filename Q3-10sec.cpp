
#include<iostream>
#include<vector>
#include<ctime>
#include <sstream>
#include <iterator>
using namespace std;

int main() {
    string input;
    cout<<"Enter price values: like(1 2 3 4..)"<<endl;
    getline( cin, input );
    istringstream is( input );
    vector<int> v( (istream_iterator<int>( is ) ),istream_iterator<int>() );
    int profit = 0;
    int n;
    int sec= 10;
	cout<<"Enter the Max transactions allowed"<<endl;
    cin>>n; //Number of transactions
    vector<int>::iterator i1 = v.begin();
    time_t start, finish; //time paramaters
    char option = 'n';
    int buy,sell; //value parameters
    while(i1<v.end() and n!=0){
    	time(&start); //timer start
    	if(option =='n'){
    		cout<<"price is "<<*i1<<endl;
    		cout<<"Buy Now? y/n"<<endl;
    		while(difftime(finish, start)<= sec){
    			cin>>option;
    			if(option=='y'){ //buy stock
    			buy = *i1;
    			i1++;
    			break;
				}
				else if(option=='n') { //don't buy
				break;
				}
				time(&finish);
			}
			while(difftime(finish, start)<= sec){
				time(&finish);	
			}
		}
		time(&start);
		if(option=='y'){
			cout<<"price is "<<*i1<<endl;
			cout<<"Sell Now? y/n"<<endl;
			while(difftime(finish, start)<= sec){
				cin>>option;
				if(option=='y'){ //sell  stock
				sell = *i1;
				profit = profit + sell - buy;
				n--;
				break;	
				}
				else if(option=='n'){ //dont sell
					break;
				}
				time(&finish);
			}
			while(difftime(finish, start)<= sec){
				time(&finish);
			}
			if(option=='n'){
				option = 'y';
			}
		}
		i1++;
	}
    cout<<"Maximun profit for transactions is :"<<profit<<endl;
    return profit;
}
