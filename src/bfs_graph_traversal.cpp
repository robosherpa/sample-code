#include <bits/stdc++.h>
#include <unordered_map>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// DO NOT EDIT
// Vertex class
class Vertex {
    public:
        char id;
        vector<Vertex*> edges;

        Vertex(char id) {
            this->id = id;
        }
};
/*
* Complete the 'bfs' function below.
*
* The function is expected to return a STRING.
* The function accepts following parameters:
*  1. Vertex origin
*/

/*
 * For your reference:
 *
 * Vertex {
 *     char id;
 *     vector<Vertex*> edges;
 * }
 *
 */

string bfs(Vertex *origin) {
    if (origin == nullptr)
    {
        return "";
    }
    std::shared_ptr<std::queue<Vertex*>> myQueue = make_shared<std::queue<Vertex*>>(); 
    std::shared_ptr<std::unordered_set<Vertex *>> visited = 
                                            make_shared<std::unordered_set<Vertex *>>();
    
    myQueue->push(origin);
    visited->insert(origin);
    
    std::string s ="";
    while(!myQueue->empty())
    {
        Vertex *current = myQueue->front();
        myQueue->pop();
        for(Vertex* edge : current->edges)
        {
            if(visited->find(edge) == visited->end())
            {
                myQueue->push(edge);
                visited->insert(edge);
            }
        }
        s += current->id;
    }  
    
    return s;

}

// DO NOT EDIT// generate graph from int and array of arrays
Vertex *deserialize(string vertices, vector<string> &edges){
    unordered_map<char, Vertex*> container;
    for (int i = 0; i < vertices.length(); i++) {
        container[vertices[i]] = new Vertex(vertices[i]);
    }
    char v1;
    char v2;
    for (int i = 0; i < edges.size(); i++) {
        string edge = edges[i];
        v1 = edge[0];
        v2 = edge[1];
        container[v1]->edges.push_back(container[v2]);
        container[v2]->edges.push_back(container[v1]);
    }
    return container[vertices[0]];
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string vertices;
    getline(cin, vertices);

    string edges_count_temp;
    getline(cin, edges_count_temp);

    int edges_count = stoi(ltrim(rtrim(edges_count_temp)));

    vector<string> edges(edges_count);

    for (int i = 0; i < edges_count; i++) {
        string edges_item;
        getline(cin, edges_item);

        edges[i] = edges_item;
    }

    Vertex *origin = deserialize(vertices, edges);
    
    string result = bfs(origin);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
