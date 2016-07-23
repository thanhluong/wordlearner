#include <bits/stdc++.h>
#include "LStream.cpp"
#include "LMath.cpp"

using namespace std;

ifstream fin ("WordLearner.dict");

struct WordType{
    string Word;
    string Meaning;
    string Example;

    int Key; //key to rearrange word list
} NewWord;

bool __WordCMP(WordType a, WordType b){
    return (a.Key <= b.Key);
}

int N; //number of the word will be checked
int Score = 0;
int C = 0; //Correct word

vector<WordType> WordList;

int CheckWord(WordType Word){
    string AnswerWord;
    string AnswerExample;

    cout << Word.Meaning << ":" << endl;
    ReadLine(AnswerWord);
    if(Word.Word != AnswerWord){//wrong answer
        cout << "Wrong! The answer is " << Word.Word << "! ";
        cout << "Your score decreased by 1" << endl << endl;
        return 1;
    }
    C++, Score++;
    cout << "Correct! Give me an example for this word:" << endl;
    ReadLine(AnswerExample);
    if(Word.Example != AnswerExample){
        cout << "Your example is not match to database! But we still +1 to your score!" << endl << endl;
        return 2;
    }
    Score++;
    cout << "Excellent! You learned by heart this word! +2 to your score" << endl << endl;
    return 0;
}

void CheckEntirely(){
    N = WordList.size();//check all element in word list

    sort(WordList.begin(), WordList.end(),__WordCMP);
    for(vector<WordType>::iterator it = WordList.begin(); it != WordList.end(); it++){
        CheckWord(*it);
    }
}

void CheckRandomly(){
    int M = WordList.size(); // size of dict

    cout << "Enter the number of word you would like to check: ";
    ReadInt(N);
    cout << " ================================================ " << endl << endl;

    srand(time(NULL)); //trigger random mode
    for(int i=1; i<=N; i++){
        CheckWord( WordList[ RandNum(M) ] );
    }
}

void Preferences(){
    int P;

    cout << "Welcome to WordLearner 1.0" << endl;
    cout << "Which way do you like to do the review session in? Type 1 to review entirely and any other number to review randomly" << endl;
    ReadInt(P);
    cout << endl;
    if(P==1){
        CheckEntirely();
        return;
    }
    CheckRandomly();
}

void ReadDict(){
    while(true){
        NewWord.Key = RandNum(295);

        getline(fin, NewWord.Word);
        getline(fin, NewWord.Meaning);
        getline(fin, NewWord.Example);
        WordList.push_back( NewWord );

        if(fin.eof()) return;
    }
}

void PrintResult(){
    cout << "Your final result: ";
    cout << C << " / " << N << " word(s) is correct" << endl;
    cout << "Your score: " << Score << endl;
    system("pause");
}

main(){
    ReadDict();
    Preferences();
    PrintResult();
}
