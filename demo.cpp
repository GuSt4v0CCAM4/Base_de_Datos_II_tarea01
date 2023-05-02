#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Query {
    string description;
    string command;
};

void readQueriesFromFile(string filename, vector<Query>& queries) {
    ifstream infile(filename);
    if (infile.good()) {
        string line;
        while (getline(infile, line)) {
            int delimiterIndex = line.find(",");
            if (delimiterIndex != string::npos) {
                string description = line.substr(0, delimiterIndex);
                string command = line.substr(delimiterIndex + 1);
                queries.push_back({description, command});
            }
        }
        infile.close();
    }
}
// funciones para llamarlo desde la query
void findRecordById(int id) {
    cout << "Buscando registro por ID" <<id<< "..." << endl;
    ifstream infile("registros.txt");

    string line;
    bool found = false;
    while (getline(infile, line)){
        string id_str = line.substr(0, line.find(","));
        int current_id = stoi(id_str);

        if (current_id == id) {
            cout <<"Registro encontrado:" <<endl;
            cout <<
        }
    }

}