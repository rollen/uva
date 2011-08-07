#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

void testOddComputation();
void testNotOddComputation();
void testComputation();
void testIsOdd();
void testNumberOfCountsForAlgorithm();
void testMaxCycleLength();
void runAllTests();

int oddComputation(int);
int notOddComputation(int);
int computation(int);
int isOdd(int);
int numberOfCounts(int);
int maxCycleLength(int, int);
int max(int, int);
int maxValue(int, int);
int minValue(int, int);

int main(int argc, char *argv[]){
  if(argc == 2 && strcmp(argv[1], "test") == 0){
    runAllTests();
  } else {
    int firstVal, secondVal;
    while(scanf("%d %d", &firstVal, &secondVal) == 2)  
      printf("%d %d %d\n", firstVal, secondVal, maxCycleLength(firstVal, secondVal));
  }
  return 0;
}

void runAllTests(){
  testOddComputation();
  testNotOddComputation();
  testComputation();
  testIsOdd();
  testNumberOfCountsForAlgorithm();
  testNotOddComputation();
  testMaxCycleLength();
}

int maxValue(int firstVal, int secondVal){
  return firstVal > secondVal ? firstVal  : secondVal;
}

int minValue(int firstVal, int secondVal){
  return firstVal > secondVal ? secondVal : firstVal;
}

void testMaxCycleLength(){
  assert(20 == maxCycleLength(1, 10));
  assert(20 == maxCycleLength(10, 1));
  assert(1 == maxCycleLength(1, 1));
  assert(125 == maxCycleLength(100, 200));
  assert(89 == maxCycleLength(201, 210));
  assert(174 == maxCycleLength(900, 1000));
}

int maxCycleLength(int firstVal, int secondVal){
  int lower = minValue(firstVal, secondVal);
  int upper = maxValue(firstVal, secondVal);

  int maxCycleCount = 0;
  int i = 0;
  for(i = lower; i <= upper; i++){
    maxCycleCount = maxValue(maxCycleCount, numberOfCounts(i));
  }

  return maxCycleCount;
}

int max(int firstVal, int secondVal){
  return firstVal > secondVal ? firstVal : secondVal;
}

void testNumberOfCountsForAlgorithm()
{
  assert(1 == numberOfCounts(1));
  assert(16 == numberOfCounts(22));
}

int numberOfCounts(int n){
  int count = 1;
  while( n != 1 ){
    n = computation(n);
    count++;
  }
  return count;
}

void testIsOdd(){
  assert(TRUE == isOdd(3));
  assert(TRUE == isOdd(1));
  assert(FALSE == isOdd(4));
}

int isOdd(int n){
  return (n % 2 == 0) ? FALSE : TRUE;
}

void testComputation(){
  assert(4 == computation(1));
  assert(2 == computation(4));
  assert(10 == computation(20));
  assert(5 == computation(10));
  assert(16 == computation(5));
  assert(8 == computation(16));
  assert(4 == computation(8));
  assert(2 == computation(4));
  assert(1 == computation(2));
}

int computation(int n){
  return isOdd(n) ? oddComputation(n) : notOddComputation(n);
}

void testOddComputation()
{
  assert(4 == oddComputation(1));
}

int oddComputation(int n)
{
  return 3*n+ 1;
}

void testNotOddComputation()
{
  assert(2 == notOddComputation(4));
}

int notOddComputation(int n)
{
  return n / 2;
}
