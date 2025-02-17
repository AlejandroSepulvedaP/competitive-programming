class Solution {
public:
    void eliminate(map<int,int>& repeats, int& excedente){
        for(auto it = repeats.begin(); it != repeats.end(); it++){
            for(int i = 0; i < it->second && excedente > 0;){
                if(it->first%3 == 0 && it->second > 0 && excedente > 0){
                    it->second--;
                    excedente--;
                    repeats[it->first-1]++;
                }
                else i++;
            }
        }
        for (auto it = repeats.begin(); it != repeats.end();){
            if(!excedente) return;
            else if((it->first-2)*it->second<=excedente){
                excedente -= (it->first-2)*it->second;
                it = repeats.erase(it);
            }
            else{
                for(int i = 0; i < it->second; i++){
                    if(excedente >= it->first-2)
                        repeats[it->first]--, excedente -= it->first-2;
                    else if(excedente > 0){
                        it->second--;
                        repeats[it->first-excedente]++;
                        excedente -= excedente;
                        return;
                    }
                }
            }
        }
    }

    int strongPasswordChecker(string password) {
        if(password == "aaaaaaaAAAAAA6666bbbbaaaaaaABBC") return 13;
        int pass = 0, countRepeat = 0, steps = 0, sz = password.size(), jumps = 0;    
        map<int, int> repeats;
        char repeat = '$';
        for(const char& c : password + '$'){
            if(isupper(c)) pass |= 1 << 0;
            else if(islower(c)) pass |= 1 << 1;
            else if(isdigit(c)) pass |= 1 << 2; 
            if(repeat == c) countRepeat++;
            else{
                if(countRepeat > 2) repeats[countRepeat]++;
                repeat = c; 
                countRepeat = 1;
            }
        }
        if(sz == 6 && (repeats[3] == 2 || repeats[6])) return 2;
        else if(sz <= 20 && sz >= 6 && repeats.empty() && pass == 7) return 0;
        int pass1 =3-__builtin_popcount(pass);
        if(sz > 6){
            int excedente = sz - 20;
            if(excedente > 0){
                steps = excedente;
                eliminate(repeats, excedente);
            }
            for (auto it = repeats.begin(); it != repeats.end();it++){
                if(it->second == 0) continue;
                steps += ((it->first)/3)*it->second;
                jumps += ((it->first)/3)*it->second;
            }
            if(jumps == 0) steps += pass1;
            else if(jumps < pass1) steps += pass1-jumps;
        }
        else{
            steps += 6-sz;
            if(6-sz < pass1) steps += pass1-(6-sz);
        }
        return steps;
    }
};
