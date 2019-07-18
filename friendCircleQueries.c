#include <bits/stdc++.h>

using namespace std;


// done using disjoint sets
class DisjointSet
{
    public:
        int value, noOfMembers;
        DisjointSet *parent;

    DisjointSet(int data)
    {
        this->value = data;
        this->parent = this;
        this->noOfMembers = 1;
    }

    DisjointSet* findRoot()
    {
        DisjointSet *myParent = this;
        while(myParent != myParent->parent)
        {
            myParent = myParent->parent;
        }

        return myParent;
    }

    void mergeSets(DisjointSet *other)
    {
        this->findRoot()->noOfMembers += other->findRoot()->noOfMembers;
        cout<<"updated members of "<<this->findRoot()->value<<" to "<<this->findRoot()->noOfMembers<<endl;
        other->findRoot()->parent = this->findRoot();

    }

    string toString() {
      string retStr = "[Value: " + to_string(this->value) +
                      " Members: " + to_string(this->noOfMembers) +
                      "  Parent: " + to_string(this->parent->value) + "]";

        return retStr;
    }
};

int findInVector(vector<DisjointSet*> v, int key)
{
    int iter = 0;
    for(auto i : v)
    {
        if (i->value == key)
            return iter;

        iter++;
    }

    return -1;
}

void printVector(vector<DisjointSet*> v)
{
    printf("[\n");
    for (auto i : v)
    {
        cout<<i->toString()<<", "<<endl;
    }
    printf("]\n");
}

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {

    int maxValue = 0;
    vector<DisjointSet*> addedValues;
    vector<int> maxVector;
    DisjointSet *initial1 = new DisjointSet(queries[0][0]);
    DisjointSet *initial2 = new DisjointSet(queries[0][1]);
    initial1->mergeSets(initial2);
    maxValue = initial1->noOfMembers;
    addedValues.push_back(initial1);
    addedValues.push_back(initial2);

    for (auto i : queries)
    {
        int indexA = findInVector(addedValues, i[0]);
        int indexB = findInVector(addedValues, i[1]);

        if (indexA >= 0 && indexB >= 0)
        {
            if (addedValues[indexA]->findRoot() == addedValues[indexB]->findRoot())
            {
                // do nothing
            }
            else if (addedValues[indexA]->noOfMembers < addedValues[indexB]->noOfMembers)
            {
                addedValues[indexB]->mergeSets(addedValues[indexA]);
                if (maxValue < addedValues[indexB]->findRoot()->noOfMembers)
                    maxValue = addedValues[indexB]->findRoot()->noOfMembers;
            }
            else
            {
                addedValues[indexA]->mergeSets(addedValues[indexB]);
                if (maxValue < addedValues[indexA]->findRoot()->noOfMembers)
                    maxValue = addedValues[indexA]->findRoot()->noOfMembers;
            }
        }
        else if (indexA < 0 && indexB >= 0)
        {
            DisjointSet *temp = new DisjointSet(i[0]);
            addedValues[indexB]->mergeSets(temp);
            addedValues.push_back(temp);
            if (maxValue < addedValues[indexB]->findRoot()->noOfMembers)
              maxValue = addedValues[indexB]->findRoot()->noOfMembers;
        }
        else if (indexA >= 0 && indexB < 0)
        {
            DisjointSet *temp = new DisjointSet(i[1]);
            addedValues[indexA]->mergeSets(temp);
            addedValues.push_back(temp);
            if (maxValue < addedValues[indexA]->findRoot()->noOfMembers)
              maxValue = addedValues[indexA]->findRoot()->noOfMembers;
        }
        else
        {
          DisjointSet *initial1 = new DisjointSet(i[0]);
          DisjointSet *initial2 = new DisjointSet(i[1]);
          initial1->mergeSets(initial2);
          maxValue = max(maxValue, initial1->noOfMembers);
          addedValues.push_back(initial1);
          addedValues.push_back(initial2);
        }

        maxVector.push_back(maxValue);
    }

    printVector(addedValues);
    return maxVector;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
