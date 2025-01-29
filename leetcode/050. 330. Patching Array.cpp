class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long current = 1;
        int i = 0, patches = 0;
        while (current <= n) {
            if (i < nums.size() && nums[i] <= current) {
                current += nums[i++];
            } else {
                current += current;
                patches++;
            }
        }
        return patches;
    }
};

/*
la táctica de este algoritmo es garantizar que tenemos todos los posibles números antes de current, y si aparece un número que no podemos generar, entonces lo tenemos en cuenta y current dobla su rango, pues si current era capaz de generar los números de [1,current-1], pero no podemos generar current, entonces current será un nuevo número y ahora current puede generar números del [1,2*current-1]

Supongamos nums = [1, 3] y n = 10:
Inicialmente, current = 1, rango cubierto: [1, 0].
Usamos nums[0] = 1. Ahora current = 2, rango cubierto: [1, 1].
No podemos cubrir current = 2. Añadimos un parche 2. Ahora current = 4, rango cubierto: [1, 3].
Usamos nums[1] = 3. Ahora current = 7, rango cubierto: [1, 6].
No podemos cubrir current = 7. Añadimos un parche 7. Ahora current = 14, rango cubierto: [1, 13].

*/
