/* File Linguist.cpp
Realization of functions for task "Linguist"
Done by Olesia Slavska (2.1 comp.math group)
Date 10.12.2021
Implementations of classes: Word, Noun, Verb, Adjective
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "Linguist.h"
using namespace std;




/*Constructor for Word object with all given information*/
Word::Word(string _type, string _mfmtype, int _plural_single, string _osoba, string _vidminnok, vector<string>& _prefix, vector<string>& _root, vector<string>& _suffix, vector<string>& _ending) :
    type(_type), mfmtype(_mfmtype), plural_single(_plural_single), osoba(_osoba), vidminnok(_vidminnok), prefix(_prefix), root(_root), suffix(_suffix), ending(_ending) {}


/*Empty Constructor for Word object*/
Word::Word(){}

/*Constructor to copy Word object*/
Word::Word(const Word &w):Word(w.type, w.mfmtype, w.plural_single, w.osoba, w.vidminnok, w.prefix, w.root, w.suffix, w.ending){}

/* Input word
input word from file

@result �  void
*/
void Word::get_from_file(){
    ifstream fin("../words.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }     
            //type, mfmtype, plural_single, osoba, vidminnok, prefix, root, suffix, ending
        type = row[0];
        mfmtype = row[1];
        plural_single = stoi(row[2]); // string to int
        osoba = row[3];
        vidminnok = row[4];

      
        getline(fin, line);
        if (fin.fail()) break;
        stringstream ssp(line);
        while (ssp.good()) {
            string substrp;
            getline(ssp, substrp, ',');
            preffix.push_back(substrp);
        }
        
        
        getline(fin, line);
        if (fin.fail()) break;
        stringstream ssr(line);
        while (ssr.good()) {
            string substrr;
            getline(ssr, substrr, ',');
            root.push_back(substrr);
        }

        
        getline(fin,pline);
        if (fin.fail()) break;
        stringstream sss(line);
        while (sss.good()) {
            string substrs;
            getline(sss, substrs, ',');
            suffix.push_back(substrs);
        }

        
        getline(fin, line);
        if (fin.fail()) break;
        stringstream sse(line);
        while (sse.good()) {
            string substre;
            getline(sse, substre, ',');
            ending.push_back(substre);
        }

        break;
        }
    }
    fin.close();

}

/* Output word
output word to file
@param - void
@result �  void
*/
void Word::add_to_file(){
    ofstream  fout;
    fout.open("../words.csv", std::ios_base::app);
    fout << "Word: ";

    for (auto& p : prefix) {
        fout << p;
    }
    for (auto& r : root) {
        fout << r;
    }
    for (auto& s : suffix) {
        fout << s;
    }
    for (auto& e : ending) {
        fout << e;
    }
    fout << endl;

    fout << type << ' ' << mfmtype << ' ' << plural_single << ' ' << osoba << ' ' << vidminnok << endl;
}

    fout.close();
}

/* Input word
input word from console
@param - void
@result �  void
*/
void Word::get_from_console(){
    //type, mfmtype, plural_single, osoba, vidminnok, prefix, root, suffix, ending
    cout<<"Input word type: ";
    getline(cin,type);
    cout << "Input word mfmtype: ";
    getline(cin, mfmtype);
    cout << "Input plural(1) or single(2): ";
    cin >> plural_single;
    cout << "Input word osoba: ";
    getline(cin, osoba);
    cout << "Input word vidminnok: ";
    getline(cin, vidminnok);


    int n;
    string temp;

    cout << "Input amount of prefixes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Preffix "<<i+1<<' ';
        cin >> temp;
        preffix.push_back(temp);
    }

    cout << "Input amount of roots: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Root " << i + 1 << ' ';
        cin >> temp;
        root.push_back(temp);
    }

    cout << "Input amount of suffix: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Suffix " << i + 1 << ' ';
        cin >> temp;
        suffix.push_back(temp);
    }

    cout << "Input amount of endings: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ending " << i + 1 << ' ';
        cin >> temp;
        ending.push_back(temp);
    }

}

/* Output word
output word to console
@param - void
@result �  void
*/
void Word::print_to_console(){
    cout << "Word: ";
    for (auto& p : prefix) {
        cout << p;
    }
    for (auto& r : root) {
        cout << r;
    }
    for (auto& s : suffix) {
        cout << s;
    }
    for (auto& e : ending) {
        cout << e;
    }
    cout << endl;

    cout << type << ' ' << mfmtype << ' ' << plural_single << ' ' << osoba << ' ' << vidminnok << endl;
}


