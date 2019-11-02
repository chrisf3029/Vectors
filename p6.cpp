//Christopher Fong
//p6.cpp

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int AMOUNT = 1000;

const int MAX_NUM = 99;

const int NUMS_PER_LINE = 25;

//Prints vector elements
void print(vector<int> list);

//Erases numbers divisible by 5
void eraseFives(vector<int>& list);

//Removes prime numbers between mixed numbers
bool removePrimes(vector<int>& list);

//tests if number is prime
bool prime(int num);

int main()
{
  vector<int> list;
  int random;
  srand(time(NULL));
  for(int i = 0; i < AMOUNT; i++){
    random = (int)(rand() % MAX_NUM) + 1;
    list.push_back(random);
  }

  print(list);

  cout << "Erase Fives." << endl << endl;

  eraseFives(list);

  print(list);

  cout << "Remove Primes." << endl << endl;
  
  while(removePrimes(list))
    print(list);

  print(list);

  return 0;
}

void print(vector<int> list)
{
  cout << "Printing list(" << NUMS_PER_LINE << " numbers per line):"<< endl;
  for(unsigned int i = 1; i <= list.size(); i++){
    if(list[i - 1] > 9)
      cout << list[i - 1] << " ";
    else
      cout << " " << list[i - 1] << " ";
    if(i % NUMS_PER_LINE == 0)
      cout << endl;
  }
  cout << endl << endl;
}

void eraseFives(vector<int>& list)
{
   for(unsigned int i = 0; i < list.size(); i++){
    if(list[i] % 5 == 0){
      list.erase(list.begin() + i);
      i--;
    }
  }
}

bool removePrimes(vector<int>& list)
{
  bool erase = false;
  int first;
  int second;
  int third;

  for(unsigned int i = 0; i < list.size() - 2; i++){ 
    first = list[i];
    second = list[i + 1];
    third = list[i + 2];
    if((first % 2 == 0 && third % 2 != 0) || (first % 2 != 0 && third % 2 == 0)){
      if(prime(second)){
        list.erase(list.begin() + i + 1);
        i--;
        erase = true;
      }
    }
  }

  return erase;
}

bool prime(int num)
{
  bool isPrime = true;
  if(num != 1 || num != 2){
    for(int i = 2; i < num / 2; i++){
      if(num % i == 0){
        isPrime = false;
        break;
      }
    }
  }
  return isPrime;
}
  
