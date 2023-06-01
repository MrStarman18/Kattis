/*Kattis problem Abandoned Animal
Developer: Justin T. Alexander
Date: 6/1/2023 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
//This version of the program utilizes the "purchase" struct to form a path of what was bought where.
//However, it exceeds the Kattis memory limit for test case 6.

int numStores, k, numItems;  //N, num of stores in town; k, num of items on sale; M, num of items sister purchased.
vector< set<string> > stores;    //What items are sold at each store.
vector<string> buyOrder;
int totalPaths = 0;         //Num of paths to buy all items. Used to determine output.

struct purchase             //Use to store where each item was bought to cache Paths?
{
    int store;
    string item;
    bool operator<(const purchase& a) const {
        return store < a.store; }
};
set< vector<purchase> > rightPaths;

void path(int item, int currStore, vector<purchase> currPath)  //Need to call twice from each store that sells the item, once if we bought it here and once if we didn't.
{   //Base cases
    //If 2+ paths already exist, we call it ambiguous
    if (totalPaths >= 2)
        return;

    //If bought all items
    if (item >= buyOrder.size())
    {   //if this path isn't in cache
        if (!rightPaths.count(currPath))
        {
            totalPaths++;
            rightPaths.insert(currPath);
        }
        return;
    }
    //If we've visited all stores without satisfying either condition, end path
    else if (currStore >= numStores)
        return;

    string currItem = buyOrder[item];
    //cout << "Testing for " << currItem << " at Store " << currStore << endl;
    //If in last Store and they don't sell the curr Item, end path
    if (currStore == numStores-1 && !stores[currStore].count(currItem))       
        return;
        
    //If current store sells current item
    if (stores[currStore].count(currItem))
    {
        vector<purchase> midPath = currPath;
        midPath.push_back({currStore, currItem});
        path(item+1, currStore+1, midPath); //buy item at this store and move on
        path(item+1, currStore, midPath);   //buy item at this store and stay here
    }
    path(item, currStore+1, currPath);      //don't buy item and move on
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
    //cout << numItems << endl << endl;
    for (int i = 0; i < numItems; i++)      //Input the order sister purchased items.
    {
        string midItem;
        cin >> midItem;
        buyOrder.push_back(midItem);
        //cout << midItem << " ";
    }
    //cout << "s" << endl;
    //Start recursive call and print result
    vector<purchase> init;
    path(0, 0, init);
    if (totalPaths == 0)
        cout << "impossible\n";
    else if (totalPaths == 1)
        cout << "unique\n";
    else if (totalPaths >= 2)
        cout << "ambiguous\n";
}