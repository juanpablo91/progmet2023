#include<iostream>

/*
Juan Pablo Gonzalez Rodriguez
*/

bool isPrime(int n);
void isPrimeSexy(const int &N);
 
int main(void){
  const int N1 = 3;
  const int N2 = 4;
  const int N3 = 2;

  isPrimeSexy(N1);
  isPrimeSexy(N2);
  isPrimeSexy(N3);

  return 0;
}

void isPrimeSexy(const int &N){
  int flag =N; 
  int p =1;
  int q = 1;

  while (flag > 0)
  { 
    p+=1;

    if(isPrime(p) ){
      q = p + 6;
      if(isPrime(q)){
        flag -=1;
      }
    }
  }
  std::cout << "(" << p << "," << q << ")" << "\n";
}
bool isPrime(int n){
  // Corner case
  if (n <= 1){
    return false;
  }
 
  // Check from 2 to n-1
  
  for (int i = 2; i < n; i++){
    if (n % i == 0){
      return false;
    }
  }
    return true;
}


