#include <bits/stdc++.h>
#include <unordered_set>
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
* Complete the 'find_all_paths' function below.
*
* The function is expected to return a STRING_ARRAY.
* The function accepts following parameters:
*  1. Vertex origin
*  2. char destination
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

vector<string> find_all_paths(Vertex *origin, char dest) {
    std::shared_ptr<std::unordered_set<Vertex*>> visited = make_shared<std::unordered_set<Vertex*>>();
    
    std::shared_ptr<vector<string>> result = make_shared<vector<string>>();

    
    std::function<void(Vertex*, string)> recursion;
    recursion = [&](Vertex* current, string path )   {
        
        if(visited->find(current) != visited->end())
        {
            return;
        }
        
        if(current->id == dest)
        {
            result->push_back(path);
            return;
        }
        
        visited->insert(current);
        
        std::vector<Vertex*> edges = current->edges;
        for (Vertex* edge : edges)
        {
            path.push_back(edge->id);
            recursion(edge, path);
            path.pop_back();
        }
        
        visited->erase(current);
        
    };
    
    std::string argPath;
    argPath.push_back(origin->id);
    recursion(origin, argPath);
    
    std::sort(result->begin(), result->end());
    
    return *result;

}
// DO NOT EDIT9
// generate graph from int and array of arrays
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

    string destination;
    getline(cin, destination);
    char dest;
    if(destination.length() > 0) dest = destination[0];

    vector<string> result = find_all_paths(origin, dest);
    
    sort(result.begin(), result.end()); 

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
