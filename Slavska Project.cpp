#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include <vector>
#include <locale>
#include <set>
#define N 20
using namespace std;

class Word{

private:
    string type; 
    string mfmtype;
    int plural_single; //1-single, 2-plural
    string osoba;
    string vidminnok;
    vector<string> prefix;
    vector<string> root;
    vector<string> suffix;
    vector<string> ending;

public:

    Word(string _type, string _mfmtype, int _plural_single, string _osoba, string _vidminnok, vector<string>& _prefix, vector<string>& _root, vector<string>& _suffix, vector<string>& _ending):
        type(_type),mfmtype(_mfmtype), plural_single(_plural_single), osoba(_osoba), vidminnok(_vidminnok),prefix(_prefix),root(_root),suffix(_suffix),ending(_ending){}

    vector<string> &get_prefix(){return prefix;}
    vector<string> &get_root(){return root;}
    vector<string> &get_suffix(){return suffix;}
    vector<string> &get_ending(){return ending;}
    string get_type(){return type;}; 
    string get_mfmtype(){return mfmtype;};
    int get_plural_single(){return plural_single;}; 
    string get_osoba(){return osoba;};
    string get_vidminnok(){return vidminnok;};

    
    
    void set_type(string type) {this->type = type;}
    void set_mfmtype(string mfmtype) {this->mfmtype = mfmtype;}
    void set_plural_single(int plural_single) {this->plural_single = plural_single;}
    void set_vidminnok(string vidminnok) {this->vidminnok = vidminnok;}
    
    
    virtual void print(ostream& out=cout){
        out<<"Word: ";
        for (auto& p : prefix){
            out << p;
        }
        for (auto& r : root){
            out << r;
        }
        for (auto& s : suffix){
            out << s;
        }
        for (auto& e : ending){
            out << e;
        }
        out<<endl;
        
        out<< type <<' '<< mfmtype <<' '<< plural_single <<' '<< osoba <<' '<< vidminnok<<endl;
    }

    Word change_ending(vector<string>& new_ending){
        Word w(type, mfmtype, plural_single, osoba, vidminnok, prefix, root, suffix, new_ending);
        return w;
    }

    Word change_suffix(vector<string>& new_suffix){
        Word w(type, mfmtype, plural_single, osoba, vidminnok, prefix, root, new_suffix, ending);
        return w;
    }

    Word change_plural_single(int new_plural_single, vector<string>& new_suffix, vector<string>& new_ending){
        Word w(get_type(),get_mfmtype(),get_plural_single(), get_osoba(), get_vidminnok(),get_prefix(), get_root(),get_suffix(),get_ending());
        
        Word w1=w.change_suffix(new_suffix);
        Word w2=w1.change_ending(new_ending);
        w2.set_plural_single(new_plural_single);
        return w2;
    }
    
    Word change_vidminnok(string new_vidminnok, vector<string>& new_suffix, vector<string>& new_ending){
        Word w(get_type(),get_mfmtype(),get_plural_single(), get_osoba(), get_vidminnok(),get_prefix(), get_root(),get_suffix(),get_ending());
        
        Word w1=w.change_suffix(new_suffix);
        Word w2=w1.change_ending(new_ending);
        w2.set_vidminnok(new_vidminnok);
        return w2;
    }
    
    string slovocel(){
        string temp="";
        for (auto& p : prefix){
            temp+=p;
        }
        for (auto& r : root){
            temp+=r;
        }
        for (auto& s : suffix){
            temp+=s;
        }
        for (auto& e : ending){
            temp+= e;
        }
        return temp;
    }
    
    int glasn(wchar_t glas[10],wchar_t sym)    // return 1 - if гласная, else return 0
    {
        for(int pois=0; pois<10; pois++){
            if (sym==glas[pois]) {
                return 1;
            }
        }
        return 0;
    }

    int find_glasn(wchar_t slovo[21], wchar_t glas[10], int i)
    {
        for (int k=i;k<21;k++){
            if (glasn(glas,slovo[k])) return 1;
        }
        return 0;
    }
    
    wstring syllable(){
        wchar_t glas [] = L"аяиіеуїєюо";
        wchar_t slovo[]= L"перевірка";
        char probel =' '; 
        const wchar_t def= L'-';
        wstring temp;
            
            
            //ищем гласные и выводим в файл через дефисы слоги
    
        for(int i=0;i<21;i++)
        {
            temp+= slovo[i];
            if (slovo[i]==probel) break;
            else 
            {
                if (glasn(glas,slovo[i])){
                    if(slovo[i+1]==probel) break; //чтобы не ставить лишний дефис 
                    else if (find_glasn(slovo,glas,i+1)) //есть ли дальше гласные
                    {
                        if ((!glasn(glas,slovo[i+1])) and (!glasn(glas,slovo[i+2]))){ //есть ли после текущей гласной 2 подряд стоящих согласных
                            i++;
                            temp += slovo[i];
                        }
                        temp+= def;   //дефиз
                    }   
                }
            }
        }
    
        return temp;
    }

};

class Verb:public Word{

public:

    Verb(string _type, string _mfmtype, int _plural_single, string _osoba, string _vidminnok, vector<string>& _prefix, vector<string>& _root, vector<string>& _suffix, vector<string>& _ending):
        Word ( _type,  _mfmtype,  _plural_single,  _osoba,  _vidminnok,  _prefix,  _root,  _suffix,  _ending){}

};

class Adjective: public Word{

public:

    Adjective(string _type, string _mfmtype, int _plural_single, string _osoba, string _vidminnok, vector<string>& _prefix, vector<string>& _root, vector<string>& _suffix, vector<string>& _ending):
        Word ( _type,  _mfmtype,  _plural_single,  _osoba,  _vidminnok,  _prefix,  _root,  _suffix,  _ending){}

    
};

class Noun: public Word{ 

public:

    Noun(string _type, string _mfmtype, int _plural_single, string _osoba, string _vidminnok, vector<string>& _prefix, vector<string>& _root, vector<string>& _suffix, vector<string>& _ending):
        Word ( _type,  _mfmtype,  _plural_single,  _osoba,  _vidminnok,  _prefix,  _root,  _suffix,  _ending){}

    
};


int main(){

    setlocale(LC_ALL, "Ukrainian");
    vector<string> p;
    p.push_back("пере");
    
    vector<string> r;
    r.push_back("вір");
    
    vector<string> s;
    s.push_back("к");
    
    vector<string> e;
    e.push_back("а");
    
    
    
    //type, mfmtype, plural_single, osoba, vidminnok, prefix, root, suffix, ending
    int n=1;
    Word* arr[n]={
        new Noun("іменник","жін",1,"", "наз",p,r,s,e)
    };
    for (int i = 0; i < n; i++){
        arr[i]->print();
        wcout<<arr[i]->syllable()<<endl;
    }
    
    vector<string> e1;
    e1.push_back("и");
    
    for (int i = 0; i < n; i++){
        (arr[i]->change_plural_single(2,s,e1)).print();
    }
    
    vector<string> s2;
    s2.push_back("ц");
    vector<string> e2;
    e2.push_back("і");
    
    cout<<endl<<endl;
    for (int i = 0; i < n; i++){
        (arr[i]->change_vidminnok("дав",s2,e2)).print();
        cout<<endl;
    }
}
