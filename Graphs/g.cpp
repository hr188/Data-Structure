#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';
  
  int n = foo.size();
    for ( int i = 0; i < n; i++)
    {
        std::cout<<foo.front()<<" ";
        foo.pop();
    }
  return 0;
}