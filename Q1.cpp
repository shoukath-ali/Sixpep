#include<iostream>
#include<fstream>
#include<string.h>
#include <ctime>
using namespace std;
int hs;

void display(){
    cout<<"1.New Word "<<" "<<"2.Score "<<" "<<"3.HighScore "<<"4.Save & Quit"<<endl;
}

void read_Highscore(){
	fstream file;
	file.open("value.txt",ios::in);
	if(!file){
		//cout<<"No suchfile"<<endl;
	}
	else { //reading file
		while(1){
			file>>hs;
			if(file.eof()){
				break;
			}
		}
	}
	file.close();
//	cout<<"HighScore is:"<<hs<<endl;
}

int main(){
	int score  = 0;
	//file creation and High score read
	read_Highscore();
	string word[6] = {"Mexico", "USA","UAE","Li","India","Hitech"};
	int i;//input option
	int r ;// random value generator
	while(i!=4){
		//read_Highscore();
		display();
		cin>>i;
		cout<<"The Player input is: "<<i <<endl;
		srand (time(NULL));
		r = rand()%10;
		if(r>5){
		 	r = r-4;
		}
    	if(i==1){
    		cout<<"Your new word is "<<word[r]<<". Type now"<<endl;
    		string j;
			time_t start, finish;
    		cin.ignore();
    		//Start time
    		time(&start);
    		getline(cin,j);
    		//end time
    		time(&finish);
    		//Case sensitive and validity check
    		if(j!=word[r]){
    			score =score-1;
			}
			else{
				int seconds = difftime(finish, start);
				if(seconds<2) score+=2;
				else if(seconds<3) score+=1;
			}
		}
		if(i==2){
			cout<<score<<endl;
		}
		if(i==3){
			cout<<hs<<endl;
		}
		if(i==4){
			if(score>hs){
				//write in score in file
				fstream my_file;
				my_file.open("value.txt", ios::out);
				if (!my_file) {
					cout << "File not created!";
				}
				else {
					my_file << score;
					my_file.close();
				}
			}
			else{
				break;
			}
		}
	}
	return 0;
}
