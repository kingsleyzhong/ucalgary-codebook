/**
 * Author: Kingsley Zhong
 * Date: 
 * License: 
 * Source: 
 * Description: My own library, just use multiple hashes if you think test data is evil. See NT/Primes for prime list.
 * Time: O(N)
 * Status: probably works
**/
class StringHash{
private:
    const ll P=9973, M;
    vector<ll> pow, hash;
public:
    StringHash(const string& s, const ll &M): pow(s.size()+1), hash(s.size()+1), M(M){
        const int n = s.size();
        pow[0] = 1;
        hash[0] = 0;
        for(int i=1;i<=n;++i){
            pow[i] = (pow[i-1] * P) % M; 
            hash[i] = ((hash[i-1] * P) % M + s[i-1]) % M;
        }
    }

    // S and F are 0 indexed and inclusive
    ll get_hash(int s, int f){
        ll ret = hash[f+1] - (hash[s] * pow[f-s+1]);
        return (ret % M + M) % M;
    }
};