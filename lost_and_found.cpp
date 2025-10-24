#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

string remove_vowels(const string &s) {
    string out;
    for (char c : s) if (!is_vowel(c)) out.push_back(c);
    return out;
}

string reverse_str_ud(const string &s) {
    string r;
    r.resize(s.size());
    for (size_t i=0;i<s.size();++i) r[i]=s[s.size()-1-i];
    return r;
}

string encode_word(const string &word) {
    if (word.empty()) return "";
    string no_vowel = remove_vowels(word);
    string rev = reverse_str_ud(no_vowel);
    int ascii_code = (int)word[0];
    size_t mid = rev.size()/2;
    return rev.substr(0,mid)+to_string(ascii_code)+rev.substr(mid);
}

string decode_password(const string &pwd) {
    int L=pwd.size(),start=-1,end=-1;
    for(int i=0;i<L;i++){
        if(isdigit(pwd[i])){
            if(start==-1) start=i;
            end=i;
        }
    }
    if(start==-1) return "";
    string digits=pwd.substr(start,end-start+1);
    int ascii_code=stoi(digits);
    char first_char=(char)ascii_code;
    string without_digits=pwd.substr(0,start)+pwd.substr(end+1);
    string rev=reverse_str_ud(without_digits);
    if(rev.empty()||rev[0]!=first_char) rev=first_char+rev;
    return rev;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mode;
    cout<<"Menu: 1=encode, 2=decode\n";
    cin>>mode;
    string s;cin>>s;
    if(mode==1) cout<<encode_word(s)<<'\n';
    else if(mode==2) cout<<decode_password(s)<<'\n';
    else cout<<"Mode tidak dikenal\n";
}
