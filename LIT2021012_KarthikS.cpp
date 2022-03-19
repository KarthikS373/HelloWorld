#include<bits/stdc++.h>
using namespace std;

typedef struct TARGET{
    string goal1;
    string goal2;
} TARGET;


string combinations(string str, string res){
    string s = str;
    sort(s.begin(), s.end()); 
    do {
        if(s == res)
            return s;
    } while (next_permutation(s.begin(), s.end()));
    return s;
}

int main(){
    system("cls");
    TARGET target;
    target.goal1 = "Hello";
    target.goal2 = "World";

    char lalphabet[26];
    char ualphabet[26];
    for (char i = 'a'; i <= 'z'; i++) {
        lalphabet[i - 'a'] = i;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        ualphabet[i - 'A'] = i;
    }

    queue<char> g1, g2;
    string str1, str2;
    srand(time(0));

    while(true){
        bool flag = false;
        int RandIndex = rand() % 26;
        char c1 = lalphabet[RandIndex];
        char c2 = ualphabet[RandIndex];
        for(int  i = 0; i < 5; ++i){
            if(c1 == target.goal1[i]){
                g1.emplace(c1);
                target.goal1.erase(i, 1);
            }
            if(c2 == target.goal1[i]){
                g1.emplace(c2);
                target.goal1.erase(i, 1);
            }
            if(c1 == target.goal2[i]){
                g2.emplace(c1);
                target.goal2.erase(i, 1);
            }
            if(c2 == target.goal2[i]){
                g2.emplace(c2);
                target.goal2.erase(i, 1);
            }
            if(g1.size() == 5 && g2.size() == 5){
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }

    for(int i = 0; i < 5; ++i){
        str1 += g1.front();
        g1.pop(); 
        str2 += g2.front();
        g2.pop(); 
    }
    string goals[2] = {"Hello", "World"};

    string res1 = combinations(str1, goals[0]);
    string res2 = combinations(str2, goals[1]);

    while(res1 != goals[0]){
        int cap = rand() % 6;
        res1 = res1[cap] ^ (1<<cap);
    }
    while(res2 != goals[1]){
        int cap = rand() % 6;
        res2 = res2[cap] ^ (1<<cap);
    }

    cout<< res1 << " " << res2 << endl;
    
    return 0;
}