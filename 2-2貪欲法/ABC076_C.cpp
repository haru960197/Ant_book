#include <bits/stdc++.h>
using namespace std;
string S, T, min_S;
string make_S(int insert_pos){
    string ret_S = S;
    for(int i=0; i<T.size();i++) ret_S.at(insert_pos+i) = T.at(i);
    for(int i=0; i<S.size(); i++) if(ret_S.at(i) == '?') ret_S.at(i) = 'a';
    return ret_S;
}
int main(){
    cin >> S >> T;
    int insert_pos[S.size()], insert_num = 0;;
    for(int i=0; i<S.size(); i++){
        for(int j=0; j<T.size(); j++){
            if(i+j >= S.size()) break;
            char c = S.at(i+j);
            if(c != T.at(j) && c!='?') break;
            if(j == T.size()-1){
                insert_pos[insert_num] = i;
                insert_num++;
            }
        }
    }
    if(insert_num == 0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    for(int i=0; i<insert_num; i++){
        if(i==0) min_S = make_S(insert_pos[i]);
        else{
            string pre_min_S = make_S(insert_pos[i]);
            if(min_S > pre_min_S) min_S = pre_min_S;
        }
    }
    cout << min_S << endl;
}