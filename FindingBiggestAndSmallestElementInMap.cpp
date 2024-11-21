// Finding the biggest and smallest element in map in O(1)
#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, int> tab;
    tab[100] = 1;
    tab[200] = 2;
    tab[300] = 3;

    map<int, int>::iterator it = tab.begin();

    cout<<it->first<< " "<< it->second<<endl;

    map<int, int>::reverse_iterator it1 = tab.rbegin();
    cout<<it1->first<<" "<<it1->second<<endl;
}