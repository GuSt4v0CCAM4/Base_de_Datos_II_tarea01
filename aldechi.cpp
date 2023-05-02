#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;
struct Query {
    string description;
    string command;
};
size_t position;

void readQuery(string filename, vector<Query>& queries){
    ifstream infile(filename);
    if (infile.good()) {
        string line;
        while (getline(infile, line)){
            int delimiterIndex = line.find(",");
            if (delimiterIndex != string::npos) {
                string description = line.substr(0, delimiterIndex);
                string command = line.substr(delimiterIndex + 1);

                queries.push_back({description,command});
            }
        }
        infile.close();
    }
}

void lectura (string name_){
    ifstream archivo;
    string texto;

    archivo.open("prueba.txt",ios::out);
}
void escribir(string name_){
    ofstream archivo;

    archivo.open("prueba.txt",ios::out);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    archivo<<"Hola que tal?";
    archivo<<"asd";

    archivo.close();
}


void creartabla(string query_2){
    string aux;
    aux =query_2.substr(1,query_2.find(" ")-1);

    ofstream archivo;
    archivo.open("esquema.txt",ios::app);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    int pos, conts=0;
    pos = query_2.find("TABLE ")+6;
    query_2.erase(0,pos);
    //query_2.erase(std::remove_if(query_2.begin(), query_2.end(), [](unsigned char c) { return std::isspace(c); }), query_2.end());
    cout<<query_2<<"  "<<query_2.find(")")<<endl;
    for(int i=0;query_2.size()>i;i++){
        if(query_2[i]=='(' || query_2[i]==',' || query_2[i]==' '){
            query_2[i] = '#';
        }
    }
    aux = query_2.substr(0,query_2.find(")"));

    archivo<<aux<<endl;

    archivo.close();
}

void insertarDatos(string query_2){
    string aux;
    ofstream archivo;
    query_2.erase(remove_if(query_2.begin(), query_2.end(), [](unsigned char c) { return std::isspace(c); }), query_2.end());
    query_2.erase(0,query_2.find("INTO")+4);
    aux = query_2.substr(0,query_2.find("VALUES"))+".txt";
    archivo.open(aux,ios::app);
    query_2.erase(0,query_2.find("(")+1);
    for(int i=0;query_2.size()>i;i++){
        if(query_2[i]==','){
            query_2[i] = '#';
        }
    }
    aux = query_2.substr(0,query_2.find(")"));
    archivo<<aux<<endl;
    archivo.close();
}

void imprimir_table(vector<string> tablee)
{
    cout<<"|";
    for(int i=0;i<tablee.size();i++){
        ifstream archivo(tablee[0]+".txt");
        for(int j=0;)
    }
}
void imprimir(string query){
    vector<string> tables;
    string aux;
    int table_aux,contador;
    query.erase(remove_if(query.begin(), query.end(), [](unsigned char c) { return std::isspace(c); }), query.end());
    table_aux = query.find("FROM")+4;
    aux=query.substr(table_aux,query.find("WHERE")-table_aux);
    table_aux=0;
    for(int i=0;i<=aux.size();i++){
        if(aux[i]==',' || i==aux.size()){
            tables.push_back(aux.substr(table_aux,i-table_aux));
            i++;
            table_aux = i;
        }
    }

    if(query.find("*")<query.find("FROM")){
        imprimir_table(tables);
    }
}
int main() {

    string name, query,query_2, query_3,query_4, aux;
    int opc;
    vector<string> line;
    //query = "&SELECT office FROM oracle Students, Depts WHERE Students.name = 'Smith' AND Students.dept = Depts.name#";
    query_2 = "&CREATE TABLE students(name string, id int, Dept string)#";
    query_3 = "&INSERT INTO students VALUES('Smith',123,'CS')#";
    query_4 = "&CREATE TABLE departamento(name string, id int, capacidad int)#";
    position = query_2.find("&");
    query_2.erase(0,position);
    creartabla(query_4);
    position = query_3.find("&");
    query_3.erase(0,position);
    //insertarDatos(query_3);
    /*while(query_2[0]!=')'){
        if(query_2.find("(")<query_2.find("#")){
            aux = query_2.substr(0,query_2.find("("));
            archivo<<aux<<"#";
            query_2.erase(0,query_2.find("(")+1);
        }else{
            aux = query_2.substr(0,query_2.find(", "));
            aux[aux.find(' ')] = '#';
            archivo<<aux;
            query_2.erase(0,query_2.find(", ")+2);
        }
    }*/

    /*aux = query_2.substr(pos,query_2.find("(")-pos);
    archivo<<aux<<"#";
    pos = query_2.find("(")+1;
    while(query_2.find("#")>pos){
        if(
    }*/
    /*
    fstream archivo("esquema.txt");
    while(getline(archivo,name)){
        line.push_back(name);
    }

    for(int i=0;i<line.size();i++){
        cout<<line[i]<<endl;
    }
    int cont=0;
    cout<<query.size()<<endl;
    //escribir(name);
    cout<<query.find("&")<<endl;
    */
    vector<Query> queries;
    readQuery("queries.txt", queries);

    cout << "Queries disponibles:" << endl;
    for (int i = 0; i < queries.size(); i++){
        cout << i +1 << ". " << queries[i].description << endl;
    }


    system("pause");
    return 0;
}