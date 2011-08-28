#include <iostream> 
#include <string>
#include <sstream>
#include <assert.h>

#define POSITIVE 1
#define NEGATIVE 0

#define TRUE 1
#define FALSE 0

using namespace std;
class Term{
  int sign, coeff, exponent;

  public:
  Term(int coeff, int exponent);
  string toString();
};

void unitTestsForTerm();
void assertString(string expected, string received);
void assertString(char* expected, string received);
void assertString(string expected, Term* term);


Term::Term(int coeff, int exponent){
  this->sign = coeff < 0 ? NEGATIVE : POSITIVE;
  this->coeff = abs(coeff);
  this->exponent = exponent;
}

string Term::toString(){
  stringstream ss;

  if( coeff == 0){
    ss << 0;
  } else if( exponent == 0 ){
    ss << coeff ;
  } else if(coeff == 1){
    ss << "x^" << exponent;
  } else {
    ss << coeff << "x^" << exponent;
  }
  return ss.str();
}

int main(int argc, char *argv[]){
  if(argc == 2 && strcmp(argv[1], "test") == 0){
    unitTestsForTerm(); 
  } else {

  }
  return 0;
}

void unitTestsForTerm(){
  assertString( string("4x^9"), new Term(4, 9) );
  assertString( string("0"), new Term(0, 4) );
  assertString( string("1"), new Term(1, 0) );
  assertString( string("x^4"), new Term(1, 4) );
}

void assertString(string expected, string received){
  try{
    cout << "Expected: " << expected << "\t" << "Received: " << received << endl;
    assert(expected.compare(received) == 0);
  } catch (int e) {
  }
}

void assertString(char* expected, string received){
  assertString(string(expected), received);
}
void assertString(string expected, Term *t){
  assertString(expected, t->toString());
}
