#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string, int> topic_id;
vector<pair<int, int> > books;

int main() {
    auto books = read_books();


