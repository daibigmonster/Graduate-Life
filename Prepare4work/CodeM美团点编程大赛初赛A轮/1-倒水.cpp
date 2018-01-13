// 有一个大水缸，里面水的温度为T单位，体积为C升。另有n杯水（假设每个杯子的容量是无限的），每杯水的温度为t[i]单位，体积为c[i]升。
// 现在要把大水缸的水倒入n杯水中，使得n杯水的温度相同，请问这可能吗？并求出可行的最高温度，保留4位小数。
// 注意：一杯温度为t1单位、体积为c1升的水与另一杯温度为t2单位、体积为c2升的水混合后，温度变为(t1*c1+t2*c2)/(c1+c2)，体积变为c1+c2。
// 输入描述:

// 第一行一个整数n, 1 ≤ n ≤ 10^5
// 第二行两个整数T，C,其中0 ≤ T ≤ 10^4, 0 ≤ C ≤ 10^9
// 接下来n行每行两个整数t[i]，c[i]
// 0 ≤ t[i], c[i] ≤ 10^4



// 输出描述:

// 如果非法，输出“Impossible”（不带引号)否则第一行输出“Possible"（不带引号），第二行输出一个保留4位小数的实数表示答案。

// 样例解释：往第二杯水中倒0.5升水
// 往第三杯水中到1升水
// 三杯水的温度都变成了20


// 输入例子1:

// 3
// 10 2
// 20 1
// 25 1
// 30 1


// 输出例子1:

// Possible
// 20.0000

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
double changeT(vector<int> t,vector<int> c,int maxt,int mint,int T,int C,double tempT,double allc){
    double sumc = 0.0,c2 = 0.0;
    // cout << tempT << " " << T << " " << C << endl;
    if(T <= mint || T >= maxt){
        int curt = (T <= mint) ? mint : maxt;
        for(int i = 0;i < t.size();i++){
            if(t[i] == curt) continue;
            c2 = float((t[i] - curt) * c[i]) / float(curt - T);
            sumc += c2;
            if(sumc > C) return -1.0;
            c2 = 0.0;
        }
        if(curt == mint) return double(curt);
        else {
            // cout << "温度和体积 " << tempT << " " << allc << endl;
            return double(tempT / allc);
        }
    }
    else 
        return -1.0;
}
int main(){
    int N,mint = 10001,maxt = 0;
    long T,C;
    while(cin >> N){
        vector<int> t(N,0);
        vector<int> c(N,0);
        cin >> T >> C;
        double tempT = double(T * C);
        double allc = double(C);
        for(int i = 0;i < N;i++){
            cin >> t[i] >> c[i];
            allc += double(c[i]);
            tempT += double(t[i] * c[i]);
            if(t[i] < mint) mint = t[i];
            if(t[i] > maxt) maxt = t[i]; 
        } 
        double ans = changeT(t,c,maxt,mint,T,C,tempT,allc);
        // cout << T << " " << C << endl;
        // for(int i= 0; i < N;i++)cout << t[i] << " " << c[i] << endl;
        if(ans == -1.0) cout << "Impossible" << endl;
        else {
            cout << "Possible" << endl;
            printf("%.4f\n",ans);
        }
    }
}