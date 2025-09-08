#include <iostream>
using namespace std;

// int main()
// {
//     try
//     {
//        throw 'a';
//     }
//     catch (int param)
//     {
//         cout << "int exception\n";
//     }
//     catch (...)
//     {
//         cout << "default exception\n";
//     }
//     cout << "After Exception";
//     return 0;
// }


#include <iostream>
using namespace std;

int fun()
{
    throw 10;
}

int main() {

  fun();

  return 0;
}
 
