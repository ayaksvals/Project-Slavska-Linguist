/* File WORD.h
Realization of structures for task "WORD": Word
Done by Slavska Olesia (2.1 comp.math group)

Headers for structures: Word
*/

#include <string>
#ifndef WORD_H_
#define WORD_H_

#ifdef __cplusplus
extern "C"{
#endif
#include "../WORD_C/WORD.h"
#ifdef __cplusplus
} // end extern "C"
#endif



/* Default class of Word */
class Word {

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

    /*Different types of constructors*/
    Word ();
    Word (string _type, string _mfmtype, int _plural_single, string _osoba, string _vidminnok, vector<string>& _prefix, vector<string>& _root, vector<string>& _suffix, vector<string>& _ending);

    /* method for word input from file*/
    void get_from_file();

    /* method for word output to file*/
    void add_to_file();

    /* method for word input from console*/
    void print_to_console();

    /* method for word output to console*/
    void get_from_console();
};


