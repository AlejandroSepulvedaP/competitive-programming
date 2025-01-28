class Solution {
public:
    long long comb(long long a, long long b, long long mod) {
        if (b > a) return 0;
        long long numer = 1, denom = 1;
        for (long long i = 0; i < b; ++i) {
            numer = numer * (a - i) % mod;
            denom = denom * (i + 1) % mod;
        }

        // Fermat's Little Theorem
        long long denom_inv = 1;
        long long exp = mod - 2;
        while (exp) {   
            if (exp % 2) denom_inv = denom_inv * denom % mod;
            denom = denom * denom % mod;
            exp /= 2;
        }
        return numer * denom_inv % mod;
    }

    int distanceSum(int m, int n, int k) {
        int mod = 1e9 + 7;
        long long base = comb(m * n - 2, k - 2, mod);
        long long res = 0;
        for (int d = 1; d < n; ++d) {
            res = (res + 1LL * d * (n - d) % mod * m % mod * m % mod) % mod;
        }
        for (int d = 1; d < m; ++d) {
            res = (res + 1LL * d * (m - d) % mod * n % mod * n % mod) % mod;
        }
        return res * base % mod;
    }
};

/*
without mod
class Solution {
public:
    // Función para calcular combinaciones C(a, b) = a! / (b! * (a - b)!)
    long long comb(long long a, long long b) {
        if (b > a) return 0;
        long long numer = 1, denom = 1;
        for (long long i = 0; i < b; ++i) {
            numer = numer * (a - i);
            denom = denom * (i + 1);
        }
        return numer / denom; // Sin uso de módulo
    }
    int distanceSum(int m, int n, int k) {
        long long base = comb(m * n - 2, k - 2); // Número de combinaciones válidas
        long long res = 0;
        // Contribuciones de las filas (distancia entre columnas)
        for (int d = 1; d < n; ++d) {
            res += d * (n - d) * m * m; // Para cada distancia d entre columnas
        }
        // Contribuciones de las columnas (distancia entre filas)
        for (int d = 1; d < m; ++d) {
            res += d * (m - d) * n * n; // Para cada distancia d entre filas
        }
        cout << res << ", " << base << endl;
        return res * base; // Multiplicar por el número de combinaciones válidas
    }
};

CASE: 1,4,3
PAIRS:
D = 1 = 1,2 - 2,3 - 2,4
D = 2 = 1,3 - 2,4
D = 3 = 1,4
TOTAL: 10

now 
{1,2,3},{1,2,4},{1,3,4},{2,3,4}
each pair appears two times, so 10 * 2

if 1,5,3
then {1,2,3},{1,2,4},{1,2,5}
each pair ppears three times, so 20 * 3

if 1,5,4
then {1,2,3,4},{1,2,3,5},{1,2,4,5}
each pair ppears three times, so 20 * 3
*/
