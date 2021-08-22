#include<cstdio>

bool SG[5001][5001];

int main(){
    for(int i = 0; i <= 5000; ++i)
        for(int j = 0; j <= 5000; ++j)
            if(SG[i][j] == 0){
                for(int k = 1; i + k <= 5000; ++k)
                    for(int s = 0; j + s*k <= 5000; ++s)
                        SG[i+k][j+s*k] = 1;
                for(int k = 1; j + k <= 5000; ++k)
                    for(int s = 0; i + s*k <= 5000; ++s)
                        SG[i+s*k][j+k] = 1;
            }
            
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i){
        int n, m;
        scanf("%d%d", &n, &m);
        if(SG[n][m] > 0) printf("Alice\n");
        else printf("Bob\n");
    }            
    return 0;
}