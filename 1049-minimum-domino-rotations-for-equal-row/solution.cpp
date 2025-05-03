// one pass, 0 ms
class Solution {
public:
    static int minDominoRotations(const vector<int>& a, const vector<int>& b) {
            const int n = a.size();
                    const int x = a[0];
                            const int y = b[0];
                                    int xa = 1;
                                            int xb = 0;
                                                    int ya = 0;
                                                            int yb = 1;
                                                                    bool xf = true;
                                                                            bool yf = true;
                                                                                    for (int i = 1; i < n; ++i) {
                                                                                                const int ai = a[i];
                                                                                                            const int bi = b[i];
                                                                                                                        if (xf) {
                                                                                                                                        xf = (x == ai || x == bi);
                                                                                                                                                        xa += (x == ai);
                                                                                                                                                                        xb += (x == bi);
                                                                                                                                                                                    }
                                                                                                                                                                                                if (yf) {
                                                                                                                                                                                                                yf = (y == ai || y == bi);
                                                                                                                                                                                                                                ya += (y == ai);
                                                                                                                                                                                                                                                yb += (y == bi);
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                        if (!(xf || yf)) return -1;
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                        if (xf && yf) return min(min(n - xa, n - xb), min(n - ya, n - yb));
                                                                                                                                                                                                                                                                                                return xf ? min(n - xa, n - xb) : min(n - ya, n - yb);
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                    };
