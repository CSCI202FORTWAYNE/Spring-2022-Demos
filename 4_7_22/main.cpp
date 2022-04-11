#include <iostream>
#include <fstream>


using namespace std;

long hashFunc(long key);

int main() 
{
    int ht[30000];
    int collisions = 0;

    ifstream in;
    in.open("input.txt");

    for(int i = 0; i < 30000; i++)
    {
        ht[i] = -1;
    }
    int count = 0;
    while(in.is_open() && count < 10000)
    {
        long x;
        in >> x;
        cout << x << " inserted at " << hashFunc(x) << endl;
        if(ht[hashFunc(x)] == -1)
        {
            ht[hashFunc(x)] = x;
        }
        else if(ht[hashFunc(x)] != x)
        {
            cout << x << " collided with " << ht[hashFunc(x)] << endl;
            collisions++;

        }
        count++;
    }
    cout << "There were " << collisions << " collisions." << endl;

    return 0;
}

long hashFunc(long key)
{
    long long keySquared = key * key;
    
    keySquared = keySquared / 10000;
    return keySquared % 30000;
}