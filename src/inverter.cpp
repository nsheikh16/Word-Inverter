#include <string>
#include <queue>
#include <map>
#include <set>

#include "inverter.h"

using namespace std;


string build_inverted_index(string filename){

	map<string,set<int> > invertedIndex;
	string text;
		
	int filenum =0;
	ifstream fileStream;
	fileStream.open(filename.c_str());
	int numoc =0;
	string line;
	while(fileStream >> line) {
		//if(fileStream.is_open()){


		//}
			ifstream inner; 
			inner.open(line.c_str());

			if (inner.is_open()){

				string line2;
				/*while(inner >> line2) {
					cout << line2;
					cout << "\n";
				}*/
				char c;
				string word = "";
				
				while (inner >> noskipws >> c) {
					//cout << c;
					//cout << " ";
					//if c is correct kind of char, add to word
					if ((c >= 65 && c<=90) || (c>=97 && c<= 122)) {
						word += c;
						//cout << word;
						//cout << " ";

					} 
					else if (word!= "") { 
						//set s = invertedIndex[word]
						//s.insert(filenum)
						//cout << word << "\n";
						invertedIndex[word].insert(filenum);
						word ="";
					}
					


					}// this should add all the letters in the file without spaces to word
					inner.clear();
					filenum++;
					inner.close();
				}
				


					
	}
		map<string,set<int> > :: iterator mapiter;
		set<int> :: iterator setiter;
		string ret = "";
		for(mapiter = invertedIndex.begin();mapiter !=invertedIndex.end();mapiter++){
			//cout << mapiter->first << '\n';
			ret += mapiter->first + ":";
			set<int> curr_set = mapiter->second;

			for(setiter = curr_set.begin();setiter != curr_set.end();setiter++ ){
				ret += " " + to_string(*setiter);
			
		}
		ret += "\n";

	}

		
		return ret;
}
