#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print_u (unordered_map<T, T> u)
{
    for (const auto &n : u)
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}

vector<int> find_two_sum (vector<int> v, int n)
{
        vector<int> res(2, 0);
        unordered_map<int, int> u;


        if (n % 2 == 0) {
            int d = n / 2;
            int t = 0;
            for (int i = 0; i < v.size(); i++) {
                if (d == v[i])
                    res[t++] = i;
                if (t == 2)
                    return res;
            }
            res[0] = 0;
            res[1] = 0;
        }

        int k = 1;
        for (int &a : v) {
                u[a] = k++;
        }
        for (auto const &b : u) {
            int t = n - b.first;
            if (u.count(t) == 1) {
                res[0] = b.second - 1;
                res[1] = u[t] - 1;
                return res;
            }
        }
        return res;
}

int main ()
{
    // unordered_map initial
    unordered_map<string, string> u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
    
    vector<int> v = {1931729,5896941,-56160,-5999108,-713650,3135403,870300,-2938196,-726482,-152831,-5552046,-6857780,2493109,-2409591,7453630,7848984,-806578,4976647,-9199319,-7660981,4168359,5466164,8577624,-7465790,-7808993,-7176396,-3622579,4996177,9623530,-1371773,-5633028,5188756,7971646,-2603602,7490338,3174208,-1825054,6892503,-8201151,-1072749,-2746872,-718104,-1804706,5504856,-9104958,-2181797,3151933,-6116343,1436458,-659793,-9256591,-3487143,3396195,-6211129,-2789647,-9336842,-122743,-3843085,8515885,-8551842,-8668581,-5040156,-9626107,-5645393,-5484621,-6417906,4483313,-4197219,-5762688,-6645419,1077632,7237401,4819732,5220382,8657346,651862,7406097,6668849,5067699,4563307,-4358391,-3996666,-4298897,-9870277,-628517,1842975,-4970541,-8815324,-4174656,-9332000,4647373,9461387,-3504914,2614670,-1315721,6099266,-8562834,-4488116,9742133,307556,791291,-2611787,7656675,9932436,-1905766,5142745,7210001,-4678645,550797,8462302,6815722,-2985059,-1236401,-6093644,-6617192,-9438320,8400183,8936598,537};

    v = find_two_sum(v, 1931729+5896941);
    print_u(u);    
    return 0;
}