#include <bits/stdc++.h> 
#include <iostream>
#include <Fstream>
#include <string>

using namespace std;

int counter=0;

int main() {
	
	string dict[100][2];
	string line;
	string token;
	ifstream infile;
	int flag=0;

	
	
	infile.open("Dictionary.txt");
	


	while (getline (infile,line) )
	
    {
      	stringstream Stream(line);
       	int i=0;
      while (getline(Stream, token, ',')) { 
 	 
 	     	dict[counter][i] = token;
 	  		i++;
 	  		
     }
     
     	counter++;

    }
    
    infile.close();
 
	string  permission_1;
	cout << "Do you want to search a word ";
	cin >> permission_1;
	string word_search;
	while (permission_1 == "yes"){
		cout << "Enter your word to search: \n";
		cin  >> word_search;
		cout << "\n";
	
		for (int i = 0; i <= counter; i++){
			
				
			if (word_search.compare(dict[i][0]) == 0){
				
				cout << dict[i][0]<<" means "<< dict[i][1] << "\n\n";
				flag = 1;
			    break;
				}
			}
			if (flag == 0) {
				
				string add_word; 
				string word_meaning;
			
			
				
				cout << "word not found in dictionary\n" << "Do you want to add the word in dictionary?\n";
				cin >> add_word;
			
				
				if (add_word == "yes")
				{
				
				  cout << "please enter it's meaning\n";
			      cin >> word_meaning;
				  dict [counter][0] = word_search;
				  dict [counter][1] = word_meaning;
				  counter ++;
				  ofstream outfile;
   				  outfile.open("Dictionary.txt", ios::app);
   				  outfile << word_search << "," << word_meaning << endl;
   				  outfile.close();

				}
					
			}
				
		flag=0;
		
        string permission_2;
		cout << "Do you want to continue searching ";    
		cin >> permission_2; 
		if (permission_2 == "yes")
	    	permission_1 = "yes";       
		else if  (permission_2 == "no")
		    permission_1 = "no"; }    
	return 0;}         