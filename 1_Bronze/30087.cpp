#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<string, string> map;
    map.insert({"Algorithm", "204"});
    map.insert({"DataAnalysis", "207"});
    map.insert({"ArtificialIntelligence", "302"});
    map.insert({"CyberSecurity", "B101"});
    map.insert({"Network", "303"});
    map.insert({"Startup", "501"});
    map.insert({"TestStrategy", "105"});

    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << map[str] << "\n";
    }
}