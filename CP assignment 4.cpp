#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<thread>
#include<chrono>
using namespace std;

void  effect(string text, int delay){
	for(char a: text){
		cout<<a<<flush;
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

void game(){
	system("cls");
	int guess,number;
	srand(time(0));
	number = rand() % 100 + 1;
	cout<<"=============="<<endl;
	cout<<" GUESS WORLD "<<endl;
	cout<<"=============="<<endl<<endl;
	cout<<"Thinking of a number";
	for(int i=0;i<7;i++){
		cout<<"."<<flush;
		this_thread::sleep_for(chrono::milliseconds(400));
	}
	cout<<endl<<"Let the guessing begin!"<<endl;
	
}

int main(){
	char play;
	string wish="Welcome to the world of numbers!";
	string q="Can you outsmart the computer?";
	string rules="Rules: ";
	string r="- The number is between 1 and 100\n- You have only 5 tries\n";
	cout<<"=============="<<endl;
	cout<<" GUESS WORLD "<<endl;
	cout<<"=============="<<endl;
	effect(wish,20);
	cout<<endl;
	effect(q,20);
	cout<<endl<<endl;
	effect(rules,30);
	cout<<endl<<r;
	cout<<endl<<"Are you Ready (y/n): ";
	cin>>play;
	if(play=='y' || play=='Y'){
		cout<<endl;
		cout<<"Lets play !";
		this_thread::sleep_for(chrono::milliseconds(1000));
		game();
	}
	else if ( play=='n'  || play == 'N'){
		cout<<"Come back when courage loads to 100%.\n";
		return 0;
	}
	else{
		cout<<"\nI will take it as a No.\nGood Bye";
		return 0;
	}
}