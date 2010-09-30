#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>

int main()
{
    using namespace std;
    using namespace boost;
    string s = "exec script1 \"script 'argument' number one\"";
    string separator1("");//dont let quoted arguments escape themselves
    string separator2(" ");//split on spaces
    string separator3("\"\'");//let it have quoted arguments

    escaped_list_separator<char> els(separator1,separator2,separator3);
    tokenizer< escaped_list_separator<char> > esc_tok(s, els);
    tokenizer<> tok(s);

    cout << "Parsing: " << s << endl << endl;

    cout << "with escaped separators: " << endl;
    for(tokenizer< escaped_list_separator<char> >::iterator beg=esc_tok.begin(); beg!=esc_tok.end();++beg)
    {
        cout << *beg << "\n";
    }

    cout << endl << "without default tokenizer: " << endl;
    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg)
    {
        cout << *beg << "\n";
    }
}
