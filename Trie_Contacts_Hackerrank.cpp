//Hackerrank contacts qstn
//https://www.hackerrank.com/challenges/contacts/problem?h_r=profile


#include<bits/stdc++.h>
using namespace std;

struct Trie{
    Trie* child[26];
    bool isEnd = false;
    int count = 0;
};

Trie* root;
void insert(string word){
    Trie* temp=root;
    for(char i : word){
        if(temp->child[i-'a']==NULL){
             Trie* cur=(Trie*)malloc(sizeof(Trie));
             temp->child[i-'a']=cur;
        }
        temp=temp->child[i-'a'];
        temp->count++;
    }
    temp->isEnd=true;
}

int prefix(string word){
    Trie* temp=root;
    for(char i : word){
        if(temp->child[i-'a']!=NULL)
            temp=temp->child[i-'a'];
        else
            return 0;
    }
    return temp->count;
}

int main(){
    int t;
    cin>>t;
    string type, word;
    root=(Trie*)malloc(sizeof(Trie));
    while(t--){
        cin>>type>>word;
        if(type=="add")
            insert(word);
        else
            cout<<prefix(word)<<endl;
    }
}
