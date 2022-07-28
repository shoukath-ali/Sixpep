
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;
    int n;
    cout<<"No of Transactions allowed per day"<<endl;
    cin>>n;
    int input;
    cout<<"Enter the entries"<<endl;
    while(input!= 0){
        cin>>input;
        v.push_back(input);
    }
    vector<int> diff;
    vector<int>::iterator i1 = v.begin();
    vector<int>::iterator i2 = i1+1;
    while(i1!=v.end()){
        diff.push_back(abs(*i2 - *i1));
        i1++;
        i1++;
        i2++;
        i2++;
    }

    sort(diff.begin(),diff.end());
    if(n>diff.size()){
        cout<<"Not possible to earn";
        return 0;
    }
    i1 = diff.begin() + (diff.size()-n) ;
    int max= 0;
    while(i1<diff.end()){
        max= max + *i1;
        i1++;
    }
    cout<<"Maximun profit for "<<n<<" transactions is :"<<max<<endl;
    return max;


}
