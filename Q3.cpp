
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;
    int n;
    cout<<"Count of entries should be multiple of 2"<<endl;
    cin>>n;
    if(n%2!=0){
        cout<<"Enter valid entrie with total count multiple of 2 (You didn't sell one stock)"<<endl;
        return 0;
    }
    int input;
    cout<<"Enter the entries"<<endl;
    for(int i =0;i<n;i++){
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
    cout<<"Enter the Max transactions allowed"<<endl;
    cin>>n;
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
