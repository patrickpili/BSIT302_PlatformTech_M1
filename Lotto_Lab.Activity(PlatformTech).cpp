#include <iostream>      
#include <thread>     
#include <atomic>  

using namespace std;

atomic<bool> r1(false);
atomic<bool> r2(false);
atomic<bool> r3(false);

atomic<int> c1 (0);
atomic<int> c2 (0);
atomic<int> c3 (0);

void first(int id) {
  while (!r1) {           
    this_thread::yield();
  }
for (volatile int i=1; i<=55; ++i) {
++c1;
if(c1 <= 6) {
    cout << id;
}
}
}
void second(int id) {
  while (!r2) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++c2;
if(c2 <= 6) {
    cout << id;
}
}
}
void third(int id) {
  while (!r3) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++c3;
if(c3 <= 6) {
    cout << id;
}
}
}
int main ()
{
int i = 1;
  thread th1[55];
  thread th2[55];
  thread th3[55];
  cout << "Lotto Winners!\n";
  
  for (int i=1; i<7; ++i) th1[i]=std::thread(first,i);
  cout << "\nFirst Winner: ";
  r1 = true; 
  this_thread::sleep_for(chrono::seconds(1));
  th1[i].join();
  
  for (int i=1; i<7; ++i) th2[i]=std::thread(second,i);
  cout << "\nSecond Winner: ";
  r2 = true; 
  this_thread::sleep_for(chrono::seconds(2));
  th2[i].join();
  
  for (int i=1; i<7; ++i) th3[i]=std::thread(third,i);
  cout << "\nThird Winner: ";
  r3 = true; 
  this_thread::sleep_for(chrono::seconds(3));
  th3[i].join();
  return 0;
}
