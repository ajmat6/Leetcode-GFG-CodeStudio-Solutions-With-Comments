#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m; // map created of key type string and value type int

    // insertion:

    //method1
    pair<string, int> p = make_pair("Ajmat", 1000);
    m.insert(p);

    //method2
    pair<string, int> q("kathat", 2000);
    m.insert(q);

    //method3
    m["Beawar"] = 3000;

    m["Beawar"] = 4000; // now beawar value will be upadated to 4000 from 3000


    // Searching:

    cout << m["Ajmat"] << endl;
    cout << m["Beawar"] << endl;
    cout << m["ak"] << endl;
    cout << m.at("ak") << endl;

    // Traverse using for loop:
    for(auto i: m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;

    // Creating an Iterator:
    unordered_map<string, int> :: iterator it = m.begin();

    // Now traversing through the map using the iterator:
    while (it != m.end())
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    

    return 0;
}