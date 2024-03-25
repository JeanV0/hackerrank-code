#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class TagHrml {
private:
    string TagName;
    map<string, string> atribute;
    TagHrml *node = nullptr;
    TagHrml *nodeBefore = nullptr;
public:
    TagHrml(string input) {
        istringstream iss(input);
        vector<string> tokens;
        string token;

        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }

        TagName = tokens.front().substr(1, TagName.size() - 2);

        for (auto it = tokens.begin() + 1; it != tokens.end(); it++) {
            auto keyAtribute = *it;
            it += 2;

            size_t pos1 = it->find('"');
            size_t pos2 = it->find('"', pos1 + 1);
            if (pos1 != string::npos && pos2 != string::npos && pos2 > pos1 + 1) {
                auto value = it->substr(pos1 + 1, pos2 - pos1 - 1);
                atribute[keyAtribute] = value;
            }
        }
    };

    ~TagHrml() {
        delete node;
    }

    string getAtribute(string key) {
        auto atributeFind = atribute.find(key);
        if (atributeFind != atribute.end()) {
            return atributeFind->second;
        }
        return "Not Found!";
    }

    TagHrml* getNode() {
        return node;
    }

    void setNode(TagHrml *tag) {
        this->node = tag;
    }

    TagHrml* getNodeBefore() {
        return nodeBefore;
    }

    void setNodeBefore(TagHrml *tag) {
        this->nodeBefore = tag;
    }

    string getTagName() {
        return TagName;
    }
};


class StructureHrml {
    private:
        map<string,TagHrml*> tags;
    public:
        void addTagHrml(TagHrml *tag){
            this->tags[tag->getTagName()] = tag;
        };
        TagHrml* getTagHrml(string key){
            auto tagFind = this->tags.find(key);
            if(tagFind != this->tags.end()){
                return tagFind->second;
            };
            return nullptr;
        }

        bool isTagEmpty(){
            return tags.size() == 0; 
        }
        
        ~StructureHrml(){
            for(auto it = tags.begin(); it != tags.end(); it++){
                delete it->second;
            }
        }
};

enum TypeSearchHrml{
    Tag,
    Atribute
};

class SearchHrml{
    private:
        TypeSearchHrml type;
        string key;
    public:
        SearchHrml(TypeSearchHrml type, string key){
            this->type = type;
            this->key = key;
        };

        TypeSearchHrml getType(){
            return type;
        }

        string getKey(){
            return key;
        }
};

class QuerySearchHrml {
    private:
        vector<SearchHrml*> decision;
    public:
        QuerySearchHrml(string query){
            while(true) {
                if(size_t search = query.find(".") != string::npos){
                    string key = query.substr(0, search+3);
                    query = query.substr(search+4);
                    decision.push_back(new SearchHrml(TypeSearchHrml::Tag, key));
                } else if (size_t search = query.find("~") != string::npos){
                    string key = query.substr(0, search+3);
                    query = query.substr(search+4);
                    decision.push_back(new SearchHrml(TypeSearchHrml::Tag,key));
                } else {
                    decision.push_back(new SearchHrml(TypeSearchHrml::Atribute,query));
                    break;
                }
            };
            reverse(decision.begin(),decision.end());
        }

        bool ifGetAtribute(){
            if(decision.back()->getType() == TypeSearchHrml::Atribute) {
                return true;
            };
            return false;
        }

        bool ifGetTagHrml(){
            if(decision.back()->getType() == TypeSearchHrml::Tag) {
                return true;
            };
            return false;
        }

        string searchKeyName(){

            auto keyName = decision.back();
            decision.pop_back();
            return keyName->getKey();
        }

        ~QuerySearchHrml(){
            for(auto it = decision.begin(); it != decision.end(); it++){
                delete *it;
            }
        }
};

int main() {
    int size_structure, searchs;

    cin >> size_structure >> searchs;

    cin.ignore();
    
    StructureHrml hrml;

    TagHrml *before = nullptr;
    TagHrml *actual = nullptr;

    map<int, string> order;

    for(auto i=0; i < size_structure; i++){
        string input;
        getline(std::cin,input);
        if(hrml.isTagEmpty()){
            actual = new TagHrml(input);
            hrml.addTagHrml(actual);
        } else if(input.find("/") != std::string::npos) {
            continue;
        } else if (actual->getNode() == nullptr) {
            auto node = new TagHrml(input);
            actual->setNode(node);
            before = actual;
            actual = node;
            actual->setNodeBefore(before);
        }
    };


    for(auto i=0; i <= searchs-1; i++){
        string input;
        getline(std::cin,input);
        auto query = new QuerySearchHrml(input);
        TagHrml* actualTag = nullptr;
        string keyName;
        while(true) {
            if(query->ifGetTagHrml()){
                if (actualTag == nullptr) {
                    actualTag = hrml.getTagHrml(query->searchKeyName());
                } else {
                    query->searchKeyName();
                    actualTag = actualTag->getNode();
                }
            } else if (query->ifGetAtribute()){
                cout << actualTag->getAtribute(query->searchKeyName()) << endl;
                break;
            }
        }
    };

    return 0;
}