#include <iostream>
#include <algorithm>
using namespace std;
int f[2002][2002];
int H, W;
int dp1[2002][2002];
int opt[2002][2002];
/*  
    定义opt[i][j]：
        【高桥分数-青木分数】的【高桥想让这个值最大，而青木想让这个值最小】的最优化结果
        当i+j为偶数时（此时下一步为高桥走）：移动到(i,j)时，获得的最大的【高桥分数-青木分数】
        当i+j为奇数时（此时下一步为青木走）：移动到(i,j)时，获得的最小的【高桥分数-青木分数】
    转移：  
        可以从两个方向转移：(i+1, j)或(i, j+1)
        当i+j为偶数时（此时下一步为高桥走）：opt[i][j] = max(opt[i+1][j] + f[i+1][j], opt[i][j+1] + f[i][j+1])
        当i+j为奇数时（此时下一步为青木走）：opt[i][j] = min(opt[i+1][j] - f[i+1][j], opt[i][j+1] - f[i][j+1])
    答案：
        从大往小转移，如果opt[1][1]为正，高桥必胜；为0平局；否则青木必胜
*/
const int INF = 0x7fffffff;
int main()
{
	cin >> H >> W;
	for(int i = 1; i <= H; ++i)
		for(int j = 1; j <= W; ++j) {
			char t;
			cin >> t;
			f[i][j] = (t == '+' ? 1 : -1);
		}
	for(int i = H; i >= 1; --i)
		for(int j = W; j >= 1; --j) {
			if(i == H && j == W) {
				opt[i][j] = 0;
				continue;
			}
			if((i + j) & 1) {  //奇数
				opt[i][j] = INF;
				if(i + 1 <= H)
					opt[i][j] = min(opt[i][j], opt[i + 1][j] - f[i + 1][j]);
				if(j + 1 <= W)
					opt[i][j] = min(opt[i][j], opt[i][j + 1] - f[i][j + 1]);
			}
			else {  //偶数
				opt[i][j] = -INF;
				if(i + 1 <= H)
					opt[i][j] = max(opt[i][j], opt[i + 1][j] + f[i + 1][j]);
				if(j + 1 <= W)
					opt[i][j] = max(opt[i][j], opt[i][j + 1] + f[i][j + 1]);
			}
		}
	if(opt[1][1] > 0)
		cout << "Takahashi" << endl;
	else if(opt[1][1] == 0)
		cout << "Draw" << endl;
	else
		cout << "Aoki" << endl;
	return 0;
}