/*
Solution based on Group Theory.
note rho * tau * rho^-1 = add_even when b =odd
 */
class Solution {
public:
    static int n;
    static inline void add_odd(char* s, int a){
        for(int i=1; i<n; i+=2){
            const int d=(s[i]-'0'+a);
            s[i]='0'+(d>=10?d-10:d);
        }
    }
    static inline void min_add_odd(char* s, int a, int A) {
        const int d=s[1]-'0';
        if (d<a) return ;// identity map
        add_odd(s, (10-d/a)*a%10);
    }

    static inline void add_even(char* s, int a){
        for(int i=0; i<n; i+=2){
            const int d=(s[i]-'0'+a);
            s[i]='0'+(d>=10?d-10:d);
        }
    }
    static inline void min_add_even(char* s, int a, int A) {
        const int d=s[0]-'0';
        if (d<a) return ;// identity map
        add_even(s, (10-d/a)*a%10);
    }
    static inline void rotate(char* s, int b){
    //    return s.substr(n-b)+s.substr(0, n-b);
        reverse(s, s+n);
        reverse(s, s+b);
        reverse(s+b, s+n);
        /*
        string t(n, '0');
        for (int i=0; i<n; i++){
            const int j=i-b;
            t[i]=s[j<0?j+n:j];
        }
        return t;
        */
    }
    static string findLexSmallestString(string s_, int a, int b) {
        n=s_.size();
        char s[101]; 
        strcpy(s, s_.c_str());
        s[n]='\0';
        const int a0=gcd(a, 10), b0=gcd(n, b);
        const int A=10/a0, B=n/b0;
        char ans[101];
        memset(ans, '9', n);
        ans[n]='\0';
        if (b0%2==0){
            for(int j=0; j<B; j++){
                rotate(s, b0);
                min_add_odd(s, a0, A);
                if (strcmp(s, ans)<0)
                    strcpy(ans, s);
            }
            return string(ans);
        }
        else{
            for(int j=0; j<B; j++){
                rotate(s, b0);
                min_add_odd(s, a0, A);
            //    if (strcmp(s, ans)<0)
            //        strcpy(ans, s);
                min_add_even(s, a0, A);
                if (strcmp(s, ans)<0)
                    strcpy(ans, s);
            }
        }
        return string(ans);
    }
};

int Solution::n;