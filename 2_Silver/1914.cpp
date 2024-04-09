#include <iostream>
#include <cmath>
using namespace std;

std::string arr[101] = {
    "0",
    "1",
    "3",
    "7",
    "15",
    "31",
    "63",
    "127",
    "255",
    "511",
    "1023",
    "2047",
    "4095",
    "8191",
    "16383",
    "32767",
    "65535",
    "131071",
    "262143",
    "524287",
    "1048575",
    "2097151",
    "4194303",
    "8388607",
    "16777215",
    "33554431",
    "67108863",
    "134217727",
    "268435455",
    "536870911",
    "1073741823",
    "2147483647",
    "4294967295",
    "8589934591",
    "17179869183",
    "34359738367",
    "68719476735",
    "137438953471",
    "274877906943",
    "549755813887",
    "1099511627775",
    "2199023255551",
    "4398046511103",
    "8796093022207",
    "17592186044415",
    "35184372088831",
    "70368744177663",
    "140737488355327",
    "281474976710655",
    "562949953421311",
    "1125899906842623",
    "2251799813685247",
    "4503599627370495",
    "9007199254740991",
    "18014398509481983",
    "36028797018963967",
    "72057594037927935",
    "144115188075855871",
    "288230376151711743",
    "576460752303423487",
    "1152921504606846975",
    "2305843009213693951",
    "4611686018427387903",
    "9223372036854775807",
    "18446744073709551615",
    "36893488147419103231",
    "73786976294838206463",
    "147573952589676412927",
    "295147905179352825855",
    "590295810358705651711",
    "1180591620717411303423",
    "2361183241434822606847",
    "4722366482869645213695",
    "9444732965739290427391",
    "18889465931478580854783",
    "37778931862957161709567",
    "75557863725914323419135",
    "151115727451828646838271",
    "302231454903657293676543",
    "604462909807314587353087",
    "1208925819614629174706175",
    "2417851639229258349412351",
    "4835703278458516698824703",
    "9671406556917033397649407",
    "19342813113834066795298815",
    "38685626227668133590597631",
    "77371252455336267181195263",
    "154742504910672534362390527",
    "309485009821345068724781055",
    "618970019642690137449562111",
    "1237940039285380274899124223",
    "2475880078570760549798248447",
    "4951760157141521099596496895",
    "9903520314283042199192993791",
    "19807040628566084398385987583",
    "39614081257132168796771975167",
    "79228162514264337593543950335",
    "158456325028528675187087900671",
    "316912650057057350374175801343",
    "633825300114114700748351602687",
    "1267650600228229401496703205375"
};

void hanoi(int n, int src, int dest, int mid) {
  if (n == 1) {
    cout << src << " " << dest << "\n";
    return;
  }
  hanoi(n - 1, src, mid, dest);
  cout << src << " " << dest << "\n";
  hanoi(n - 1, mid, dest, src);
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cout << arr[n] << "\n";
  if (n <= 20)
    hanoi(n, 1, 3, 2);
}