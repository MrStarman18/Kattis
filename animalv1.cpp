/*Kattis problem Abandoned Animal
Developer: Justin T. Alexander
Date: 6/1/2023 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
//This version of the program counts the same path multiple times. Implementing a cache of paths to solve this.

int numStores, k, numItems;  //N, num of stores in town; k, num of items on sale; M, num of items sister purchased.
vector< set<string> > stores;    //What items are sold at each store.
vector<string> buyOrder;
int totalPaths = 0;         //Num of paths to buy all items. Used to determine output.

void path(int item, int currStore, int prevStore)  //Need to call twice from each store that sells the item, once if we bought it here and once if we didn't.
{   //Base cases
    //If 2+ paths already exist, we call it ambiguous
    if (totalPaths >= 2)
        return;
    //If bought all items
    if (item >= buyOrder.size())
    {
        if (prevStore != currStore)
            totalPaths++;
        return;
    }
    //If we've visited all stores without satisfying either condition, end path
    else if (currStore >= numStores)
        return;

    string currItem = buyOrder[item];
    cout << "Testing for " << currItem << " at Store " << currStore << endl;
    //If in last Store and they don't sell the curr Item, end path
    if (currStore == numStores-1 && !stores[currStore].count(currItem))       
        return;
        
    //If current store sells current item
    if (stores[currStore].count(currItem))
    {
        path(item+1, currStore+1, currStore);  //buy item at this store and move on
        path(item+1, currStore, currStore);    //buy item at this store and stay here
    }
    path(item, currStore+1, currStore);        //don't buy item and move on
}

int main()
{   //Input
    cin >> numStores >> k;
    for (int i = 0; i < numStores; i++)     //Initialize Stores vector.
    {   set<string> midMan;
        stores.push_back(midMan);
    }
    for (int i = 0; i < k; i++)             //Input what items are sold at each store.
    {
        int midStore; string midItem;
        cin >> midStore >> midItem;
        stores[midStore].insert(midItem);
    }
    cin >> numItems;
    cout << numItems << endl << endl;
    for (int i = 0; i < numItems; i++)      //Input the order sister purchased items.
    {
        string midItem;
        cin >> midItem;
        buyOrder.push_back(midItem);
        //cout << midItem << " ";
    }
    //cout << "s" << endl;
    //Start recursive call and print result
    path(0, 0, -1);
    if (totalPaths == 0)
        cout << "impossible\n";
    else if (totalPaths == 1)
        cout << "unique\n";
    else if (totalPaths >= 2)
        cout << "ambiguous\n";
}