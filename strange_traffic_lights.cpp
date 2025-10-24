#include <bits/stdc++.h>
using namespace std;

string color_at(long long t){
    const int total=103;
    long long offset=(t-45)%total;
    if(offset<0) offset+=total;
    if(offset<3) return "Kuning";
    if(offset<83) return "Merah";
    return "Hijau";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    while(cin>>t){
        cout<<"Detik "<<t<<" -> "<<color_at(t)<<'\n';
    }
}
