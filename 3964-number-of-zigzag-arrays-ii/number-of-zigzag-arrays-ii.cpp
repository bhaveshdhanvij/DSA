class Solution {
public:
    static constexpr long long MOD = 1000000007LL;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix matPow(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++) {
                T[y][m + x] = 1;
            }

            for (int y = 0; y < x; y++) {
                T[m + y][x] = 1;
            }
        }

        Matrix P = matPow(T, n - 1);

        vector<long long> startUp(sz, 0), startDown(sz, 0);

        for (int i = 0; i < m; i++) {
            startUp[m + i] = 1;
            startDown[i] = 1;
        }

        auto apply = [&](const vector<long long>& v) {
            vector<long long> res(sz, 0);

            for (int i = 0; i < sz; i++) {
                long long cur = 0;
                for (int j = 0; j < sz; j++) {
                    cur = (cur + P[i][j] * v[j]) % MOD;
                }
                res[i] = cur;
            }
            return res;
        };

        vector<long long> a = apply(startUp);
        vector<long long> b = apply(startDown);

        long long ans = 0;
        for (long long x : a) ans = (ans + x) % MOD;
        for (long long x : b) ans = (ans + x) % MOD;

        return (int)ans;
    }
};